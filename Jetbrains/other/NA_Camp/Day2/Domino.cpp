# include <bits/stdc++.h>
using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Description: Disjoint-set data structure.
 * Time: $O(alpha(N))$
 */
struct UF {
    // E is parent set number if positive, and the size if negative.
    // If negative, it's the root of a set.
    vi e;
    vector<deque<int>> odds;
    UF(int n) : e(n, -1), odds(n) {};
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        if (odds[a].size() < odds[b].size()) {
            swap(odds[a], odds[b]);
        }
        while (!odds[b].empty()) {
            odds[a].push_back(odds[b].front());
            odds[b].pop_back();
        }
        sort(odds[a].begin(), odds[a].end());
        return true;
    }
};

void dfs(vector<vi> &g, int st, set<int> &seen, UF &uf, vector<int> &counts) {
    seen.insert(st);
    if (counts[st] % 2 == 1) {
        uf.odds[st].push_back(st);
    }
    queue<int> Q;
    Q.push(st);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        trav(next, g[cur]) {
            if (seen.count(next) == 0) {
                seen.insert(next);
                Q.push(next);
                uf.join(st, next);
                if (counts[next] % 2 == 1) {
                    uf.odds[uf.find(next)].push_back(next);
                }
            }
        }
    }
    // No odds, pretend the smallest occurs twice
    assert(uf.find(st) == st);
    if (uf.odds[st].empty()) {
        uf.odds[st].push_back(st);
        uf.odds[st].push_back(st);
    }
}
const int MAX = 50001;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int k;
        cin >> k;
        vi counts(MAX, 0);
        vector<vi> g(MAX);
        for (int i = 0; i < k; ++i) {
            int a, b;
            cin >> a >> b;
            counts[a]++;
            counts[b]++;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        UF uf(MAX);
        set<int> seen;
        int ccs = 0;
        vector<int> odd_inds;
        for (int i = 0; i < (int)counts.size(); ++i) {
            if (counts[i] > 0 && seen.count(i) == 0) {
                dfs(g, i, seen, uf, counts);
                ccs++;
                for (int &j : uf.odds[i]) {
                    odd_inds.push_back(j);
                }
            }
        }
        sort(odd_inds.begin(), odd_inds.end());
        vector<bool> done(odd_inds.size());
        int left = odd_inds.size()/2 - 1;
        cout << left << "\n";
        for (int i = 0; left > 0; ++i) {
            if (done[i]) {
                continue;
            }
            int first = odd_inds[i];
            int first_comp = uf.find(first);
            for (int j = i + 1; true; ++j) {
                if (done[j]) {
                    continue;
                }
                int second = odd_inds[j];
                int second_comp = uf.find(second);
                if (!uf.sameSet(first, second) || uf.odds[first_comp].size() > 2 || ccs == 1) {
                    left--;
                    cout << first << " " << second << "\n";
                    // assert(uf.odds[first_comp].front() == first);
                    uf.odds[first_comp].pop_front();
                    // assert(uf.odds[second_comp].front() == second);
                    uf.odds[second_comp].pop_front();
                    if(uf.join(first_comp, second_comp)){
                        ccs--;
                    }
                    done[i] = true;
                    done[j] = true;
                    break;
                }
            }
        }
    }
    return 0;
}
