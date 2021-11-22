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
    while (n != 0) {
        int xS = (n - 1) / 2;
        int yS = (n - 1) / 2;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            xS += x;
            yS += y;
        }
        cout << xS / n << " " << yS / n << "\n";
        cin >> n;
    }
    cout << endl;
    return 0;
}