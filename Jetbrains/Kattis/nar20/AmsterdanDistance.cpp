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
    double m, n, r;
    cin >> m >>n >> r;
    double at, ay, bt, by;
    cin >> at >> ay >> bt >> by;
    double hd = r*abs(ay-by)/n;
    double vd = M_PI * (r * min(ay, by))/m * abs(at-bt)/n;
    double ans = min(hd+vd, (ay+by)*r/n);
    printf("%.9f", ans);
    return 0;
}