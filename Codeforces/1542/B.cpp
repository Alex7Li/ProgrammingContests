# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool test(int n, int a, int i) {
    int pow = n / i;
    while (pow > 0 && a > 1 && pow % a == 0) {
        pow /= a;
    }
    return pow == 1;
}

// Check if base^p = residue mod M
//bool haslog(ll base, ll M, ll residue) {
//    set<int> seen;
//    ll bp = base % M;
//    residue %= M;
//    while(seen.find(bp) == seen.end()) {
//        if (bp == residue) {
//            return true;
//        }
//        seen.insert(bp);
//        bp = (bp * base) % M;
//    }
//    return false;
//    }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, a, b;
        cin >> n >> a >> b;
        bool pos = false;
        ll p = 1;
        while (p <= n) {
            if ((p - n) % b == 0) {
                pos = true;
            }
            p *= a;
            if(a==1){
                break;
            }
        }
        cout << (pos ? "Yes" : "No") << endl;
    }
    return 0;
}