# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
ll INF = 1LL << 62;
vi x;
vi y;
ll dist(ll ind1, ll ind2) {
    return (x[ind1] - x[ind2]) * (x[ind1] - x[ind2]) + (y[ind1] - y[ind2]) * (y[ind1] - y[ind2]);
}
vi times(int source, int n) {
    vi t(n);
    t[source] = 0;
    priority_queue<pii, vector<pii>, greater<>> queue;
    queue.push({0, source});
    vi time(n, INF);
    vector<bool> done(n);
    time[source] = 0;
    while(!queue.empty()) {
        pii cur = queue.top();
        queue.pop();
        if(done[cur.second]) {
            continue;
        }
        done[cur.second] = true;
        for (int i = 0; i < n; ++i) {
            if(!done[i]) {
                ll endT = cur.first + dist(i, cur.second);
                if(endT < time[i]) {
                    queue.push({endT, i});
                    time[i] = endT;
                }
            }
        }
    }
    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    x = vi(n);
    y = vi(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    int source;
    cin >> source;
    source--;
    vi t = times(source, n);
    sort(t.begin(), t.end());
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll lo = 0;
        ll MAX = t.size() + 1;
        ll cur_time;
        cin >> cur_time;
        for (ll j = 1LL << (ll) (log2(MAX)); j != 0; j >>= 1) {
            if (lo + j < t.size() && t[lo + j] <= cur_time) {
                lo += j;
            }
        }
        cout << (lo + 1) << "\n";
    }
    return 0;
}