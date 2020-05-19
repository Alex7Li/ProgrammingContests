# include <bits/stdc++.h>
//https://codeforces.com/contest/1311/problem/C
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(i, 0, t) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<ll> counts(s.length(), 0);
        rep(j, 0, m) {
            int p;
            cin >> p;
            counts[p-1]++;
        }
        vector<ll> letters(26, 0);
        counts[s.length() - 1]++;
        letters[s[s.length() - 1] - 'a'] += 1;
        for (int j = n - 2; j >= 0; j--) {
            counts[j] += counts[j + 1];
            letters[s[j] - 'a'] += counts[j];
        }
        cout << letters[0];
        rep(j, 1, 26) {
            cout << " " << letters[j];
        }
        cout << "\n";
    }
    return 0;
}