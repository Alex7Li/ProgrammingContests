# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int m, n, x;
        cin >> n >> m >> x;
        vector<int> h(n);
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }
//        sort(h.begin(), h.end());
        priority_queue<pii> Q;
        for (int i = 0; i < m; ++i) {
            Q.push(pii(0, i));
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            pii next = Q.top();
            Q.pop();
            int ind = next.second;
            int he = next.first;
            ans[i] = ind;
            Q.push({he - h[i], ind});
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}