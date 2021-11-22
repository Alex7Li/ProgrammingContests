# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> factor(int n) {
    vector<pii> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int pow = 0;
            for (; n % i == 0; n /= i, pow++) {
            }
            factors.push_back(pii(i, pow));
        }
    }
    if (n != 1) {
        factors.push_back(pii(n, 1));
    }
    return factors;
}

void pushAll(vector<pii> &factors, vector<int> &a, int ind, int prod) {
    if (ind == -1) {
        a.push_back(prod);
    } else {
        ll pow = 1;
        for (int i = 0; i <= factors[ind].second; i++) {
            pow *= factors[ind].first;
        }
        for (int i = factors[ind].second; i >= 0; i--) {
            pow /= factors[ind].first;
            if (i == 0 && prod == 1) {
                continue;
            }
            pushAll(factors, a, ind - 1, prod * pow);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 0, t) {
        int n;
        cin >> n;
        vector<pii> factors = factor(n);
        vector<int> a(0);
        for (int i = 0; i < factors.size(); i++) {
            vector<int> inds(i);
            pushAll(factors, a, i, 1);
        }
        swap(a[a.size() - 1], a[a.size() - 2]);
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        if (factors.size() == 2 && factors[0].second == factors[1].second && factors[0].second == 1) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}