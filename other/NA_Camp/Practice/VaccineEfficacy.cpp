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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int total_vaccinated = 0;
    int total_unvaccinated = 0;
    vector<double> vac(3, 0);
    vector<double> unv(3, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s[0] == 'Y') {
            total_vaccinated++;
            for (int j = 0; j < 3; ++j) {
                if (s[j + 1] == 'Y') {
                    vac[j]++;
                }
            }
        } else {
            total_unvaccinated++;
            for (int j = 0; j < 3; ++j) {
                if (s[j + 1] == 'Y') {
                    unv[j]++;
                }
            }
        }
    }
    cout.setf(ios::fixed);
    cout << setprecision(10);
    for (int i = 0; i < 3; ++i) {
        if (unv[i] * total_vaccinated <= vac[i] * total_unvaccinated) {
            cout << "Not Effective";
        } else {
            vac[i] /= total_vaccinated; // vaccinated efficacy
            unv[i] /= total_unvaccinated; // unvaccinated efficacy
            // (1 - x) * unv[i] = vac[i];
            cout << (1 - vac[i] / unv[i]) * 100;
        }
        cout << endl;
    }
    return 0;
}