# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1147/D
# define MOD 998244353
using namespace std;

struct WeightedEdge {
    int to, weight;
};


bool dfs(int start, vector<vector<WeightedEdge>> &adjList, vector<int> &color, int newColor) {
    color[start] = newColor;
    for (WeightedEdge e: adjList[start]) {
        if (color[e.to] == 2 && !dfs(e.to, adjList, color, color[start] ^ e.weight)) {
            return false;
        } else if ((color[e.to] ^ color[start]) != e.weight) {
            return false;
        }
    }
    return true;
}

void addEdge(vector<vector<WeightedEdge>>& edges, int a, int b, int weight) {
    edges[a].push_back({b, weight});
    edges[b].push_back({a, weight});
}

int main() {
    string s;
    cin >> s;
    int m = s.length();
    vector<long long> twoPow(m + m, 1);
    for (unsigned i = 1; i < twoPow.size(); i++) {
        twoPow[i] = (twoPow[i - 1] * 2) % MOD;
    }
    long long ans = 0L;
    // fix the length of a.
    for (int aLen = 1; aLen < m; aLen++) {
        // there are two types of restrictions.
        // palindrome restrictions, which require characters be the same
        // and xor restrictions, which require characters to be different.
        // we represent these as a weighted graph.
        vector<vector<WeightedEdge>> edges(m + aLen + 1, vector<WeightedEdge>());
        // create palindrome restriction edges
        for (int i = 0; i < m / 2; i++) {
            addEdge(edges, i, m - i - 1, 0);
        }
        for (int i = 0; i < aLen / 2; i++) {
            addEdge(edges, i + m, m + aLen - i - 1, 0);
        }
        // chars fixed by xor
        for (int i = 0; i < m - aLen; i++) {
            if (s[i] != '?') {
                addEdge(edges, i, m + aLen, s[i] - '0');
            }
        }
        for (int i = m - aLen; i < m; i++) {
            if (s[i] != '?') {
                addEdge(edges, i, i + aLen, s[i] - '0');
            }
        }
        //first char of a is 1.
        edges[m].push_back({m + aLen, 1});
        edges[m + aLen].push_back({m, 1});
        // If we fix a character, it will fix every other character in it's
        // connected component - note it doesn't matter if we fix that character to
        // 0 or 1. So we can add to our answer 2^(# connected components - 1).
        // However, if any nodes has an odd distance to itself, you lose ):
        vector<int> colors(m + aLen + 1, 2);
        int components = -1;
        // 0: color 0. 1: color 1. 2: not yet seen
        for (int i = m + aLen; i >= 0; i--) {
            if (colors[i] == 2) {
                if (dfs(i, edges, colors, 0)) {
                    components++;
                } else {
                    goto impossible;
                }
            }
        }
        ans = (ans + twoPow[components]) % MOD;
        cout << components << " ";
        impossible:;
    }
    cout << ans;
    return 0;
}