# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1500/A
using namespace std;
# define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;

int distinct(int x, int y, int z, int w) {
    if (x == z || x == y || x == w || y == z || y == w || z == w) {
        return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<set<int>> m(5000001);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int s = a[i - 1] + a[j - 1];
            m[s].insert(i);
            m[s].insert(j);
            if (m[s].size() >= 4) {
                trav(k, m[s]) {
                    trav(l, m[s]) {
                        trav(i1, m[s]) {
                            trav(k1, m[s]) {
                                if (distinct(k, l, i1, k1) &&
                                    a[k - 1] + a[l - 1] == a[i1 - 1] + a[k1 - 1]) {
                                    cout << "YES\n";
                                    cout << k << " " << l << " " << i1 << " " << k1 << "\n";
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "NO" << "\n";
    return 0;
}