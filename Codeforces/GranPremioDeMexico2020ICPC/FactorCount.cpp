# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void factor(set<int> &factors, int n) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.insert(i);
            n /= i;
        }
    }
    factors.insert(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        set<int> factors;
        factor(factors, a);
        factor(factors, b);
        factors.erase(1);
        cout << factors.size() << "\n";
    }
    return 0;
}