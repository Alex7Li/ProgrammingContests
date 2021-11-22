# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000432cd3/000000000043315f
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1000002013;

ll sumTo(ll x) {
    return ((x * (x - 1)) / 2) % MOD;
}

ll cost(ll dist, ll n) {
    return sumTo(n) - sumTo(n - dist);
}

ll solve(vector<pii> event, int n) {
    // time, number of peps
    stack<pii> toDepart;
    ll tcost = 0;
    trav(e, event) {
        if (e.second < 0) {
            // it's a start
            e.second *= -1;
            toDepart.push(e);
        } else {
            // if it's an end, depart a lot of people
            while (!toDepart.empty() && e.second >= toDepart.top().second) {
                ll people = toDepart.top().second;
                e.second -= people;
                ll dist = e.first - toDepart.top().first;
                tcost = (tcost + people * cost(dist, n)) % MOD;
                toDepart.pop();
            }
            if (e.second > 0) {
                ll people = e.second;
                ll dist = e.first - toDepart.top().first;
                tcost = (tcost + people * cost(dist, n)) % MOD;
                toDepart.top().second -= e.second;
            }
        }
    }
    return tcost;
}

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, m;
        cin >> n >> m;
        // ind, number of peps (negative for start)
        vector<pii> event(2 * m);
        rep(i, 0, m) {
            int o, e, p;
            cin >> o >> e >> p;
            event[2 * i] = pii(o, -p);
            event[2 * i + 1] = pii(e, p);
        }
        ll orig = solve(event, n);
        sort(event.begin(), event.end());
        ll after = solve(event, n);
        cout << "Case #" << tt << ": " << ((orig - after) % MOD + MOD) % MOD << "\n";
    }
    return 0;
}