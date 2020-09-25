# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T>
T gcd(T a, T b) {
    if (a == 0) {
        return b;
    } else {
        return gcd(b % a, a);
    }
}

// floyd warshall - fast verision
// https://reader.elsevier.com/reader/sd/pii/S0893965911002928?token=8DA9440E723F0CD16B6B6BDD32F5F0438CFE67CB39156656F07F4B55F846BCEDE5F2FD5D1C4770DFB7121C1F96F04B5A
void allPairsShortestPath(vector<vector<int>> distMat) {
    int n = distMat.size();
    int INF = 1000;
    for (int k = 0; k < n; k++) {
        vector<int> finiteRow;
        vector<int> finiteCol;
        for (int i = 0; i < n; i++) {
            if (distMat[i][k] != INF) {
                finiteRow.push_back(i);
            }
            if (distMat[k][i] != INF) {
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
}

struct Loc {
    int x;
    int y;

    // Must be overloaded for unordered map
    bool operator==(const Loc &other) const {
        return x == other.x && y == other.y;
    }
};

struct Loc2 {
    int x;
    int y;

    // Overloaded for ordered map. If !(x<y), !(y<x), then
    //  x will be considered equal to y.
    bool operator<(const Loc2 &o) const {
        return x == o.x ? y < o.y : x < o.x;
    }
};

// to string
ostream &operator<<(ostream &stream, const Loc &l) {
    return stream << l.x << " " << l.y;
}

int main() {
    // Unordered map
    auto locHash = [](const Loc &l) { return l.x + (l.y << 4); };
    unordered_map<Loc, int, decltype(locHash)> locU(50, locHash);
    locU[{1, 2}] = 1;
    locU[{2, 3}] = 2;
    locU[Loc{1, 2}] = 2;
    for (auto a:locU) {
        cout << a.first << " " << a.second << "\n";
    }
    cout << "\n";
    // Lambda for unordered map. If !(x<y), !(y<x), then
    //  x will be considered equal to y.
    auto order = [](const Loc &l, const Loc &l2) {
        return l.x == l2.x ? l.y < l2.y : l.x < l2.x;
    };
    map<Loc, int, decltype(order)> locO(order);

    locO[{1, 2}] = 1;
    locO[{2, 3}] = 2;
    locO[{1, 10}] = 2;
    for (auto a:locO) {
        cout << a.first << " " << a.second << "\n";
    }
    cout << "\n";
    map<Loc2, int> locO2;
    locO2[{1, 2}] = 1;
    locO2[{2, 3}] = 2;
    locO2[Loc2{1, 2}] = 2;
    for (auto a:locO2) {
        cout << a.first.x << " " << a.first.y << " " << a.second << "\n";
    }
}

// return false if there is a loop. UNTESTED
bool topSort(int ind, vector<int> &seen, vector<vector<int>> &g) {
    seen[ind] = 1;
    trav(next, g[ind]) {
        if (seen[next] != 2) {
            if (seen[next] == 1) {
                return false; // detect loop
            }
            if (!topSort(next, seen, g)) {
                return false;
            }
        }
    }
    seen[ind] = 2;
    return true;
}

bool hasCycle(vector<vector<int>> &g) {
    vector<int> seen(g.size());
    for (int i = 0; i < g.size(); i++) {
        if (seen[i] == 0) {
            if (!topSort(i, seen, g)) {
                return true;
            }
        }
    }
    return false;
}

