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
    int k, d;
    cin >> k >> d;
    vi a(d);
    int minNonzero = 10;
    int minAll = 10;
    for (int i = 0; i < d; ++i) {
        cin >> a[i];
        minAll = min(minAll, a[i]);
        if (a[i] != 0) {
            minNonzero = min(minNonzero, a[i]);
        }
    }
    if(minNonzero == 10) {
        cout << -1;
    } else{
        cout << minNonzero;
        if(k > 1){
            for (int i = 0; i < k - 2; ++i) {
                cout << minAll;
            }
            cout << minNonzero;
        }
    }
    cout << endl;

    return 0;
}