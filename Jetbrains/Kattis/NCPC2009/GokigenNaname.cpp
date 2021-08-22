# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int toState(vector<int> &v) {
    int state = 0;
    for (int i = 0; i < v.size(); ++i) {
        int x = v[i];
        if (v[i] == -1) {
            x = 3;
        }
        state += (1 << (i * 2)) * x;
    }
    return state;
}

vector<int> getConfig(int i, int n) {
    vector<int> conf(n + 1, 0);
    int ind = 0;
    while (i != 0) {
        conf[ind] = i % 4;
        if (conf[ind] == 3) {
            conf[ind] = -1;
        }
        i /= 4;
    }
    return conf;
}

bool solve(vector<vi> &g, int row, vi &require, deque<string> &ans, vi &cc) {
    // how to ensure no loops?
    int n = g.size() - 1;
    vector<int> unusedCC;
    for (int i = 0; i < 2 * (n + 1); ++i) {
        if (count(cc.begin(), cc.end(), i) == 0) {
            unusedCC.push_back(i);
        }
    }
    // TODO Why is cc[-1] -1 seomtimes?
    for (int i = 0; i < (1 << n); ++i) {
        vi ccCopy = cc;
        vi nextCC(n + 1, -1);
        string s;
        bool ok = true;
        vector<int> next_required = g[row + 1];
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                s.push_back('\\');
                if (require[j + 1] == 2 || require[j] == 0 || next_required[j + 1] == 0) { // pruning
                    i += (1 << j) - 1;
                    ok = false;
                    break;
                }
            } else {
                s.push_back('/');
                if (require[j + 1] == 0 || require[j] == 2 || next_required[j] == 0) { // pruning
                    i += (1 << j) - 1;
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) {
            continue;
        }
        // check if we match up in a valid way
        for (int j = 0; j <= n; ++j) {
            if (require[j] != -1) {
                int fromLeft = j != 0 && s[j - 1] == '/';
                int fromRight = j != n && s[j] == '\\';
                if (require[j] != fromLeft + fromRight) {
                    ok = false;
                    break;
                }
            }
            if (next_required[j] != -1) {
                int toLeft = j != 0 && s[j - 1] == '\\';
                int toRight = j != n && s[j] == '/';
                next_required[j] -= toLeft + toRight;
                if (next_required[j] < 0 || 2 < next_required[j]) {
                    ok = false;
                    break;
                }
            }
        }
        if(!ok){
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                nextCC[j + 1] = ccCopy[j];
            } else {
                if (nextCC[j] == -1) {
                    nextCC[j] = ccCopy[j + 1];
                } else if (nextCC[j] == ccCopy[j + 1]) {
                    ok = false;
                } else if (j > 0 && s[j - 1] == '\\') {
                    if (ccCopy[j - 1] == ccCopy[j + 1]) {
                        ok = false;
                    }
                    nextCC[j] = ccCopy[j - 1];
                    // we are connecting two components,
                    // update everything in the component of ccCopy[j+1]
                    // to be in the component of ccCopy[j-1]
                    int old = ccCopy[j + 1];
                    int newV = ccCopy[j - 1];
                    for (int k = 0; k < ccCopy.size(); ++k) {
                        if (ccCopy[k] == old) {
                            ccCopy[k] = newV;
                        }
                        if (nextCC[k] == old) {
                            nextCC[k] = newV;
                        }
                    }
                } else {
                    nextCC[j] = ccCopy[j + 1];
                }
            }
        }
        // assign other ccs
        int unusedInd = 0;
        for (int j = 0; j < nextCC.size(); ++j) {
            if (nextCC[j] == -1) {
                nextCC[j] = unusedCC[unusedInd++];
            }
        }
        if (ok) {
            ans.push_back(s);
            if (row == n - 1) {
                int valid = count_if(next_required.begin(), next_required.end(), [](int x) {
                    return x == 0 || x == -1;
                });
                if (valid == n + 1) {
                    return true;
                }
            } else {
                if (solve(g, row + 1, next_required, ans, nextCC)) {
                    return true;
                }
            }
            ans.pop_back();
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vi> g(n + 1, vi(n + 1, -1));
    for (int i = 0; i < n + 1; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n + 1; ++j) {
            if (s[j] != '.') {
                g[i][j] = (int) (s[j] - '0');
            }
        }
    }
    deque<string> ans;
    vector<int> cc(n + 1);
    iota(cc.begin(), cc.end(), 0);
    bool b = solve(g, 0, g[0], ans, cc);
    if (!b) {
        cout << "NOT POSSIBLE";
        assert(false);
    }
    for (auto &an : ans) {
        cout << an << endl;
    }
    return 0;
}