# include <bits/stdc++.h>
using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class k, class v>
using ordered_map = tree<k, v, less<k>,
        rb_tree_tag, // Red black tree. Can use splay_tree_tag for a splay tree,
        // but split operation for splay is linear time so it may be terrible.
        tree_order_statistics_node_update // To get find_by_order and order_of_key methods
>;
template<class k> // Same as ordered map almost
        using ordered_set = tree<k, null_type, less<k>,
        rb_tree_tag, tree_order_statistics_node_update>;

int INF = 100'000'000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, m;
        cin >> n >> m;
        // set of times that movies are at
        ordered_set<int> locmap;
        // map movie index -> time;
        vector<int> loc(n + 1);
        for (int i = 1; i <= n; ++i) {
            locmap.insert(i);
            loc[i] = i;
        }
        int time = 0;
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            int query;
            cin >> query;
            int movie_time = loc[query];
            ans.push_back(locmap.order_of_key(movie_time));
            locmap.erase(movie_time);
            locmap.insert(time);
            loc[query] = time;
            time--;
        }
        cout << ans[0];
        for (int i = 1; i < ans.size(); ++i) {
            cout << " " << ans[i];
        }
        cout << endl;
    }
    return 0;
}