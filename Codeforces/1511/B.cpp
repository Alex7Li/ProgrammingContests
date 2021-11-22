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
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int a, b, c;
        cin >> a >> b >> c;
        int gcd = (int) (pow(10, c-1));
        int bP = (int)(pow(10, b-1));
        int aP = (int)(pow(10, a-1));
        int bV = gcd;
        int aV = gcd;
        while(bV < bP){
            bV*=3;
        }
        while(aV < aP){
            aV*=5;
        }
        cout << aV << " " << bV << "\n";
    }
    return 0;
}