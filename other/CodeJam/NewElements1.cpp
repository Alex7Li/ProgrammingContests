# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000051679/0000000000146183
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T>
T gcd(T a, T b) {
    if (a == 0) {
        return b;
    } else {
        return gcd(b % a, a);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 1, t + 1) {
        int n;
        cin >> n;
        vector<pii> points(n);
        cout << "Case #" << tt << ": ";
        set<pii> slopes;
        rep(i, 0, n) {
            cin >> points[i].first >> points[i].second;
        }

        rep(i, 0, n) {
            rep(j, 0, n) {
                int dx = points[i].first - points[j].first;
                int dy = points[i].second - points[j].second;
                if (dx > 0 && dy < 0) {
                    int d = gcd<int>(dx, dy);
                    slopes.insert(pii(dx / d, dy / d));
                }
            }
        }
        cout << slopes.size() + 1 << "\n";
    }
    return 0;
}






