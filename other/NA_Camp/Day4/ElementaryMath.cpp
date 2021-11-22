# include <bits/stdc++.h>
using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
// This code performs maximum bipartite matching.
//
// Running time: O(|E| |V|) -- often much faster in practice
//
//   INPUT: w[i][j] = edge between row node i and column node j
//   OUTPUT: mr[i] = assignment for row node i, -1 if unassigned
//           mc[j] = assignment for column node j, -1 if unassigned
//           function returns number of matches made

#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); j++) {
        if (w[i][j] && !seen[j]) {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}
int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
    mr = VI(w.size(), -1);
    mc = VI(w[0].size(), -1);
    int ct = 0;
    // OPTIONAL SECTION: Find a greedy matching (improves performance by a big constant)
    for (int i = 0; i < w.size(); ++i) {
        for (int j = 0; j < w[0].size(); ++j) {
            if (w[i][j] && mc[j] == -1) {
                mc[j] = i;
                mr[i] = j;
                ct++;
                break;
            }
        }
    }
    // END OPTIONAL SECTION
    for (int i = 0; i < w.size(); i++) {
        VI seen(w[0].size());
        if (mr[i] == -1 && FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}
void insert(ll val, map<ll, int> &values) {
    if (values.count(val) == 0) {
        values.insert({val, values.size()});
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pll> pairs(n);
    map<ll, int> values;
    for (int i = 0; i < n; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
        insert(pairs[i].first * pairs[i].second, values);
        insert(pairs[i].first + pairs[i].second, values);
        insert(pairs[i].first - pairs[i].second, values);
    }
    int tot = values.size();
    map<int, ll> stuff;
    trav(x, values) {
        stuff.insert({x.second, x.first});
    }

    vector<vector<int>> m;
    // For each pair
    for (int i = 0; i < n; ++i) {
        VI line(tot);
        ll num1 = pairs[i].first;
        ll num2 = pairs[i].second;
        // For each value
        for (int j = 0; j < tot; ++j) {
            int result = stuff[j]; // what's the corresponding value?
            if ((result == (num1 + num2)) || (result == (num1 - num2)) || (result == (num1 * num2))) {
                line[j] = 1;
            } else {
                line[j] = 0;
            }
        }
        m.push_back(line);
    }

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < tot; ++j) {
//            cout << m[i][j] << " ";
//        }
//        cout << endl;
//    }

    VI row_mates(n);
    VI col_mates(tot);
    int value = BipartiteMatching(m, row_mates, col_mates);

    if (value != n) {
        cout << "impossible" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            ll num1 = pairs[i].first;
            ll num2 = pairs[i].second;
            int result = stuff[row_mates[i]];
            char op;
            if (result == num1 + num2) {
                op = '+';
            } else if (result == num1 - num2) {
                op = '-';
            } else if (result == num1 * num2) {
                op = '*';
            } else {
                assert(false);
            }
            cout << num1 << " " << op << " " << num2 << " = " << result << endl;
        }
    }
    return 0;
}
