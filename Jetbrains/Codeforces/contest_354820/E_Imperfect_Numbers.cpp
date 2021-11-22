#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int MAX = 1000000;
    vi ans(MAX + 1, 0);
    for(int i = 1; i <= MAX; i++) {
        for(int j = 2 * i; j <= MAX; j+= i){
          ans[j] += i;
        }
    }
    vi a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(a[i] == ans[a[i]]){
        cout << "perfect\n";
      } else if(a[i] < ans[a[i]]) {
        cout << "abundant\n";
      } else {
        cout << "deficient\n";
      }
    }
    return 0;
}