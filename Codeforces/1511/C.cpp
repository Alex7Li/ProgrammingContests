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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> top(51, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (top[a[i]] == -1) {
            top[a[i]] = i;
        }
    }
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        for (int j = 0; j <= 50; ++j) {
            if(t == j){
                cout << top[t] + 1 << " ";
            }else {
                if (top[j] < top[t]) {
                    top[j] += 1;
                }

        }
        top[t] = 0;
    }
    cout << endl;
    return 0;
}