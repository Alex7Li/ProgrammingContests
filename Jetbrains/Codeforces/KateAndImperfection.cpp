# include <bits/stdc++.h>
// http://codeforces.com/contest/1333/problem/F
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
    int n;
    cin >> n;
    int maxF = n/2;
    int subsetSize = n;
    vector<bool> notInSet(n+1);
    vector<int> ans(n+1);
    while(subsetSize > 1){
        int st = n/maxF;
        for(int i = st; i > 1; i--){
            if(!notInSet[i*maxF]){
                notInSet[i*maxF] = true;
                ans[subsetSize] = maxF;
                subsetSize--;
            }else {
                continue;
            }
        }
        maxF--;
    }
    for(int i = 2; i <= n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}