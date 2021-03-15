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
    int n;
    cin >> n;
    vi o1(n * 2 + 1);
    vi c(n * 2 + 1);
    rep(i, 0, n) {
        int ai, bi;
        cin >> ai >> bi;
        if (ai == bi) {
            o1[ai]++;
            c[ai] += 2;
        } else {
            o1[ai]++;
            o1[bi]++;
            c[ai]++;
            c[bi]++;
        }
    }
    int ops = 2 * n;
    rep(i, 0, 2 * n + 1) {
        ops = min(2 * n - c[i], ops);
    }
    int m11 = 0;
    int m12 = 0;
    rep(i, 0, 2 * n + 1) {
        if (o1[i] > m12) {
            if (o1[i] > m11) {
                m12 = m11;
                m11 = o1[i];
            } else {
                m12 = o1[i];
            }
        }
    }
    ops = min(ops, 2 * n - m11 - m12);
    cout << ops << endl;
    return 0;
}