# include <bits/stdc++.h>
//https://codeforces.com/gym/100377/attachments/download/2401/2014-zimnyaya-shkola-po-programmirovaniu-harkov-dyen-4-ya-tvyerdohlyeb-r-yedyemskiy-vysshaya-liga-en.pdf
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct City {
    ll x, c, t;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<City> cities(n);
    rep(i, 0, n) {
        cin >> cities[i].x >> cities[i].c >> cities[i].t;
    }
    vector<ll> maxC(n, 0);
    rep(i, 1, n) {
        rep(j, 0, i) {
            ll cost = cities[j].c * abs(cities[j].x - cities[i].x) + cities[i].t;
            maxC[i] = max(maxC[i], maxC[j] + cost);
        }
    }
    cout << maxC[n - 1] << "\n";
    return 0;
}