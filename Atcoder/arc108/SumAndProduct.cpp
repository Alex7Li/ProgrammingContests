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
    ll s, p;
    cin >> s >> p;
    for(ll i = 1; i*i <= p; i++){
        ll j = s - i;
        if(i * j == p){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}