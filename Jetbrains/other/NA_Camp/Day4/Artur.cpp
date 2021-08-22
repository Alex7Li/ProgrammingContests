# include <bits/stdc++.h>
using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<double, double> pii;
typedef vector<double> vd;
typedef vector<int> vi;
typedef pair<pii, pii> ptype;

double interpolate(ptype p, double x) {
    double x1 = p.first.first;
    double y1 = p.first.second;
    double x2 = p.second.first;
    double y2 = p.second.second;
    return (x2 - x) / (x2- x1) * y1 + (x-x1)/(x2- x1)  * y2;
}

int def(ptype q, ptype p){
    if(q.second.first < p.first.first){
        return false;
    }
    if(p.second.first < q.first.first){
        return false;
    }
    if(p.first.first == p.second.first && q.first.first == q.second.first){
        return q.first.second < p.first.second;
    }
    if (p.first.first == p.second.first){
        return interpolate(q, p.first.first) < p.first.second;
    }
    if(q.first.first == q.second.first){
        return q.first.second < interpolate(p, q.first.first);
    }
    if(q.first.first < p.first.first) {
        return interpolate(q, p.first.first) < p.first.second;
    }else {
        return q.first.second < interpolate(p, q.first.first);
    }
}
vi topoSort(const vector<vi>& gr) {
    vi indeg(sz(gr)), ret;
    for (auto& li : gr) for (int x : li) indeg[x]++;
    queue<int> q; // use priority queue for lexic . largest ans.
    rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int i = q.front(); // top() for priority queue
        ret.push_back(i);
        q.pop();
        for (int x : gr[i])
            if (--indeg[x] == 0) q.push(x);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ptype> sticks(n, {{0,0},{0,0}});
    for (int i = 0; i < n; ++i) {
        cin >> sticks[i].first.first >> sticks[i].first.second >> sticks[i].second.first >> sticks[i].second.second;
        if(sticks[i].first > sticks[i].second){
            swap(sticks[i].first, sticks[i].second);
        }
    }
    vector<vi> g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i != j){
                if(def(sticks[i], sticks[j])) {
                    g[i].push_back(j);
                }
            }
        }
    }
    vi ans = topoSort(g);
    for (int i = 0; i < (int)(ans.size() - 1); ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << ans[ans.size() - 1] + 1 << endl;
    return 0;
}