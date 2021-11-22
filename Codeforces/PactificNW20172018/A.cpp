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
    bool odd = true;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == s[i + 1]) {
            odd = false;
        }
    }
    cout << (odd ? "Odd." : "Or not.");
    return 0;
}