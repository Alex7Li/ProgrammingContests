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
    string s, t;
    cin >> s >> t;
    int best = 1001;
    for (int i = 0; i <= s.length() - t.length(); i++) {
        int cur = 0;
        for (int j = 0; j < t.length(); j++) {
            if (s[i + j] != t[j]) {
                cur++;
            }
        }
        best = min(best, cur);
    }
    cout << best;
    return 0;
}