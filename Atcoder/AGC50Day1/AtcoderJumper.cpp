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
    if(n==1){
        cout << 1 << " " << 1;
        return 0;
    }
    int max2 = 1;
    while (max2 < n) {
        max2 *= 2;
    }
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int v = (i * 2) % max2;
        a.push_back(v >= n ? v - max2 / 2 : v);
        b.push_back(v + 1 >= n ? v + 1 - max2 / 2 : v + 1);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] + 1 << " " << b[i] + 1 << "\n";
    }
    return 0;
}