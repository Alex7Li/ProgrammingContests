# include <bits/stdc++.h>
//http://codeforces.com/gym/102465
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi Z(string S) {
    vi z(sz(S));
    int l = -1, r = -1;
    rep(i, 1, sz(S)) {
        z[i] = i >= r ? 0 : min(r - i, z[i - l]);
        while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
            z[i]++;
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string str;
    cin >> n;
    cin >> str;
    vector<vector<int>> best(n+1, vector<int>(n+1, 0));
    for (int l = 1; l <= n; l++) {
        for (int st = 0; st <= n - l; st++) {
            int end = st + l;
            best[st][end] = l;
            vector<int> z = Z(str.substr(st, l));
            for(int subEnd = st+1; subEnd < end; subEnd++){
                if(l % (subEnd-st) == 0){
                    if(z[subEnd-st] == end - subEnd){
                        best[st][end] = min(best[st][end], best[st][subEnd]);
                    }
                }
                best[st][end] = min(best[st][end], best[st][subEnd] + best[subEnd][end]);
            }
        }
    }
    cout << best[0][n] << endl;
    return 0;
}