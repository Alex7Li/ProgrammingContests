# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 1, t+1){
        int n;
        int tr=0, r=0, c=0;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        rep(i, 0, n){
            rep(j, 0, n){
                cin >> mat[i][j];
                if(i==j){
                    tr+=mat[i][j];
                }
            }
        }
        rep(i,0, n){
            set<int> sr;
            set<int> sc;
            rep(j, 0, n){
                sr.insert(mat[i][j]);
                sc.insert(mat[j][i]);
            }
            if(sr.size()!=n){
                r++;
            }
            if(sc.size()!=n){
                c++;
            }
        }

        cout << "Case #" << tt << ": " << tr << " " << r << " " << c << "\n";
    }
    return 0;
}