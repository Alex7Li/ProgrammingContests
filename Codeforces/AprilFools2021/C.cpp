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
    string s;
    cin >> s;
    vi a(s.size());
    for (int i = 0; i < s.size(); i++) {
        a[i] = s[i] - 'A';
    }
    bool fib = true;
    for (int j = 2; j < a.size(); j++) {
        if ((a[j - 2] + a[j - 1]) % 26 != a[j]) {
            fib = false;
        }
    }
    cout << (fib ? "YES" : "NO") << endl;
    return 0;
}