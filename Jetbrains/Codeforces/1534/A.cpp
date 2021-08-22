# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> g(n, vector<char>(m));
        bool p1 = true;
        bool p2 = true;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                g[i][j] = s[j];
                bool red = g[i][j] == 'R';
                bool white = g[i][j] == 'W';
                if (((i + j) % 2 && red) || ((i + j + 1) % 2 && white)) {
                    p1 = false;
                }
                if (((i + j) % 2 && white) || ((i + j + 1) % 2 && red)) {
                    p2 = false;
                }
            }
        }
        if(p1){
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if((i + j) % 2 == 1) {
                        cout << 'W';
                    }else{
                        cout << 'R';
                    }
                }
                cout << "\n";
            }
        }else if(p2){
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if((i + j) % 2 == 1) {
                        cout << 'R';
                    }else{
                        cout << 'W';
                    }
                }
                cout << "\n";
            }
        }else{
            cout << "NO" << "\n";
        }
    }
    cout << endl;
    return 0;
}