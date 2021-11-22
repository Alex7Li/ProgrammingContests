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
    vector<double> pTaken(n);
    for(int i = 1; i < n; i++) {
      pTaken[i] = 1.0 / (n - 1);
    }
    for(int i = 1; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        pTaken[j] += pTaken[i] / (n - i);
      }
    }
    cout << pTaken[n - 1];
    return 0;
}