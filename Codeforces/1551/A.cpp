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
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        int a = n / 3;
        int b = a;
        if (a + 2 * (b + 1) <= n) {
            b++;
        }
        if ((a + 1) + 2 * b <= n) {
            a++;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}