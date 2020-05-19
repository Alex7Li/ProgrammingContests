# include <bits/stdc++.h>
//http://codeforces.com/contest/1332/problem/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    cin >> t;
    rep(times, 0, t){
        cin >> n;
        vector<bool> used(11, 0);
        vector<int> color(n, 0);
        rep(i, 0, n){
            int val;
            cin >> val;
            rep(j, 0, 11){
                if(val % primes[j] == 0){
                    used[j] = true;
                    color[i] = j;
                    break;
                }
            }
        }
        map<int, int> ind;
        int count = 0;
        rep(i, 0, 11){
            if(used[i]){
                count++;
            }
            ind[i] = count;
        }
        cout << count << "\n";
        rep(i, 0, n){
            cout << ind[color[i]] << " ";
        }
        cout << "\n";
    }
    return 0;
}