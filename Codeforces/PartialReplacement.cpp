# include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/1506/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int st = 0;
        while (s[st] != '*') {
            st++;
        }
        int end = n - 1;
        while (s[end] != '*') {
            end--;
        }
        int count = end == st ? 1 : 2;
        int e = st + k;
        while (e < end) {
            for (int i = e;; i--) {
                if (s[i] == '*') {
                    st = i;
                    count += 1;
                    break;
                }
            }
            e = st + k;
        }
        cout << count << "\n";
    }
    return 0;
}