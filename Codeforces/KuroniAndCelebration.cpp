# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
//https://codeforces.com/contest/1305/problem/D
void answer(int ans) {
    cout << "! " << ans+1 << endl;
}

int ask(vector<int> &query) {
    cout << "? " << (query[0] + 1) << " " << (query[1] + 1) << endl;
    cout.flush();
    int x;
    cin >> x;
    return x - 1;
}

void removeEdge(vector<vi> &edges, int ind1, int ind2) {
    edges[ind1].pop_back();
    for (int i = 0; i < edges[ind2].size(); i++) {
        if (edges[ind2][i] == ind1) {
            edges[ind2].erase(edges[ind2].begin() + i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int j, k;
        cin >> j >> k;
        edges[--k].push_back(--j);
        edges[j].push_back(k);
    }
    vector<bool> canBeRoot(n, true);
    for (int i = 0; i < n / 2; i++) {
        vector<int> query;
        for (int j = 0; j < n; j++) {
            if (edges[j].size() == 1) {
                query.push_back(j);
                canBeRoot[j] = false;
                if (query.size() == 2) {
                    break;
                }
            }
        }
        int response = ask(query);
        if (response == query[0] || response == query[1]) {
            answer(response);
            return 0;
        } else {
            removeEdge(edges, query[0], edges[query[0]][0]);
            removeEdge(edges, query[1], edges[query[1]][0]);
        }
    }
    for(int i = 0; i < n; i++){
        if(canBeRoot[i]){
            answer(i);
        }
    }
    return 0;
}