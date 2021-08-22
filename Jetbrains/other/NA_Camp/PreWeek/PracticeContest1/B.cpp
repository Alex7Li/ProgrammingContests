# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Airport {
    bool normal = true;
    set<int> flights;
};

int get_dist(vector<Airport> adj, int s, int t) {
    int n = adj.size();
    queue<pii> queue;
    set<int> off_set;
    for (int i = 0; i < n; ++i) {
        if (i != s) {
            off_set.insert(i);
        }
    }
    queue.push({s, 0});
    while (!queue.empty()) {
        pii p = queue.front();
        int ind = p.first;
        int d = p.second;
        queue.pop();
        if (ind == t) {
            return d;
        }
        Airport port = adj[ind];
        if (port.normal) {
            for (int flight_ind : port.flights) {
                if (off_set.end() == off_set.find(flight_ind)) {
                    // not in the set, so it is in the queue.
                    continue;
                } else {
                    off_set.erase(flight_ind);
                    queue.push({flight_ind, d + 1});
                }
            }
        } else {
            set<int> new_off_set;
            for(int flight_ind : off_set){
                if (port.flights.end() == port.flights.find(flight_ind)) {
                    // Not in the set of things we don't go to:
                    // thus we go here
                    queue.push({flight_ind, d + 1});
                } else {
                    new_off_set.insert(flight_ind);
                }
            }
            off_set = new_off_set;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int s, t;
    cin >> n >> s >> t;
    vector<Airport> adj;
    for (int i = 0; i < n; ++i) {
        char t;
        cin >> t;
        int m;
        cin >> m;
        set<int> flights;
        for (int j = 0; j < m; j++) {
            int to;
            cin >> to;
            flights.insert(to);
        }
        adj.push_back({t == 'N', flights});
    }
    int ans = get_dist(adj, s, t);
    if (ans == -1) {
        cout << "impossible";
    } else {
        cout << ans;
    }
    cout << endl;
    return 0;
}