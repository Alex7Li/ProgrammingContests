# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef4/0000000000317409
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int e, n;
        cin >> e >> n;
        string tour;
        cin >> tour;
        bool done = false;
        cout << "Case #" << i << ": ";
        for (int t = 0; t <= tour.size(); t++) {
            if (abs(e) + abs(n) <= t) {
                cout << t;
                done = true;
                break;
            }
            if (t != tour.size()) {
                switch (tour[t]) {
                    case 'N':
                        n++;
                        break;
                    case 'E':
                        e++;
                        break;
                    case 'W':
                        e--;
                        break;
                    case 'S':
                        n--;
                        break;
                }
            }
        }
        if (!done) {
            cout << "IMPOSSIBLE";
        }
        cout << "\n";
    }
    return 0;
}