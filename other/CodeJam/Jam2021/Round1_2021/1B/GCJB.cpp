# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae4aa#problem
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

bool works(int M, vi u, int a, int b) {
    vi mask(M + 1, 0);
    mask[M] = 1;
    for (int i = M; i >= 0; --i) {
        mask[i] -= u[i];
        if (mask[i] < 0) {
            return false;
        }
        if (i - a >= 0) {
            /* This needs to be 100, I had it on 40 before. This got
             * Right on 99/100 test cases, wrong on
             *
            1
            20 1 20
            20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20
            -> gives answer 70, should be 68
             *
             */
            mask[i - a] = min(100LL, mask[i - a] + mask[i]);
        }
        if (i - b >= 0) {
            mask[i - b] = min(100LL, mask[i - b] + mask[i]);
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, a, b;
        cin >> n >> a >> b;
        vi u(501, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> u[i];
        }
        int ans = -1;
        for (int M = 500; M >= n; --M) {
            if (works(M, u, a, b)) {
                ans = M;
            }
        }
        cout << "Case #" << (tt + 1) << ": ";
        if(ans == -1){
            cout << "IMPOSSIBLE" << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}