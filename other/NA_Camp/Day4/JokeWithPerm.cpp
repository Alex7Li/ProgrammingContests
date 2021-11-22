# include <bits/stdc++.h>
using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
string s;
bool works(vector<vi> &locs, vi &inds) {
    set<int> singles;
    for (int i = 0; i < inds.size(); ++i) {
        singles.insert(locs[i][inds[i]]);
    }
    set<int> seen;
    for (int j = 0; j < s.size(); ++j) {
        if (singles.count(j) == 0) {
            if (singles.count(j + 1) == 0 && j + 1 < s.size()) {
                int v = (s[j] - '0') * 10 + (s[j + 1] - '0');
                seen.insert(v);
                j++;
            } else {
                return false;
            }
        }
    }
    for (int i = 10; i <= n; ++i) {
        if (seen.count(i) == 0) {
            return false;
        }
    }
    // print answer
    vector<int> vals;
    for (int j = 0; j < s.size(); ++j) {
        if (singles.count(j) == 0 && singles.count(j + 1) == 0 && j + 1 < s.size()) {
            int v = (s[j] - '0') * 10 + (s[j + 1] - '0');
            vals.push_back(v);
            j++;
        } else {
            vals.push_back(s[j] - '0');
        }
    }
    cout << vals[0];
    for (int i = 1; i < vals.size(); ++i) {
        cout << " " << vals[i];
    }
    cout << endl;
    return true;
}
bool try_all(vector<vi> &locs, vi &inds, int ind) {
    if (ind == locs.size()) {
        /*for (int i = 0; i < inds.size(); ++i) {
            cout << inds[i] << " ";
        }
        cout << endl;*/
        return works(locs, inds);
    }
    for (int i = 0; i < locs[ind].size(); ++i) {
        if (try_all(locs, inds, ind + 1)) {
            return true;
        }
        inds[ind]++;
    }
    inds[ind] = 0;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int l = s.size();
    if (l < 10) {
        n = l;
    } else {
        n = (l - 9) / 2 + 9;
    }
    vector<vi> locs(min(9, n));
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '0' && (i + 1 == s.size() || s[i + 1] != '0')) {
            locs[s[i] - '0' - 1].push_back(i);
        }
    }
    // cerr << s.size() << endl;
    if(n > 20){
        for (int j = 5; j <= 9; ++j) {
            set<int> posLocs;
            for (int & i : locs[j - 1]) {
                posLocs.insert(i);
            }
            for (int i = 1; i <= (n - j) / 10; ++i) {
                // if the pre digit happens only once it's not
                // possible for it to be a single.
                vector<int> preIsI;
                for (int k : locs[j - 1]) {
                    // cerr << k - 1 << endl;
                    if (k != 0 && s[k - 1] - '0' == i) {
                        preIsI.push_back(k);
                    }
                }
                if(preIsI.size() == 1){
                    for (int & k : preIsI) {
                        posLocs.erase(k);
                    }
                }
            }
            locs[j - 1].clear();
            trav(x, posLocs) {
                locs[j - 1].push_back(x);
            }
        }
    }
    vi inds(locs.size(), 0);
    try_all(locs, inds, 0);
    return 0;
}
