# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int cur, int parent, vector<vector<pii>>& edges, vector<bool>& seen, vector<int>& labels){
    seen[cur] = true;
    for(pii edge: edges[cur]){
        int next = edge.second;
        int edge_label = edge.first;
        if(next==parent){
            if(labels[parent] == edge_label){
                labels[cur] = (labels[parent] + 1) % seen.size();
                break;
            }else{
                labels[cur] = edge_label;
            }
        }
    }
    for(pii edge: edges[cur]){
        int next = edge.second;
        if(!seen[next]){
            dfs(next, cur, edges, seen, labels);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> edges(n, vector<pii>());
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges[--u].push_back(pii(--c, --v));
        edges[v].push_back(pii(c, u));
    }
    vector<bool> seen(n, false);
    vector<int> labels(n, false);
    seen[0] = true;
    labels[0] = 0;
    dfs(0, 0, edges, seen, labels);
    for(int i = 0; i < n; i++){
        if(!seen[i]){
            cout << "No";
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        cout << labels[i] + 1 << "\n";
    }
    return 0;
}