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
    for(int tt = 0; tt < t; tt++){
        int n;
        cin >> n;
        vi a(n);
        vi d(n, -1);
        ll sum = 0;
        rep(i,0,n){
            cin >> a[i];
            sum += a[i];
        }
        rep(i, 0, n-1){
            int x, y;
            cin >> x >> y;
            d[x-1]++;
            d[y-1]++;
        }
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        stable_sort(idx.begin(), idx.end(),
                    [&a](size_t i1, size_t i2) {return a[i1] > a[i2];});
        cout << sum;
        int ind = 0;
        rep(i, 0, n - 2){
            while(d[idx[ind]] == 0){
                ind++;
            }
            sum += a[idx[ind]];
            d[idx[ind]]--;
            cout << " " << sum;
        }
        cout << "\n";
    }
    return 0;
}