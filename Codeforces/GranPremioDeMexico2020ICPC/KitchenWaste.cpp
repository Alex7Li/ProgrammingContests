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
    int n, m;
    cin >> n >> m;
    vi bread(n);
    vi oven(m);
    rep(i, 0, n){
        cin >> bread[i];
    }
    rep(i, 0, m){
        cin >> oven[i];
    }
    int ovenInd = 0;
    rep(i, 0, n){
        while(oven[ovenInd] < bread[i]){
            ovenInd++;
        }
        oven[ovenInd]-= bread[i];
    }
    int ans = 0;
    rep(i, 0, m){
        ans += oven[i];
    }
    cout << ans;
    return 0;
}