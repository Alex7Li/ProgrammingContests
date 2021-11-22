# include <bits/stdc++.h>
//http://codeforces.com/contest/1340/problem/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define INF 1'000'000;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int dist(int lit, int letter) {
    int count = 0;
    for (int j = 0; j < 7; j++) {
        int isSet = (lit & (1 << j));
        int willSet = (letter & (1 << j));
        if (isSet && !willSet) {
            return INF;
        } else if (willSet && !isSet) {
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int k;
    cin >> n >> k;
    vector<int> strings = {0b1110111, 0b010010, 0b1011101, 0b1011011, 0b111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
    vector<int> lit;
    rep(i, 0, n) {
        string s;
        cin >> s;
        lit.push_back(stoi(s, 0, 2));
    }
    vector<vector<bool>> cost(n+1, vector<bool>(k+10, false));
    cost[n][0] = true;
    for (int i = n - 1; i >= 0; i--) {
        trav(x, strings) {
            int c = dist(lit[i], x);
            // TODO Why doenst cost[i].size() work?
            for (int j = 0; j < k+10 - c; j++) {
                if (cost[i + 1][j] == true) {
                    cost[i][j + c] = true;
                }
            }
        }
    }
    if (!cost[0][k]) {
        cout << -1;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = strings.size() - 1; j >= 0; j--) {
                int d = dist(lit[i], strings[j]);
                if (k-d>= 0 && cost[i+1][k - d]) {
                    cout << j;
                    k -= d;
                    break;
                }
            }
        }
    }
    cout << endl;
    return 0;
}