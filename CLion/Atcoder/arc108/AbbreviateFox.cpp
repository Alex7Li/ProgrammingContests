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
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<int> last;
    int score = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == 'f') {
            last.push(0);
            continue;
        } else if (s[i] == 'o' && last.size() > 0 && last.top() == 0) {
            last.pop();
            last.push(1);
        } else if (s[i] == 'x' && last.size() > 0 && last.top() == 1) {
            last.pop();
            score += 1;
        } else {
            last = stack<int>();
        }
    }
    cout << n - 3 * score;
    return 0;
}