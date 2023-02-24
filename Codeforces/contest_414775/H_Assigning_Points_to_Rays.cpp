#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class k, class v>
using hash_map = __gnu_pbds::gp_hash_table<k, v>;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define PI 3.14159265358979323846
#ifdef LOCAL
    #pragma GCC optimize("trapv") // signed overflow => RE
#else
    #pragma GCC target("arch=skylake") // CF only
#endif

struct Point {
  int x;
  int y;
  int orig_ind;
};

struct Ray {
  Point p;
  int volume;
  int orig_ind;
};

#define epsilon 1e-15

double mod2pi(double x){
  while(x < -PI){
    x += PI * 2;
  }
  while(x > PI - epsilon) {
    x -= PI * 2;
  }
  return x;
}

inline double atan2l(int a, int b){
  return atan2((double)a, (double)b);
}
int is_between(Point& p, Point& r1, Point& r2) {
  long double p1 = atan2l(r1.y, r1.x);
  long double p2 = atan2l(r2.y, r2.x);
  long double pa = atan2l(p.y, p.x);
  long double theta2 = mod2pi(p2 - pa);
  long double theta1 = mod2pi(pa - p1);
  if(abs(theta1 - theta2) < epsilon) {
    return 0;
  }
  if(abs(theta1) > abs(theta2)){
    return 1;
  } else {
    return -1;
  }
}
int sign(ll x){
  if (x==0) {
    return 0;
  } else if(x > 0) {
    return 1;
  } else {
    return -1;
  }
}

bool rot_less(const Point& a, const Point& b) {
  // if equal return false
  if(sign(a.y) == sign(b.y) &&
     sign(a.x) == sign(b.x) &&
     a.y * b.x == a.x * b.y){
    return false;
  }
  return mod2pi(atan2l(a.y, a.x)) < mod2pi(atan2l(b.y, b.x));
}
struct PushRelabel {
  struct Edge {
    int dest, back;
    int f, c;
  };
  vector<vector<Edge>> g;
  vector<int> ec;
  vector<Edge*> cur;
  vector<vi> hs;
  vi H;
  PushRelabel(int n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}
  void addEdge(int s, int t, int cap, int rcap = 0) {
    if (s == t) return;
    g[s].push_back({t, sz(g[t]), 0, cap});
    g[t].push_back({s, sz(g[s]) - 1, 0, rcap});
  }
  void addFlow(Edge& e, ll f) {
    Edge& back = g[e.dest][e.back];
    if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
    e.f += f;
    e.c -= f;
    ec[e.dest] += f;
    back.f -= f;
    back.c += f;
    ec[back.dest] -= f;
  }
  ll calc(int s, int t) {
    int v = sz(g);
    H[s] = v;
    ec[t] = 1;
    vi co(2 * v);
    co[0] = v - 1;
    rep(i, 0, v) cur[i] = g[i].data();
    for (Edge& e : g[s]) addFlow(e, e.c);
    for (int hi = 0;;) {
      while (hs[hi].empty())
        if (!hi--) return -ec[s];
      int u = hs[hi].back();
      hs[hi].pop_back();
      while (ec[u] > 0)  // discharge u
        if (cur[u] == g[u].data() + sz(g[u])) {
          H[u] = 1e9;
          for (Edge& e : g[u])
            if (e.c && H[u] > H[e.dest] + 1) H[u] = H[e.dest] + 1, cur[u] = &e;
          if (++co[H[u]], !--co[hi] && hi < v)
            rep(i, 0, v) if (hi < H[i] && H[i] < v)-- co[H[i]], H[i] = v + 1;
          hi = H[u];
        } else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1)
          addFlow(*cur[u], min(ec[u], cur[u]->c));
        else
          ++cur[u];
    }
  }
  bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};
// Adjacency list implementation of Dinic's blocking flow algorithm.
// This is very fast in practice, and only loses to push-relabel flow.
//
// Running time:
//     O(|V|^2 |E|)
//
// INPUT:
//     - graph, constructed using AddEdge()
//     - source and sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain actual flow values, look at edges with capacity > 0
//       (zero capacity edges are residual edges).

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

struct Edge {
    int u, v;
    ll cap, flow;
    Edge() {}
    Edge(int u, int v, ll cap) : u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
    int N;
    vector<Edge> E;
    vector<vector<int>> g;
    vector<int> d, pt;
    Dinic(int N) : N(N), E(0), g(N), d(N), pt(N) {}
    void addEdge(int u, int v, ll cap) {
        if (u != v) {
            E.emplace_back(u, v, cap);
            g[u].emplace_back(E.size() - 1);
            E.emplace_back(v, u, 0);
            g[v].emplace_back(E.size() - 1);
        }
    }
    bool BFS(int S, int T) {
        queue<int> q({S});
        fill(d.begin(), d.end(), N + 1);
        d[S] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == T) break;
            for (int k: g[u]) {
                Edge &e = E[k];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
                    d[e.v] = d[e.u] + 1;
                    q.emplace(e.v);
                }
            }
        }
        return d[T] != N + 1;
    }
    ll DFS(int u, int T, ll flow = -1) {
        if (u == T || flow == 0) return flow;
        for (int &i = pt[u]; i < g[u].size(); ++i) {
            Edge &e = E[g[u][i]];
            Edge &oe = E[g[u][i] ^ 1];
            if (d[e.v] == d[e.u] + 1) {
                ll amt = e.cap - e.flow;
                if (flow != -1 && amt > flow) amt = flow;
                if (ll pushed = DFS(e.v, T, amt)) {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    ll MaxFlow(int S, int T) {
        ll total = 0;
        while (BFS(S, T)) {
            fill(pt.begin(), pt.end(), 0);
            while (ll flow = DFS(S, T))
                total += flow;
        }
        return total;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<Point> points(m);
    rep(i, 0, m) {
      cin >> points[i].x >> points[i].y;
      points[i].orig_ind = i;
    }
    sort(points.begin(), points.end(), rot_less);
    vector<Ray> rays(n);
    rep(i, 0, n) {
      cin >> rays[i].p.x >> rays[i].p.y >> rays[i].volume;
      rays[i].orig_ind = i;
    }
    sort(rays.begin(), rays.end(), [](Ray& a, Ray& b) {
      return rot_less(a.p, b.p);
    });
    Dinic flow(n + m + 2);
    int next_ray_ind = 0;
    for(int i = 0; i < points.size(); i++){
      while(next_ray_ind < rays.size() &&
        rot_less(rays[next_ray_ind % n].p, points[i])) {
        // cout << i _ next_ray_ind << endl;
        next_ray_ind += 1;
      }
      int prev = (next_ray_ind + n - 1) % n;
      int next = next_ray_ind % n;
      // assert(rot_less(points[i], rays[next].p));
      // assert(rot_less(points[prev], rays[i].p));
      int cmp = is_between(points[i], rays[prev].p, rays[next].p);
      if(cmp >= 0) {
        // cout << i _ next _ endl;
        flow.addEdge(i, next + m, 1);
      }
      if(cmp <= 0) {
        // cout << i _ prev _ endl;
        flow.addEdge(i, prev + m, 1);
      }
    }
    rep(i, 0, m) {
      // cout << n + m _ i << endl;
      flow.addEdge(n + m, i, 1);
    }
    rep(i, m, n + m) {
      // cout << i _ n + m  + 1 << endl;
      flow.addEdge(i, n + m + 1, rays[i - m].volume);
    }
    int ans = flow.MaxFlow(n + m, n + m + 1);
    std::cout << ans << "\n";
    vector<pii> ansList;
    // rep(i, 0, m) {
    //   for(auto edge: flow.g[i]) {
    //     if(edge.f > 0) {
    //       ansList.push_back({i, edge.dest - m});
    //     }
    //   }
    // }
    for(int i = 0; i < flow.E.size(); i++){
      if(flow.E[i].flow > 0 && flow.E[i].u < m && flow.E[i].v >= m) {
          ansList.push_back({flow.E[i].u, flow.E[i].v - m});
      }

    }
    for(int i = 0; i < ansList.size(); i++){
      std::cout << points[ansList[i].first].orig_ind << " " << rays[ansList[i].second].orig_ind << "\n";
    }
    return 0;
}