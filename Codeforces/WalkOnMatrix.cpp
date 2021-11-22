# include <bits/stdc++.h>
//http://codeforces.com/contest/1332/problem/D
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    cout << 2 << " " << 4 << endl;
    cout << (1 << 18) - 1 << " " << k << " " << 0 << " " << 0 << endl;
    cout << (1 << 17) << " " << (1<< 18) - 1 << " "<< (1<< 17) - 1 << " "  << k << endl;
    return 0;
}