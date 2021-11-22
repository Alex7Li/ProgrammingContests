# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int parent(int st, vi &p) {
    if (st == p[st]) {
        return st;
    }
    int par = parent(p[st], p);
    p[st] = par;
    return par;
}

void merge(int a, int b, vi &p) {
    p[parent(b, p)] = parent(a, p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> m >> n;
    vector<bool> loop(n, false);
    vector<int> component(n);
    for (int i = 0; i < n; i++) {
        component[i] = i;
    }
    vi ans;
    rep(i, 0, m) {
        int one, x, y;
        cin >> one >> x;
        x--;
        if (one == 1) {
            int p = parent(x, component);
            if (loop[p]) {
                // we already have a loop
                continue;
            }
            loop[p] = true;
            ans.push_back(i);
        } else {
            cin >> y;
            y--;
            int px = parent(x, component);
            int py = parent(y, component);
            if (px == py || (loop[px] && loop[py])) {
                // we got a cycle...
                continue;
            } else {
                merge(px, py, component);
                loop[px] = loop[px] || loop[py];
                ans.push_back(i);
            }
        }
    }
    ll count = 1;
    for (int i = 0; i < ans.size(); i++) {
        count = (count * 2) % 1'000'000'007;
    }
    cout << count << " " << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}