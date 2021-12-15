// https://open.kattis.com/problems/stringmatching
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
  string pattern, text;
  for (getline(cin, pattern); pattern != ""; getline(cin, pattern)) {
    getline(cin, text);
    auto it = text.find(pattern, 0);
    if (it != string::npos) {
      cout << it;
    }
    do {
      it = text.find(pattern, it + 1);
      if (it != string::npos) {
        cout << " " << it;
      }
    } while (it != string::npos);
    cout << "\n";
  }
  return 0;
}
