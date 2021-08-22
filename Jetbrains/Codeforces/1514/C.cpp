# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b % a, a);
}

vector<int> cop(int n) {
    vector<int> ans = {1};
    ll p = 1;
    for (int i = 2; i < n; ++i) {
        if (gcd(i, n) == 1) {
            p = (p * i) % n;
            ans.push_back(i);
        }
    }
    if (p == 1) {
        ans.push_back(1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> ans = cop(n);
    cout << ans.size() - 1 << "\n";
    for (int i = 0; i < ans.size() - 1; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}