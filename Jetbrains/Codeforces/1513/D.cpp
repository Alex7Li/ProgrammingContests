# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAX = 1000000007;

ll gcd(ll a, ll b) {
    return a == 0 ? b : gcd(b % a, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, p;
        cin >> n >> p;
        vector<int> a(n + 2);
        for (int i = 0; i < n; i++) {
            cin >> a[i + 1];
        }
        a[n + 1] = MAX;
        vector<int> idx(a.size());
        iota(idx.begin(), idx.end(), 0);
        stable_sort(idx.begin(), idx.end(),
                    [&a](size_t i1, size_t i2) { return a[i1] < a[i2]; });
        vector<int> seen(a.size(), MAX);
        for (int i = 1; i <= n; ++i) {
            int id = idx[i];
            if (seen[id] != MAX) {
                continue;
            }
            seen[id] = a[id];
            int j = id;
            ll gc = a[id];
            while (j + 1 <= n && seen[j + 1] > seen[j] && gcd(a[j + 1], gc) == a[id]) {
                seen[j + 1] = seen[j];
                gc = gcd(a[j + 1], gc);
                j++;
            }
            j = id;
            gc = a[id];
            while (j - 1 >= 0 && seen[j - 1] > seen[j] && gcd(a[j - 1], gc) == a[id]) {
                seen[j - 1] = seen[j];
                gc = gcd(a[j - 1], gc);
                j--;
            }
        }
        ll sum = 0;
        for (int i = 1; i < n; ++i) {
            int aa = seen[i];
            int b = seen[i + 1];
            int best = p;
            if (aa == b) {
                best = min(aa, best);
            }
            if (gcd(a[i], b) == b) {
                best = min(b, best);
            }
            if (gcd(a[i + 1], aa) == aa) {
                best = min(aa, best);
            }
            sum += best;
        }
        cout << sum << "\n";
    }
    return 0;
}