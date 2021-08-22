# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <bits/stdc++.h>
#include <ctime>

using namespace std;

# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<char>> Grid;

const int CAND_SIZE = 8;
const int MAX_DEPTH = 4;
const double REAL_WEIGHT = 10.0;

int fieldWidth; // The width of the playing field
int fieldHeight; // The height of the playing field
int costSoil; // Cost to plant your flower on a soil tile
int costGrass; // Cost to plant your flower on a grass tile
int costRocks; // Cost to plant your flower on a rocks tile
int costFlower; // Cost to plant your flower on a tile with opponents flower

struct State {
    int tulipGold;
    int daisyGold;
    int turnsLeft;
    bool tulipTurn;

    void nextTurn() {
        turnsLeft -= 1;
        tulipTurn = !tulipTurn;
    }

    bool operator==(const State &o) {
        return this->tulipTurn == o.tulipTurn && this->daisyGold == o.daisyGold &&
               this->tulipGold == o.tulipGold && this->turnsLeft == o.turnsLeft;
    }
};

struct undoAdd {
    State old;
    shared_ptr<vector<int>> row;
    shared_ptr<vector<int>> col;
    shared_ptr<vector<char>> prevTile;
};

int removeCost(char tileType) {
    switch (tileType) {
        case 'S':
            return costSoil;
        case 'G':
            return costGrass;
        case 'R':
            return costRocks;
        case 'T':
            return costFlower;
        case 'D':
            return costFlower;
    }
    assert(false);
}


int points(int flowersRemoved) {
    int first = 2;
    int second = 3;
    int score = 7;
    for (int i = 4; i < flowersRemoved; i++) {
        int temp = first;
        first = second;
        second = temp + second;
        score += score;
    }
    return score;
}

int getRemovedFlowers(Grid &g, int row, int col, char flowerType, shared_ptr<vi> rows, shared_ptr<vi> cols) {
    char prev = g[row][col];
    g[row][col] = flowerType;
    char c = flowerType;
    // Check column for tuple
    for (int i = max(row - 3, 0); i < min(row + 4, fieldHeight) - 3; i++) {
        if (c == g[i][col] && c == g[i + 1][col] && c == g[i + 2][col] && c == g[i + 3][col]) {
            while (i < fieldHeight && c == g[i][col]) {
                if (i != row) {
                    rows->push_back(i);
                    cols->push_back(col);
                }
                i++;
            }
            break;
        }
    }
    // Check row
    for (int i = max(col - 3, 0); i < min(col + 4, fieldWidth) - 3; i++) {
        if (c == g[row][i] && c == g[row][i + 1] && c == g[row][i + 2] && c == g[row][i + 3]) {
            while (i < fieldWidth && c == g[row][i]) {
                if (i != col) {
                    rows->push_back(row);
                    cols->push_back(i);
                }
                i++;
            }
            break;
        }
    }

    // Check top left to bottom right diagonal
    for (int t = -3; t <= 0; t++) {
        int i = row + t;
        int j = col + t;
        if (i < 0 || j < 0 || i + 4 > fieldHeight || j + 4 > fieldHeight) {
            continue;
        }
        if (c == g[i][j] && c == g[i + 1][j + 1] && c == g[i + 2][j + 2] && c == g[i + 3][j + 3]) {
            while (i < fieldHeight && j < fieldWidth && c == g[i][j]) {
                if (i != row) {
                    rows->push_back(i);
                    cols->push_back(j);
                }
                i++;
                j++;
            }
            break;
        }
    }

    // Check bottom left to top right diagonal
    for (int t = -3; t <= 0; t++) {
        int i = row - t;
        int j = col + t;
        if (i - 3 < 0 || j < 0 || i >= fieldHeight || j + 4 > fieldHeight) {
            continue;
        }
        if (c == g[i][j] && c == g[i - 1][j + 1] && c == g[i - 2][j + 2] && c == g[i - 3][j + 3]) {
            while (i >= 0 && j < fieldHeight && c == g[i][j]) {
                if (i != row) {
                    rows->push_back(i);
                    cols->push_back(j);
                }
                i--;
                j++;
            }
            break;
        }
    }
    g[row][col] = prev;
    return rows->size();
}

int pointPotential(const Grid &g, int row, int col, char flowerType) {
    char c = flowerType;
    // Check column for tuple
    vector<int> distScore(4, 0);
    for (int i = max(row - 3, 0); i < min(row + 4, fieldHeight); i++) {
        if (c == g[i][col]) {
            distScore[0]++;
        }
    }
    // Check row
    for (int i = max(col - 3, 0); i < min(col + 4, fieldWidth); i++) {
        if (c == g[row][i]) {
            distScore[1]++;
        }
    }
    // Check top left to bottom right diagonal
    for (int t = -3; t <= 3; t++) {
        int i = row + t;
        int j = col + t;
        if (i < 0 || j < 0 || i + 4 > fieldHeight || j + 4 > fieldHeight) {
            continue;
        }
        if (c == g[i][j]) {
            distScore[2]++;
        }
    }
    // Check bottom left to top right diagonal
    for (int t = -3; t <= 3; t++) {
        int i = row - t;
        int j = col + t;
        if (i - 3 < 0 || j < 0 || i >= fieldHeight || j + 4 > fieldHeight) {
            continue;
        }
        if (c == g[i][j]) {
            distScore[3]++;
        }
    }
    int total = 0;
    int baseScore = 0;
    for (int i = 0; i < distScore.size(); i++) {
        total += distScore[i];
        baseScore += 1 << distScore[i];
    }
    if (c == g[row][col]) {
        total -= 3;
    }
    return points(total) / 8 + baseScore;
}

undoAdd addFlower(Grid &g, State &s, pii pos) {
    int row = pos.first;
    int col = pos.second;
    char removedTile = g[row][col];
    assert(s.turnsLeft > 0);
    shared_ptr<vector<int>> rows = make_shared<vi>(1, row);
    shared_ptr<vector<int>> cols = make_shared<vi>(1, col);
    shared_ptr<vector<char>> prevTiles = make_shared<vector<char>>(1, removedTile);
    State oldS = s;
    char flowerType = s.tulipTurn ? 'T' : 'D';
    int nChanged = getRemovedFlowers(g, row, col, flowerType, rows, cols);
    if (s.tulipTurn) {
        s.tulipGold -= removeCost(removedTile);
    } else {
        s.daisyGold -= removeCost(removedTile);
    }
    g[row][col] = flowerType;

    if (nChanged > 1) {
        if (s.tulipTurn) {
            s.tulipGold += points(nChanged);
        } else {
            s.daisyGold += points(nChanged);
        }
        // Update, all flowers replaced by grass
        for (int i = 0; i < (*rows).size(); i++) {
            prevTiles->push_back(g[(*rows)[i]][(*cols)[i]]);
            g[(*rows)[i]][(*cols)[i]] = 'G';
        }
    }
    s.nextTurn();
    /* TODO: This still doesn't allocate right past the first element... */
    return undoAdd{oldS, rows, cols, prevTiles};
}

State undoAddFlower(Grid &g, undoAdd undo) {
    for (int i = 0; i < undo.row->size(); i++) {
        int r = (*undo.row)[i];
        int c = (*undo.col)[i];
        g[r][c] = (*undo.prevTile)[i];
    }
    return undo.old;
}

template<typename T>
vector<int>& sortInds(const vector<T> &v) {
    vector<int> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    stable_sort(idx.begin(), idx.end(),
                [&v](size_t i1, size_t i2) { return v[i1] > v[i2]; });
    return idx;
}

vector<pii>& candidatePositions(Grid &g, const State &s) {
    vector<double> candPriorities(fieldHeight * fieldWidth, 0);
    for (int i = 0; i < fieldHeight; i++) {
        for (int j = 0; j < fieldWidth; j++) {
            int flat = i * fieldWidth + j;
            if (g[i][j] == 'T') {
                candPriorities[flat] += pointPotential(g, i, j, 'D')
                                        + pointPotential(g, i, j, 'T');
            }
        }
    }
    vi sortedInds = sortInds(candPriorities);
    vector<pii> v(CAND_SIZE);
    for (int i = 0; i < CAND_SIZE && i < sortedInds.size(); i++) {
        int ind = sortedInds[i];
        v[i] = pii(ind / fieldWidth, ind % fieldWidth);
    }
    return v;
}

double minimax(Grid &g, State &s, vector<pii> &cands, pair<double, double> &tulipAv, int depth, double bestYet) {
    if (s.tulipGold < 0) {
        return -1e50;
    } else if (s.daisyGold < 0) {
        return 1e50;
    } else if (depth == MAX_DEPTH) {
        double score = (s.tulipGold - s.daisyGold) * REAL_WEIGHT *
                       (6.0 - log(s.turnsLeft)) * (10.0 / (s.tulipGold + 1.0));
        int maxPotential = 0;
        for (int i = max(0.0, tulipAv.first - 3.0); i < min(fieldHeight + 0.0, tulipAv.first + 3); i++) {
            for (int j = max(0.0, tulipAv.first - 3.0); j < min(fieldWidth + 0.0, tulipAv.second + 3); j++) {
                if (g[i][j] != 'T') {
                    int pot = pointPotential(g, i, j, 'T');
                    maxPotential = max(maxPotential, pot);
                }
            }
        }
        return score + maxPotential;
    }
    double bestScore = depth % 2 == 0 ? -INFINITY : INFINITY;
    bool ok = true;
    for (pii cand : cands) {
        undoAdd undo = addFlower(g, s, cand);
        if (depth % 2 == 0) { // maximize the score - we only care if we end up with a number less than bestYet
            bestScore = max(bestScore, minimax(g, s, cands, tulipAv, depth + 1, bestScore));
            if (bestScore > bestYet) {
                ok = false;
            }
        } else { // minimize the score - we only care if we end up with number more than bestYet
            bestScore = min(bestScore, minimax(g, s, cands, tulipAv, depth + 1, bestScore));
            if (bestScore < bestYet) {
                ok = false;
            }
        }
        s = undoAddFlower(g, undo);
        if (!ok) {
            break;
        }
    }
    return bestScore;
}

pii getBestMove(Grid &g, State &s) {
    pair<double, double> tulipAv;
    int n = 1;
    for (int i = 0; i < fieldHeight; i++) {
        for (int j = 0; j < fieldWidth; j++) {
            if (g[i][j] == 'T') {
                n++;
                tulipAv.first += i;
                tulipAv.second += j;
            }
        }
    }
    tulipAv.first /= n;
    tulipAv.second /= n;
    vector<pii> cands = candidatePositions(g, s);
    double bestScore = -INFINITY;
    pii bestMove;
    for (pii cand : cands) {
        shared_ptr<vi> a = make_shared<vi>(0), b = make_shared<vi>(0);
        // Don't plant on a daisy unless we have an advantage, or we get lots of points from it.
        if (g[cand.first][cand.second] != 'D' || s.tulipGold - s.daisyGold > costFlower ||
            points(getRemovedFlowers(g, cand.first, cand.second, 'T', a, b)) > costFlower) {
            if (g[cand.first][cand.second] != 'T') {
                undoAdd undo = addFlower(g, s, cand);
                double score = minimax(g, s, cands, tulipAv, 1, bestScore);
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = cand;
                }
                s = undoAddFlower(g, undo);
            }
        }
    }
    return bestMove;
}

int main() {
    cin >> fieldWidth >> fieldHeight;
    cin >> costSoil >> costGrass >> costRocks >> costFlower;
    string yourFlowers; // type of flowers you plant (tulips or daisies)
    string opponentsFlowers; // type of flowers opponent plants (tulips or daisies)
    cin >> yourFlowers >> opponentsFlowers;
    Grid g(fieldHeight, vector<char>(fieldWidth));
    // game loop
    while (1) {
        State state;
        cin >> state.turnsLeft;
        state.turnsLeft = state.turnsLeft * 2 + 2;
        int yourGold; // Your current gold
        int opponentGold; // Opponents current gold
        cin >> yourGold >> opponentGold;
        state.tulipGold = yourGold;
        state.daisyGold = opponentGold;
        state.tulipTurn = true;
        for (int i = 0; i < fieldHeight; i++) {
            string gridLine; // playing field encoded by S - soil, G - grass, R - rocks, T - tulip, D - daisy.
            cin >> gridLine;
            for (int j = 0; j < fieldWidth; ++j) {
                g[i][j] = gridLine[j];
                // I am always tulips.
                if (opponentsFlowers == "tulips") {
                    if (g[i][j] == 'D') {
                        g[i][j] = 'T';
                    } else if (g[i][j] == 'T') {
                        g[i][j] = 'D';
                    }
                }
            }
        }
        clock_t startT = clock();
        pii move = getBestMove(g, state);
        double turnTime = (0.0 + clock() - startT) / CLOCKS_PER_SEC;
        cout << move.first << " " << move.second << " Time: " << turnTime << endl;
    }
}

