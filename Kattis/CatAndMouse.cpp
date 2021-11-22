# include <bits/stdc++.h>
//https://open.kattis.com/problems/catandmice
using namespace std;
# define trav(a, x) for(auto& a : x)
# define INF std::numeric_limits<double>::infinity()
typedef vector<int> vi;
typedef vector<double> vd;


bool can_catch_all(vi &x, vi &y, vi &s, double m, double start_v, int n) {
    // We can be at mouse i having seen subset S at time t
    vector<vd> dp(1 << n, vd(n, INF));
    for (int i = 0; i < n; i++) {
        // cat starts after catching the ith mouse
        double arrive_time = hypot(x[i], y[i]) / start_v;
        if(arrive_time < s[i]) {
            dp[1 << i][i] = arrive_time;
        }
    }
    for (int i = 1; i < 1 << n; i++) {
        vi mouses_caught;
        vi mouses_not_caught;
        for (int j = 0; j < n; j++) {
            if (((1 << j) & i) == 0) {
                mouses_not_caught.push_back(j);
            } else {
                mouses_caught.push_back(j);
            }
        }
        double speed = start_v * pow(m, mouses_caught.size());
        trav(from_mouse, mouses_caught) {
            trav(to_mouse, mouses_not_caught) {
                int new_set = i | (1 << to_mouse);
                double arrive_time = dp[i][from_mouse] + hypot(x[from_mouse] - x[to_mouse],
                                                               y[from_mouse] - y[to_mouse]) / speed;
                if (arrive_time < s[to_mouse]) {
                    dp[new_set][to_mouse] = min(dp[new_set][to_mouse], arrive_time);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dp[(1 << n) - 1][i] != INF) {
            return true;
        }
    }
    return false;
}


int main() {
    int n;
    cin >> n;
    vi x(n);
    vi y(n);
    vi s(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }
    double m;
    cin >> m;
    double high = 1e10;
    double low = 0.0001;
    while (low + .00001 < high) {
        double mid = (high + low) / 2;
        if (can_catch_all(x, y, s, m, mid, n)) {
            high = mid; // can be slower
        } else {
            low = mid; //gotta go faster
        }
    }
    printf("%lf\n", low);
    return 0;
}