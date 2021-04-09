# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
# define MOD 998244353
# define HALF 499122177


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> ways(n + 1);
    ways[0] = 1;
    ways[1] = 1;
    vector<ll> waysAC(n + 1);
    waysAC[0] = ways[0];
    waysAC[1] = ways[1];
    ll denom = 1;
    for (int i = 0; i < n; i++) {
        denom = (denom * HALF) % MOD;
    }
    for (int i = 2; i <= n; i++) {
        ways[i] = waysAC[i - 1];
        waysAC[i] = (waysAC[i - 2] + ways[i]) % MOD;
    }
    cout << (ways[n] * denom) % MOD;
    return 0;
}
