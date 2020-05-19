# include <bits/stdc++.h>
//https://codeforces.com/contest/1270/problem/E
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int gcd(int a, int b){
    return a==0? b:gcd(b%a, a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    scanf("%i", &n);
    vector<int> x = vector<int>(n, 0);
    vector<int> y = vector<int>(n, 0);
    int xgcd = 0;
    int ygcd = 0;
    vector<int> A = vector<int>();
    rep(i, 0, n) {
        scanf("%i", &x[i]);
        scanf("%i", &y[i]);
        xgcd = gcd(xgcd, x[i] - x[0]);
        ygcd = gcd(ygcd, y[i] - y[0]);
    }
    if (xgcd != 0 && ygcd != 0) {
        for (int i = n - 1; i >= 0; i--) {
            x[i] -= x[0];
            y[i] -= y[0];
            if ((x[i] / xgcd + y[i] / ygcd) % 2 == 0) {
                A.push_back(i);
            }
        }
    }
    if(A.size()==0 || A.size() == n){
        A.clear();
        rep(i, 0, n) {
            if (xgcd == 0) {
                if (y[i] / ygcd % 2 == 0) {
                    A.push_back(i);
                }
            } else {
                if (x[i] / xgcd % 2 == 0) {
                    A.push_back(i);
                }
            }
        }
    }
    cout << A.size() << "\n" << A[0]+1;
    rep(i, 1, A.size()){
        cout << " " << A[i]+1;
    }
    return 0;
}