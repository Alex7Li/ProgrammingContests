#include <bits/stdc++.h>

using namespace std;

//https://www.codingame.com/ide/challenge/spring-challenge-2020
//https://github.com/fala13/SpringChallenge2020/releases to run

# define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;


using namespace std;

int width, height;
int turn = 0;
clock_t turnStTime;
float moveValue = 0;

class Pac;

std::ostream &operator<<(std::ostream &o, const Pac &a);

struct Loc;

class Pellet;

class GridLocation;

int dist(const Loc &p1, const Loc &p2);

float heur(const shared_ptr<GridLocation> &dest, const vector<shared_ptr<Pac>> &allies,
           const vector<shared_ptr<Pac>> &foes, const Pac &you);


struct Loc {
    int x = -1;
    int y = -1;

    bool operator==(const Loc &other) const {
        return x == other.x && y == other.y;
    }
};

std::ostream &operator<<(std::ostream &o, const Loc &a) {
    o << "(" << a.x << "," << a.y << ")";
    return o;
}

struct MoveQueue {
    vector<string> moves;

    void printAll() {
        if (moves.size() > 0) {
            cout << moves[0];
        }
        for (int i = 1; i < moves.size(); i++) {
            cout << "|" << moves[i];
        }
        double duration = 1000 * (clock() - turnStTime) / ((double) CLOCKS_PER_SEC);
        cout << " " << duration << "ms" << endl;
        turnStTime = clock();
    }
};

class Pellet {
public:
    Pellet(int v, Loc loc) {
        val = v;
        this->loc = loc;
    }

    int val;
    Loc loc;

    bool operator==(const Pellet &other) const {
        return loc == other.loc;
    }
};

std::ostream &operator<<(std::ostream &o, const Pellet &a) {
    o << "val=" << a.val << " " << a.loc;
    return o;
}

auto locHash = [](const Loc &l) { return l.x + (l.y << 4); };
unordered_map<Loc, int, decltype(locHash)> locIndex(50, locHash);

string typeStr(int id) {
    switch (id) {
        case 0:
            return "SCISSORS";
        case 1:
            return "PAPER";
        case 2:
            return "ROCK";
        default:
            cerr << "BAD TYPE ID";
            return "BAD";
    }
}

int typeId(const string type) {
    switch (type[0]) {
        case 'S':
            return 0;
        case 'P':
            return 1;
        case 'R':
            return 2;
        default:
            cerr << "BAD TYPE";
            return 3;
    }
}

string beatingType(const string type) {
    return typeStr((typeId(type) + 2) % 3);
}

enum competitionResult {
    FIRSTLOSE = 0, FIRSTWIN = 1, TIE = 2
};

competitionResult beats(const string myType, const string foeType) {
    return static_cast<competitionResult>((typeId(myType) - typeId(foeType) + 2) % 3);
};

enum gridContent {
    PAC, PEL, EMPTY
};

class GridLocation {
public:
    vector<shared_ptr<GridLocation>> adj;
    int lastSeen;
    Loc loc;
    gridContent content;
    unique_ptr<Pellet> pellet;
    shared_ptr<Pac> pac;
    int claimed = 0;
    shared_ptr<GridLocation> deadEnd = nullptr;

    GridLocation(Loc location, gridContent cont, unique_ptr<Pellet> pel, int lastSeen) {
        loc = location;
        content = cont;
        pellet = move(pel);
        this->lastSeen = lastSeen;
    }

    GridLocation(Loc location, gridContent cont, shared_ptr<Pac> pac, int lastSeen) {
        loc = location;
        content = cont;
        this->pac = pac;
        this->lastSeen = lastSeen;
    }
};

std::ostream &operator<<(std::ostream &o, const GridLocation &a) {
    o << '[';
    switch (a.content) {
        case PAC:
            o << *a.pac;
            break;
        case PEL:
            o << *a.pellet;
            break;
        case EMPTY:
            o << a.loc;
            break;
        default:
            assert(false);
    }
    return o << " t: " << a.lastSeen << ']';
}

class Pac {
public:
    int id = -1;
    bool mine;
    int lastSeen = -100;
    Loc loc = Loc({100, 100});
    string type = "NONE";// ROCK, PAPER, SCISSORS
    int speedTurnsLeft = 0;
    int abilityCooldown = 0;

    Pac(int id, bool mine, int lastSeen) {
        this->id = id;
        this->mine = mine;
        this->lastSeen = lastSeen;
    }

    void move(const Loc &pos, MoveQueue &mq, double moveVal) {
        string move = "MOVE ";
        move.append(to_string(id)).append(" ").append(to_string(pos.x)).append(" ").append(to_string(pos.y));
        mq.moves.push_back(move);
        moveValue += moveVal;
    }

    void changeType(const string newType, MoveQueue &mq, double moveVal) {
        string move = "SWITCH ";
        move.append(to_string(id)).append(" ").append(newType);
        mq.moves.push_back(move);
        moveValue += moveVal;
    }

    void speed(MoveQueue &mq, double moveVal) {
        string move = "SPEED ";
        move.append(to_string(id));
        mq.moves.push_back(move);
        moveValue += moveVal;
    }

    bool operator==(const Pac &other) const {
        return id == other.id;
    }

    bool operator!=(const Pac &other) const {
        return id != other.id;
    }

    bool operator<(const Pac &other) const {
        return id < other.id;
    }

    /*
     * Given two pacs, we consider their turns of speed powerup to find out how many turns
     * it would take to catch up. Assume neither is cornered, and the runner uses speed.
     */
    int timeToOutrun(const Pac chaser, const Pac runner, int headStart, bool chaserSpeedsUp) {
        int speedBonus = chaser.speedTurnsLeft - runner.speedTurnsLeft;
        if (speedBonus >= headStart) {
            return headStart + runner.speedTurnsLeft;
        }
        if (chaserSpeedsUp &&
            chaser.speedTurnsLeft == 0) { // if chaser has speed turns and can't catch up it's hopeless
            if (headStart - speedBonus > 4) {
                return 100;
            }
            int timeToCatch = chaser.abilityCooldown + 1 - speedBonus + headStart;//wait for powerup, use it, catch up
            return timeToCatch;
        } else {
            return 100; // not anytime soon.
        }
    }

    /*
     * Two pacs race to a point. Who wins?
     */
    competitionResult raceResult(const Pac p1, const Pac p2, Loc point) {
        int d1 = dist(p1.loc, point);
        int d2 = dist(p2.loc, point);
        int t1 = d1 - min(d1 / 2, p1.speedTurnsLeft);
        int t2 = d2 - min(d2 / 2, p2.speedTurnsLeft);
        if (t1 == t2) {
            return TIE;
        } else if (t1 > t2) {
            return FIRSTLOSE;
        } else {
            return FIRSTWIN;
        }
    }

    /*
     * Returns if p1 can kill p2.
     */
    bool
    canKill(const Pac p1, const Pac p2, unordered_map<Loc, shared_ptr<GridLocation>, decltype(locHash)> &locations) {
        shared_ptr<GridLocation> getTo = locations[p2.loc]->deadEnd;
        if (beats(p1.type, p2.type) == FIRSTWIN) {
            int chaseTime = timeToOutrun(p1, p2, dist(p1.loc, p2.loc), true);
            if (chaseTime < p2.abilityCooldown) {
                return true;
            } else if (getTo) {
                if (raceResult(p1, p2, getTo->loc) != FIRSTLOSE) {
                    return true;
                }
            }
        } else {
            if (getTo) {
                if (raceResult(p1, p2, getTo->loc) == FIRSTWIN) {
                    int time = dist(p1.loc, getTo->loc);
                    if (abilityCooldown <= time) {
                        // how far can p2 run?
                        int maxD = 0;
                        for (auto a:locations) {
                            if (a.second->deadEnd == getTo) {//p2 can run here
                                maxD = max(maxD, dist(a.second->loc, getTo->loc));
                            }
                        }
                        int distToKill = maxD + dist(getTo->loc, p1.loc);
                        return distToKill + 1 < p2.abilityCooldown; // extra turn for transformation
                    }
                }
            }
        }
        return false;
    }

    float scorePoint(shared_ptr<GridLocation> &point, vector<shared_ptr<Pac>> &team, vector<shared_ptr<Pac>> &foes,
                     int maxDepth, int curDepth) {
        float locPoints = 0;
        if (point->claimed == turn) {
            locPoints -= 5.0 / (1 + curDepth); // a teammate plans to be here soon.
        } else if (point->content == PEL) {
            // add between .3 and 1 points for each pellet, and 10 for power pellets.
            locPoints += point->pellet->val;
            locPoints -= max((turn - point->lastSeen) / 130.0, .6);
            if (point->adj.size() == 1) {
                locPoints *= max(1.0, (curDepth) * (log(maxDepth + 3) - log(curDepth + 3)));
            }
        }
        float d = dist(point->loc, this->loc);
        for (shared_ptr<Pac> foe:foes) {
            if (foe->type != "DEAD" &&
                turn - foe->lastSeen <= 1 &&
                (beats(foe->type, type) == FIRSTWIN || foe->abilityCooldown < d)) { // there is a dangerous foe here
                if (raceResult(*this, *foe, point->loc) != FIRSTWIN) { // they could kill us if we go this way
                    locPoints -= 20;
                }
            }
        }
        if (point->content == PAC) {
            if (point->pac->mine) {
                locPoints -= 8;//don't run into your friend
            } else {
                locPoints -= 1;// generally not great
            }
        }
        if (point->deadEnd) {
            locPoints -= .02;
        }
        if (point->content == EMPTY) {
            for (shared_ptr<Pac> p: team) { // it is better to move away from everyone.
                locPoints -= .03 / (dist(point->loc, p->loc) + 1);
            }
            if (point->deadEnd) {
                locPoints -= .1;
            }
        }
        return locPoints;
    }

    vector<shared_ptr<GridLocation>>
    chooseMovePathDeep(unordered_map<Loc, shared_ptr<GridLocation>, decltype(locHash)> &locations,
                       vector<shared_ptr<Pac>> &team,
                       vector<shared_ptr<Pac>> &foes, float &score) {
        vector<shared_ptr<GridLocation>> bestPath;
        vector<shared_ptr<GridLocation>> curPath;
        unordered_set<Loc, typeof(locHash)> seen(128, locHash);
        curPath.push_back(locations[loc]);
        vector<int> prog(64, 0);
        float bestScore = -100000;
        float thisScore = 0;
        do {
            int p = prog[curPath.size() - 1];
            if (p == curPath.back()->adj.size()) {
                prog[curPath.size() - 1] = 0;
                thisScore -= scorePoint(curPath.back(), team, foes, 64, curPath.size()) / (curPath.size() + 8);
                curPath.pop_back();
            } else {
                prog[curPath.size() - 1]++;
                shared_ptr<GridLocation> nextLoc = (curPath.back()->adj)[p];
                if (seen.find(nextLoc->loc) == seen.end() &&
                    dist(loc, curPath.back()->loc) + 1 == dist(loc, nextLoc->loc)) {
                    if (nextLoc->deadEnd && curPath.back()->deadEnd) {
                        if (nextLoc->content == PEL) {
                            nextLoc->lastSeen = curPath.back()->lastSeen;
                        } else {
                            nextLoc->lastSeen = 0;//it's probably not there
                        }
                    }
                    curPath.push_back(nextLoc);
                    thisScore += scorePoint(curPath.back(), team, foes, 64, curPath.size()) / (curPath.size() + 8);
                    /*for (int i = 1; i < curPath.size(); i++) {
                        cerr << curPath[i]->loc << " ";
                    }
                    cerr << thisScore << "\n";*/
                    if (thisScore > bestScore) {
                        bestPath = curPath;
                        bestScore = thisScore;
                    }
                }
            }
        } while (curPath.size() > 0);
        score = bestScore;
        cerr << bestScore << " ";
        return bestPath;
    }

    vector<shared_ptr<GridLocation>>
    chooseMovePath(unordered_map<Loc, shared_ptr<GridLocation>, decltype(locHash)> &locations,
                   vector<shared_ptr<Pac>> &team,
                   vector<shared_ptr<Pac>> &foes, int depth, float &score) {
        int pelletsSeen = 0;
        vector<shared_ptr<GridLocation>> bestPath;
        vector<shared_ptr<GridLocation>> curPath;
        curPath.push_back(locations[loc]);
        vector<int> prog(depth, 0);
        float bestScore = -100000;
        double thisScore = 0;
        do {
            int p = prog[curPath.size() - 1];
            if (p == curPath.back()->adj.size()) {
                prog[curPath.size() - 1] = 0;
                thisScore -= scorePoint(curPath.back(), team, foes, depth, curPath.size()) / (curPath.size() + 3);
                curPath.pop_back();
            } else {
                prog[curPath.size() - 1]++;
                shared_ptr<GridLocation> nextLoc = (curPath.back()->adj)[p];
                if (dist(loc, curPath.back()->loc) + 1 == dist(loc, nextLoc->loc)) {
                    if (nextLoc->deadEnd && curPath.back()->deadEnd) {
                        if (nextLoc->content == PEL) {
                            nextLoc->lastSeen = curPath.back()->lastSeen;
                        } else {
                            nextLoc->lastSeen = 0;//it's probably not there
                        }
                    }
                    if (nextLoc->content == PEL) {
                        pelletsSeen++;
                    }
                    curPath.push_back(nextLoc);
                    thisScore += scorePoint(curPath.back(), team, foes, depth, curPath.size()) / (curPath.size() + 3);
                    /*for (int i = 0; i < curPath.size(); i++){
                        cout << *curPath[i] << " ";
                    }
                    cout << thisScore << "\n";*/
                    if (thisScore > bestScore) {
                        bestPath = curPath;
                        bestScore = thisScore;
                    }
                    if (curPath.size() == depth + 1) {
                        thisScore -=
                                scorePoint(curPath.back(), team, foes, depth, curPath.size()) / (curPath.size() + 3);
                        curPath.pop_back();
                    }
                }
            }
        } while (curPath.size() > 0);
        if (pelletsSeen < 2) {
            cerr << "deep";
            return chooseMovePathDeep(locations, team, foes, score);
        }
        score = bestScore;
        // cerr << bestScore << " ";
        return bestPath;
    }

    void tryKill(shared_ptr<Pac> &foe, MoveQueue moveQueue) {
        cerr << "trying to kill " << foe->id << " \n";
        foe->lastSeen = turn; // keep track of this guy
        if (abilityCooldown == 0) {
            if (type != beatingType(foe->type)) {
                changeType(beatingType(foe->type), moveQueue, 2);
            } else {
                speed(moveQueue, 2);
            }
        } else {
            move(foe->loc, moveQueue, 2);
        }
    }

    bool considerPowerup(MoveQueue &moveQueue, vector<shared_ptr<Pac>> &foes,
                         unordered_map<Loc, shared_ptr<GridLocation>, decltype(locHash)> &locations) {
        for (auto foe:foes) {
            if (foe->type != "DEAD") {
                if (turn - foe->lastSeen <= 1) {
                    if (canKill(*this, *foe, locations)) {
                        tryKill(foe, moveQueue);
                        return true;
                    }
                    if (foe->type == beatingType(this->type)) {// we should change types to not die
                        if (locations[this->loc]->deadEnd &&
                            raceResult(*this, *foe, locations[this->loc]->deadEnd->loc) != FIRSTWIN) {
                            changeType(beatingType(foe->type), moveQueue, 0);
                            return true;
                        }
                    }
                }
            }
        }
        if (loc.x % 2 == 1 && loc.y % 2 == 1) {
            speed(moveQueue, 0);
            return true;
        }
        return false;
    }

    void performAction(unordered_map<Loc, shared_ptr<GridLocation>, decltype(locHash)> &locations,
                       vector<shared_ptr<Pac>> &team, MoveQueue &moveQueue, vector<shared_ptr<Pac>> &foes, int depth) {
        if (abilityCooldown != 0 || !considerPowerup(moveQueue, foes, locations)) {
            for (auto foe:foes) {
                if (foe->type != "DEAD") {
                    if (turn - foe->lastSeen <= 1) {
                        if (canKill(*this, *foe, locations)) {
                            tryKill(foe, moveQueue);
                            return;
                        }
                    }
                }
            }
            float score = 0;
            vector<shared_ptr<GridLocation>> goalPath = chooseMovePath(locations, team, foes, depth, score);
            shared_ptr<GridLocation> goal;
            if (goalPath.size() <= 2) {
                goal = goalPath[goalPath.size() - 1];
            } else {
                goal = goalPath[2];// in case we have speed rn we go a step ahead.
            }
            for (int i = 1; i < goalPath.size(); i++) {
                goalPath[i]->claimed = turn;
            }
            move(goal->loc, moveQueue, score);
        }
    }
};


std::ostream &operator<<(std::ostream &o, const Pac &a) {
    o << "id:" << a.id << "@" << a.loc << " cd:" << a.abilityCooldown << " from " << a.lastSeen;
    return o;
}

vector<vector<int>> distMat;

/*
 * If a point on the grid is a dead end.
 */
void setDeadEnds(unordered_map<Loc, shared_ptr<GridLocation>, decltype(locHash)> &locations) {
    bool newFound = true;
    stack<shared_ptr<GridLocation>> toUpdate;
    while (newFound) {
        newFound = false;
        for (auto x : locations) {
            shared_ptr<GridLocation> gl = x.second;
            if (!gl->deadEnd) {
                int freeCount = 0;
                shared_ptr<GridLocation> nextSpot;
                for (shared_ptr<GridLocation> nxt : gl->adj) {
                    if (!nxt->deadEnd) {
                        nextSpot = nxt;
                        freeCount++;
                    }
                }
                if (freeCount == 1) {
                    newFound = true;
                    gl->deadEnd = nextSpot;
                    toUpdate.push(gl);
                }
            }
        }
    }
    while (!toUpdate.empty()) {
        shared_ptr<GridLocation> up = toUpdate.top();
        toUpdate.pop();
        for (shared_ptr<GridLocation> nxt : up->adj) {
            if (nxt->deadEnd != nullptr && nxt->deadEnd != up->deadEnd) {
                nxt->deadEnd = up->deadEnd;
            }
        }
    }
}

/*
 * Create a distance matrix for a grid, store in the global variable distMat.
 * Also link together the GridLocations
 */
void
setUpGrid(vector<vector<bool>> &grid, unordered_map<Loc, shared_ptr<GridLocation>, decltype(locHash)> locations) {
    int n = locations.size();
    distMat = vector<vector<int>>(n, vector<int>(n, 1000));
    for (int i = 0; i < n; i++) {
        distMat[i][i] = 0;
    }
    vector<pii> adj = {pii(1, 0), pii(0, 1), pii(grid.size() - 1, 0), pii(0, grid[0].size() - 1)};
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j]) {
                for (pii adjDir:adj) {
                    int x = (i + adjDir.first) % grid.size();
                    int y = (j + adjDir.second) % grid[0].size();
                    if (grid[x][y]) {
                        int ind1 = locIndex[Loc({i, j})], ind2 = locIndex[Loc({x, y})];
                        distMat[ind1][ind2] = 1;
                        locations[Loc({i, j})]->adj.push_back(locations[Loc({x, y})]);
                    }
                }
            }
        }
    }
    for (int k = 0; k < n; k++) {
        vector<int> finiteRow;
        vector<int> finiteCol;
        for (int i = 0; i < n; i++) {
            if (distMat[i][k] != 1000) {
                finiteRow.push_back(i);
            }
            if (distMat[k][i] != 1000) {
                finiteCol.push_back(i);
            }
        }
        trav(i, finiteRow) {
            trav(j, finiteCol) {
                if (distMat[i][k] + distMat[k][j] < distMat[i][j]) {
                    distMat[i][j] = distMat[i][k] + distMat[k][j];
                }
            }
        }
    }
    setDeadEnds(locations);
}


/*
 * Shortest path distance between 2 points
 */
int dist(const Loc &p1, const Loc &p2) {
    return distMat[locIndex[p1]][locIndex[p2]];
}


void
addInSight(unordered_set<Loc, decltype(locHash)> &locationsInSight, Loc &location, vector<vector<bool>> &grid) {
    locationsInSight.insert(location);
    for (int i = -2; i < 2; i++) {
        Loc stLoc = location;
        int dx = i % 2; // check each cardinal direction
        int dy = (i + 1) % 2;
        int newX = (stLoc.x + dx + width) % width;
        while (grid[newX % width][stLoc.y + dy]) {
            stLoc.x = newX;
            stLoc.y += dy;
            if (stLoc == location) {
                break;// there could be one wrapped horizontal line
            }
            locationsInSight.insert({stLoc.x, stLoc.y});
            newX = (stLoc.x + dx + width) % width;
        }
    }
}

int getInfo() {
    while (true) {
        string line;
        getline(cin, line);
        cerr << line << "\n";
    }
}

/**
 * Grab the pellets as fast as you can!
 **/
int main() {
    cin >> width >> height;
    cin.ignore();
    turnStTime = clock();
    unordered_map<Loc, shared_ptr<GridLocation>, decltype(locHash)> locations(128, locHash);
    vector<vector<bool>> grid(width, vector<bool>(height));
    for (int i = 0; i < height; i++) {
        string row;
        getline(cin, row); // one line of the grid: space " " is floor, pound "#" is wall
        for (int j = 0; j < width; j++) {
            grid[j][i] = row[j] == ' ';
            if (grid[j][i]) {
                Loc l = Loc({j, i});
                locIndex[l] = locations.size();
                locations[l] = make_shared<GridLocation>(l, PEL, make_unique<Pellet>(1, l), 0);
            }
        }
    }

    setUpGrid(grid, locations);
    // game loop
    vector<shared_ptr<Pac>> team;
    vector<shared_ptr<Pac>> foes;
    for (int i = 0; i < 5; i++) {
        team.push_back(make_shared<Pac>(-1, 1, -1));
        team[i]->type = "DEAD";
        foes.push_back(make_shared<Pac>(-1, 0, -1));
        foes[i]->type = "DEAD";
    }
    vector<shared_ptr<GridLocation>> powerPellets;
    while (1) {
        moveValue = 0;
        turn++;
        int myScore;
        int opponentScore;
        cin >> myScore >> opponentScore;
        cin.ignore();
        int visiblePacCount; // all your pacs and enemy pacs in sight
        cin >> visiblePacCount;
        cin.ignore();
        unordered_set<Loc, decltype(locHash)> locationsInSight(40, locHash);
        for (int i = 0; i < visiblePacCount; i++) {
            int id;
            bool mine;
            cin >> id >> mine;
            shared_ptr<Pac> p;
            if (mine) {
                if (turn == 1) {
                    p = make_shared<Pac>(id, mine, turn);
                } else {
                    p = move(team[id]);
                }
            } else {// enemy
                if (foes[id]->lastSeen == -1) {
                    p = make_shared<Pac>(id, mine, turn);
                } else {
                    p = move(foes[id]);
                }
            }
            cin >> p->loc.x >> p->loc.y >> p->type >> p->speedTurnsLeft
                >> p->abilityCooldown;
            cin.ignore();
            p->lastSeen = turn;
            shared_ptr<GridLocation> gl = locations[p->loc];
            if (p->type != "DEAD") {
                gl->content = PAC;
                gl->pac = p;
            }
            if (mine) {
                if (p->type != "DEAD") {
                    addInSight(locationsInSight, p->loc, grid);
                }
                team[id] = move(p);
            } else {
                foes[id] = move(p);
            }
        }
        for (shared_ptr<GridLocation> powPel : powerPellets) {
            powPel->content = EMPTY;
        }
        for (Loc loc : locationsInSight) {
            shared_ptr<GridLocation> gl = locations[loc];
            gl->lastSeen = turn;
            if (gl->content == PEL) {
                gl->content = EMPTY;
            } else if (gl->content == PAC) {
                if (gl->pac->lastSeen == turn && !(gl->pac->loc == loc)) {
                    gl->content = EMPTY;
                }
            }
        }
        for (Loc loc : locationsInSight) {
            shared_ptr<GridLocation> gl = locations[loc];
            if (gl->content == EMPTY) {
                int unknownAdj = gl->adj.size();
                for (shared_ptr<GridLocation> adj : gl->adj) {
                    if (adj->lastSeen == turn && adj->content == EMPTY) {
                        unknownAdj--;
                    }
                }
                if (unknownAdj <= 2) {
                    queue<shared_ptr<GridLocation>> Q;
                    Q.push(gl);
                    while(!Q.empty()) {
                        shared_ptr<GridLocation> next = Q.front();
                        Q.pop();
                        for (shared_ptr<GridLocation> adj : next->adj) {
                            if (adj->lastSeen != turn && adj->content == PEL) {
                                if(adj!=gl && adj->lastSeen!=-80){
                                    Q.push(adj);
                                }
                                adj->lastSeen = -80;
                            }
                        }
                    }
                }
            }
        }
        int visiblePelletCount; // all pellets in sight
        cin >> visiblePelletCount;
        cin.ignore();
        for (int i = 0; i < visiblePelletCount; i++) {
            Loc pelletLoc;
            cin >> pelletLoc.x >> pelletLoc.y;
            cin >> locations[pelletLoc]->pellet->val;
            cin.ignore();
            locations[pelletLoc]->content = PEL;
            if (turn == 1 && locations[pelletLoc]->pellet->val == 10) {
                powerPellets.push_back(locations[pelletLoc]);
            }
        }
        vector<int> turnOrder = vector<int>();
        for (int i = 0; i < team.size(); i++) {
            turnOrder.push_back(i);
        }
        MoveQueue bestMQ;
        double bestScore = -1000000;
        do {
            for (auto a :locations) {
                a.second->claimed = turn - 1;
            }
            int depth = rand() % 12 + 3;
            random_shuffle(turnOrder.begin(), turnOrder.end());
            MoveQueue thisQueue = MoveQueue();
            for (int i = 0; i < team.size(); i++) {
                int ind = turnOrder[i];
                if (team[ind]->type == "DEAD") {
                    continue;
                } else {
//                    cerr << "Move for Pac " << ind << "\n";
                    team[ind]->performAction(locations, team, thisQueue, foes, depth);
                }
            }
            moveValue /= log(depth) + 1;
            if (moveValue > bestScore) {
                bestScore = moveValue;
                bestMQ = thisQueue;
            }
            moveValue = 0;
        } while ((float) (clock() - turnStTime) / CLOCKS_PER_SEC < (turn == 1 ? .97 : .02));
        bestMQ.printAll();
    }
}

