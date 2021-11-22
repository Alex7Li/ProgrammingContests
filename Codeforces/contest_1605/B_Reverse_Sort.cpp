#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    int zC = 0;
    string s;
    cin >> s;
    vi x;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        zC += 1;
      }
    }
    for (int i = 0; i < zC; i++) {
      if (s[i] == '1') {
        x.push_back(i);
      }
    }
    for (int i = zC; i < n; i++) {
      if (s[i] == '0') {
        x.push_back(i);
      }
    }
    if (x.size() == 0) {
      cout << "0\n";
    } else {
      cout << "1\n";
      cout << x.size();
      for (int b : x) {
        cout << " " << (b + 1);
      }
      cout << "\n";
    }
  }
  return 0;
}