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
    ll C;
    cin >> n >> C;
    vector<pii> e;
    for (int i = 0; i < n; i++) {
        int s, en, val;
        cin >> s >> en >> val;
        e.push_back(pii{s, val});
        e.push_back(pii{en + 1, -val});
    }
    sort(e.begin(), e.end());
    ll curDay = 0;
    ll curCost = 0;
    ll tCost = 0;
    for (int i = 0; i < e.size(); i++) {
        if (e[i].first > curDay) {
            tCost += (e[i].first - curDay) * min(curCost, C);
            curDay = e[i].first;
        }
        curCost += e[i].second;
    }
    cout << tCost << "\n";
    return 0;
}
