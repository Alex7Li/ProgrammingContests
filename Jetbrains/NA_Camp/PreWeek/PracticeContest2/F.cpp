# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
VPII edges;
// THIS IS A HACKY AF SOLUTION BUT IT WORKED
// Output best weight MST, edges are the
// edges in the MST
T Prim(const VVT &w) {
    edges.clear();
    int n = w.size();
    VI found(n);
    VI prev(n, -1);
    VT dist(n, 10e20);
    int here = 0;
    dist[here] = 0;

    while (here != -1) {
        found[here] = true;
        int best = -1;
        for (int k = 0; k < n; k++)
            if (!found[k]) {
                if (w[here][k] != -1 && dist[k] > w[here][k]) {
                    dist[k] = w[here][k];
                    prev[k] = here;
                }
                if (best == -1 || dist[k] < dist[best]) best = k;
            }
        here = best;
    }

    T tot_weight = 0;
    for (int i = 0; i < n; i++)
        if (prev[i] != -1) {
            edges.push_back(make_pair(prev[i], i));
            tot_weight += w[prev[i]][i];
        }
    return tot_weight;
}
pair<ll, ll> getTimeAndMoney(VVI &costT, VVI &costC) {
    ll time = 0;
    ll money = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        time += costT[u][v];
        money += costC[u][v];
    }
    return {time, money};
}
ll eval(VVI &costT, VVI &costC, double w) {
    int n = costC.size();
    VVT cost(n, VT(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = costT[i][j] + costC[i][j] * w;
    Prim(cost); // updates edges
    pair<ll, ll> tm = getTimeAndMoney(costT, costC);
    return tm.first * tm.second;
}
// AH, YES. THE BINARY SEARCH ALGORITHM?
// It's terrible since sometimes two elements can
// be equal and we have no guarantees in this case.
// So we do a multiphase grid search instead lol
ll best_cost(VVI &costT, VVI &costC, double low, double hi) {
    ll cL = eval(costT, costC, low);
    ll best = cL;
    double bestV = low;
    vector<ll> scores;
    double step = (hi - low) / 512.0;
    for (double mid = low + step; mid < hi; mid += step) {
        ll scoreM = eval(costT, costC, mid);
        if(scoreM < best) {
            best = scoreM;
            bestV = mid;
        }
    }
    if (hi - low < .000000001) {
        return eval(costT, costC, bestV);
    } else {
        return best_cost(costT, costC, bestV - step, bestV + step);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    VVI costT(n, VI(n, 10000));
    VVI costC(n, VI(n, 10000));
    for (int i = 0; i < n; ++i) {
        costT[i][i] = 0;
        costC[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        cin >> costT[x][y];
        costT[y][x] = costT[x][y];
        cin >> costC[x][y];
        costC[y][x] = costC[x][y];
    }
    best_cost(costT, costC, 0, 256);
    pair<ll, ll> tm = getTimeAndMoney(costT, costC);
    cout << tm.first << " " << tm.second << endl;
    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }
}