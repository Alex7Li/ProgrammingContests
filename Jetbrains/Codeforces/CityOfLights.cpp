# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//http://codeforces.com/gym/102465
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, inc;
    cin >> n >> k;
    vector<bool> off(n);
    int count = 0;
    int maxC = 0;
    for (int i = 0; i < k; i++){
        cin >> inc;
        for (int j = inc - 1; j < n; j+=inc) {
            if (off[j]) {
                count--;
            } else {
                count++;
            }
            off[j] = !off[j];
        }
        maxC = max(maxC, count);
    }
    cout << maxC << endl;
    return 0;
}