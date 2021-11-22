# include <bits/stdc++.h>
//https://codeforces.com/contest/1479/problem/C
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, r;
    cin >> l >> r;
    cout << "YES" << "\n";
    int d = r - l + 1;
    int pow;
    for (pow = 0; (1 << pow) <= d; pow++) {}
    int n = pow + 2;
    vector<string> edges;
    for (int i = 1; i < n; i++) {
        edges.push_back("1 " + to_string(i + 1) + " " + to_string(l));
    }
    for (int i = 0; i < pow - 1; i++) {
        int ind = n - i - 2;
        for (int j = ind + 1; j < n; j++) {
            edges.push_back(to_string(ind + 1) + " " + to_string(j + 1) + " " + to_string(1 << i));
        }
    }
    int extra = (1 << (pow - 1));
    d -= extra;
    while (d != 0) {
        for (pow = 0; (1 << pow) <= d; pow++) {}
        pow--;
        edges.push_back("2 " + to_string(n - pow - 1) + " " + to_string(extra - (1 << pow)));
        extra += (1 << pow);
        d -= (1 << pow);
    }
    cout << n << " " << edges.size() << "\n";
    trav(a, edges) {
        cout << a << "\n";
    }
    return 0;
}