# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

vector<pii> make_diff(vector<ll> &f, ll l) {
    ll fix = 0;
    ll loose = l;
    vector<pii> ans;
    ll left = l;
    for (long long fi : f) {
        if (fix < loose) {
            ll pivot = loose - fi;
            left -= pivot - fix;
            ans.emplace_back(fix, 1);
            ans.emplace_back(pivot, -1);
            fix = pivot;
            loose = pivot - fi;
        } else {
            ll pivot = loose + fi;
            left -= fix - pivot;
            ans.emplace_back(pivot, 1);
            ans.emplace_back(fix, -1);
            fix = pivot;
            loose = pivot + fi;
        }
    }
    if (fix < loose) {
        ans.emplace_back(fix, 1);
        ans.emplace_back(fix + left, -1);
    } else {
        ans.emplace_back(fix - left, 1);
        ans.emplace_back(fix, -1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, l;
    cin >> n >> m >> l;
    vector<ll> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    vector<ll> c(m + 2);
    c[0] = -(l - 1);
    for (int i = 1; i <= m; ++i) {
        cin >> c[i];
    }
    c[m + 1] = (l + 1);
    // vector of (position, pm 1)
    vector<pii> differences = make_diff(f, l);
    vector<ll> ans(m + 1);
    for (int i = 1; i <= m; ++i) {
        differences.emplace_back(c[i], 0);
    }
    ll cInd = 0;
    ll h = 0;
    sort(differences.begin(), differences.end());
    for (pii cur: differences) {
        ll ind = cur.first;
        ll d = cur.second;
        //cerr << ind << " " << d << "\n";
        if (cur.second == 0) {
            cInd++;
            ans[cInd] = h * (c[cInd + 1] - c[cInd]);
        } else {
            ans[cInd] += (c[cInd + 1] - ind) * d;
            h += d;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}