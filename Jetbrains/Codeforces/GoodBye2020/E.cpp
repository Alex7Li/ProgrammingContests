# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define MOD 1'000'000'007
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
        int n;
        cin >> n;
        vector<ll> x(n);
        vector<ll> counts(62, 0);
        rep(i, 0, n) {
            cin >> x[i];
            rep(j, 0, 61) {
                if ((x[i] & (1LL << j)) != 0) {
                    counts[j]++;
                }
            }
        }
        vector<ll> a(n);
        vector<ll> b(n);
        rep(i, 0, n) {
            rep(j, 0, 61) {
                ll pow = (1LL << j) % MOD;
                ll add = (counts[j] * pow) % MOD;
                if ((x[i] & (1LL << j)) != 0) {
                    a[i] = (a[i] + add) % MOD;
                    ll addAll = (n * pow) % MOD;
                    b[i] = (b[i] + addAll) % MOD;
                } else {
                    b[i] = (b[i] + add) % MOD;
                }
            }
        }
        ll sum = 0;
        rep(i, 0, n) {
            sum = (sum + a[i] * b[i]) % MOD;
        }
        cout << sum << '\n';
    }
    return 0;
}