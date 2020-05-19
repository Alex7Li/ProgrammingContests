# include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/1250/K
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef ll Flow;
struct Edge {
    int dest, back;
    Flow f, c;
    bool forward;
};

struct PushRelabel {
    vector<vector<Edge>> g;
    vector<Flow> ec;
    vector<Edge *> cur;
    vector<vi> hs;
    vi H;

    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}

    void add_edge(int s, int t, Flow cap, Flow rcap = 0) {
        if (s == t) return;
        g[s].push_back({t, sz(g[t]), 0, cap, true});
        g[t].push_back({s, sz(g[s]) - 1, 0, rcap, false});
    }

    void add_flow(Edge &e, Flow f) {
        Edge &back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
        e.f += f;
        e.c -= f;
        ec[e.dest] += f;
        back.f -= f;
        back.c += f;
        ec[back.dest] -= f;
    }

    Flow maxflow(int s, int t) {
        int v = sz(g);
        H[s] = v;
        ec[t] = 1;
        vi co(2 * v);
        co[0] = v - 1;
        rep(i, 0, v) cur[i] = g[i].data();
        trav(e, g[s]) add_flow(e, e.c);

        for (int hi = 0;;) {
            while (hs[hi].empty()) if (!hi--) return -ec[s];
            int u = hs[hi].back();
            hs[hi].pop_back();
            while (ec[u] > 0)  // discharge u
                if (cur[u] == g[u].data() + sz(g[u])) {
                    H[u] = 1e9;
                    trav(e, g[u]) if (e.c && H[u] > H[e.dest] + 1)
                            H[u] = H[e.dest] + 1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        rep(i, 0, v) if (hi < H[i] && H[i] < v)
                                --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1)
                    add_flow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
        }
    }


    deque<int> find_path(int from, int to) {
        deque<int> d;
        while (from != to) {
            trav(e, g[from]) {
                if (e.forward && e.f > 0) {
                    e.f--;
                    d.push_back(from);
                    //cout << from << " ";
                    from = e.dest;
                    break;
                }
            }
        }
        return d;
    }
};

struct Talk {
    int ind, st, end, projector = -1;

    bool operator<(const Talk &o) const {
        return (st != o.st ? st < o.st : end < o.end);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases, n, m, x, y, a, b;
    cin >> cases;
    rep(t, 0, cases) {
        cin >> n >> m >> x >> y;
        vector<Talk> talks = vector<Talk>(n + m);
        vector<pii> times;
        map<int, int> compressedTime;
        rep(i, 0, n) {
            cin >> a >> b;
            talks[i] = Talk({i, a, b});
            times.push_back({a, 2});
            times.push_back({b, 0});
        }
        rep(i, 0, m) {
            cin >> a >> b;
            talks[i + n] = Talk({i + n, a, b});
            times.push_back(pii(a, 3));
            times.push_back(pii(b, 1));
        }
        sort(times.begin(), times.end());
        int nTimes = 0;
        trav(tpair, times) {
            int time = tpair.first;
            if (compressedTime.find(time) == compressedTime.end()) {
                compressedTime[time] = nTimes++;
            }
        }
        int seminars = 0, lectures = 0;
        vector<int> hdneeded = vector<int>(nTimes + 1, 0);
        vector<int> normneeded = vector<int>(nTimes + 1, 0);
        trav(event, times) {
            switch (event.second) {
                case 0:
                    lectures--;
                    break;
                case 1:
                    seminars--;
                    break;
                case 2:
                    lectures++;
                    break;
                case 3:
                    seminars++;
                    break;
            }
            hdneeded[compressedTime[event.first]] = lectures;
            normneeded[compressedTime[event.first]] = seminars;
        }
        bool pos = true;
        rep(i, 0, nTimes) {
            if (hdneeded[i] > x || normneeded[i] + hdneeded[i] > x + y) {
                pos = false;
            }
        }
        if (!pos) {
            cout << "NO\n";
            continue;
        }
        int nodes = nTimes + 1 + m;
        PushRelabel pr = PushRelabel(nodes);
        for (int i = 0; i < nTimes; i++) {
            int cap = min(x + y - hdneeded[i] - normneeded[i], y);
            pr.add_edge(i, i + 1, cap);
        }
        int ind = nTimes + 1;
        for (int i = n; i < n + m; i++) {
            auto seminar = talks[i];
            pr.add_edge(compressedTime[seminar.st], ind, 1);
            pr.add_edge(ind++, compressedTime[seminar.end], 1);
        }
        int flow = pr.maxflow(0, nTimes);
        if (flow != y) {
            cout << "NO\n";
            continue;
        }
        set<int> assigned;
        rep(i, x + 1, x + y + 1) { //follow the flow of y different projectors through the graph
            deque<int> path = pr.find_path(0, nTimes);
            //cout << endl;
            trav(p, path) {
                if (p > nTimes) {
                    assert(assigned.find(p) == assigned.end());
                    assigned.insert(p);
                    talks[p - nTimes - 1 + n].projector = i;
                }
            }
        }
        vector<Talk> otherTalks;
        for (auto i = 0u; i < talks.size(); i++) {
            if (talks[i].projector == -1) {
                otherTalks.push_back(talks[i]);
            }
        }
        sort(otherTalks.begin(), otherTalks.end());
        priority_queue<pii, vector<pii>, greater<pii>> ends;
        set<int> available;
        for(int i = 0; i < x; i++){
            available.insert(i+1);
        }
        for (Talk &talk: otherTalks) {
            while (!ends.empty() && talk.st >= ends.top().first) {
                available.insert(ends.top().second);
                ends.pop();
            }
            int projInd = *available.begin();
            available.erase(projInd);
            ends.push(pii(talk.end, projInd));
            talks[talk.ind].projector = projInd;
        }
        cout << "YES\n";
        for (int i = 0; i < n + m - 1; i++) {
            cout << talks[i].projector << " ";
        }
        cout << talks[n + m - 1].projector << "\n";
    }

    return 0;
}
