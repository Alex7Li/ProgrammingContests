# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int count_occur(vi &a, vector<vi> &occurs, int l, int r, vector<unsigned int> &random) {
    if (r - l < 30) {
        unordered_map<int, int> frequencies;
        for (int i = l; i < r; ++i) {
            frequencies[a[i]]++;
        }
        for (auto f:frequencies) {
            if (f.second > (r - l) / 2) {
                return f.second;
            }
        }
    } else {
        // random time
        for (int i = 0; i < 30; i++) {
            int v = a[(random[i] % (r - l)) + l];
            int true_f = lower_bound(occurs[v].begin(), occurs[v].end(), r) -
                         lower_bound(occurs[v].begin(), occurs[v].end(), l);
            if (true_f > (r - l) / 2) {
                return true_f;
            }
        }
    }
    return 0;
}

int num(int n, int c) {
    return max(1, n - 2 * (n - c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<vector<int>> occurs(n + 1);
    std::vector<unsigned int> indices(max(n, 30));
    std::iota(indices.begin(), indices.end(), 0);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(indices.begin(), indices.end(), default_random_engine(seed));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        occurs[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) { // sentinel
        occurs[i].push_back(2 * n);
    }
    vector<pii> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        int c = count_occur(a, occurs, queries[i].first - 1, queries[i].second, indices);
        int ans = num(queries[i].second - queries[i].first + 1, c);
        cout << ans << "\n";
    }
    return 0;
}