# include <bits/stdc++.h>
//http://codeforces.com/problemset/problem/1355/E
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, a, r, m;

ll solve(vector<int> h, int endH) {
    ll need = 0;
    ll excess = 0;
    for (int i = 0; i < h.size(); i++) {
        if (h[i] >= endH) {
            excess += h[i] - endH;
        } else {
            need += endH - h[i];
        }
    }
    ll cost = 0;
    ll s = min(need, excess);
    if (m < a + r) {
        cost += s * m;
        need -= s;
        excess -= s;
    }
    cost += need * a + excess * r;
    return cost;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> r >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int minV = 0;
    int maxV = 1'000'000'000;
    while (minV + 2 < maxV) {
        int mid = (minV + maxV)/2;
        ll bot = solve(h, mid);
        ll top = solve(h, mid+1);
        if(bot <= top){
            maxV = mid;
        }
        if(bot >= top){
            minV = mid+1;
        }
    }
    ll bestCost = solve(h, minV);
    for(int i = minV + 1; i <= maxV; i++){
        bestCost = min(solve(h,i), bestCost);
    }
    cout << bestCost << "\n";
    return 0;
}