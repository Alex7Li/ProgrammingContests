# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll bestScore(vector<ll> c, int n) {
    ll mina = c[0];
    ll minb = c[1];
    ll suma = c[0];
    ll sumb = 0;
    ll best = 1LL << 62;
    for (int len = 1; len < c.size(); ++len) {
        if (len % 2 == 0) {
            mina = min(mina, c[len]);
            suma += c[len];
        } else {
            minb = min(minb, c[len]);
            sumb += c[len];
        }
        ll score = suma + sumb;
        ll evenLeft = n - (len + 2) / 2;
        ll oddLeft = n - (len + 1) / 2;
        score += mina * evenLeft;
        score += minb * oddLeft;
        best = min(best, score);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<ll> c(n);
        rep(i, 0, n) {
            cin >> c[i];
        }
        ll best = bestScore(c, n);
        rep(i, 0, n / 2) {
            swap(c[2 * i], c[2 * i + 1]);
        }
        /*
        if (c.size() % 2 == 1) {
            c.pop_back();
        }
        best = min(best, bestScore(c, n));*/
        cout << best << "\n";
    }
    return 0;
}