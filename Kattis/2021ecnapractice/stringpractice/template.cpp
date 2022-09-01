// https://szkopul.edu.pl/problemset/problem/PT4yHRX9Mmz85ndhNPGCi_WB/site/?key=statement
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
bool try_length(int length, int n, vi &max_suffix) {
  bool works = true;
  int l = length;
  int last_ok = 2 * l;
  for (int j = l; j < n; j++) {
    if (j == last_ok) {
      works = false;
      break;
    }
    if (l <= max_suffix[j]) {
      last_ok = j + l + 1;
    }
  }
  return works;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  vi max_suffix(n);
  for (int i = 1; i < n; i++) {
    for (int suf = max_suffix[i - 1];; suf = max_suffix[suf - 1]) {
      if (s[i] == s[suf]) {
        max_suffix[i] = suf + 1;
        break;
      }
      if (suf == 0) {
        break;
      }
    }
  }
  vector<int> possible_lengths(1, n);
  for (int suf = max_suffix[n - 1]; suf != 0; suf = max_suffix[suf - 1]) {
    possible_lengths.push_back(suf);
  }
  reverse(possible_lengths.begin(), possible_lengths.end());
  for (int i = 0; i < n; i++) {
    if (i > 0 && possible_lengths[i] <= 2 * possible_lengths[i - 1]) {
      continue;
    }
    bool works = try_length(possible_lengths[i], n, max_suffix);
    if (works) {
      cout << possible_lengths[i] << "\n";
      break;
    }
  }
  return 0;
}
