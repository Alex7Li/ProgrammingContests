# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void make_order(int n, vector<bool> &st) {
    if (st.size() >= n) {
        return;
    }
    int sz = st.size();
    for (int i = 0; i < sz; ++i) {
        st.push_back(!st[i]);
    }
    make_order(n, st);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<bool> order = {false, true};
    make_order(n + m, order);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (order[i + j]) {
                cout << 'B';
            } else {
                cout << 'Y';
            }
        }
        cout << "\n";
    }
    return 0;
}