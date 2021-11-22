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
    int m1 = 0;
    int m2 = 0;
    int i1 = 0;
    int i2 = 0;
    rep(i, 0, 1 << n) {
        int x;
        cin >> x;
        if (i >= 1 << (n - 1)) {
            if(x > m1) {
                m1 = x;
                i1 = i;
            }
        } else {
            if(x > m2){
                m2 = x;
                i2 = i;
            }
        }
    }
    cout << (m1 > m2 ? i2 : i1) + 1;
    return 0;
}