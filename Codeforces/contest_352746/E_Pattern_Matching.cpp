/*
ds: given a string, get the indicies of all patterns that it matches.

abcd 4 [1, [4], 5] => 4 comes before 1, 5
abba 2 [[2], 4] => 2 comes before 4
dbcd 5 [1, [5]] => 5 comes before 1
_b_d
__b_
aaaa
ab__
_bcd
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi topoSort(const vector<vi> &gr) {
  vi indeg(sz(gr)), ret;
  for (auto &li : gr)
    for (int x : li)
      indeg[x]++;
  queue<int> q; // use priority_queue for lexic. largest ans.
  rep(i, 0, sz(gr)) if (indeg[i] == 0) q.push(i);
  while (!q.empty()) {
    int i = q.front(); // top() for priority queue
    ret.push_back(i);
    q.pop();
    for (int x : gr[i])
      if (--indeg[x] == 0)
        q.push(x);
  }
  return ret;
}

unordered_map<string, int> patterns;
int k;
void addPattern(string pattern, int ind) { patterns.insert({pattern, ind}); }

vector<int> getMatches(string str) {
  // there are only 2^4 possible patterns that we can match.
  vector<int> v;
  for (int i = 0; i < 1 << k; i++)
  {
    string pat = "";
    for (int j = 0; j < k; j++) {
      if (i & (1 << j)) {
        pat += '_';
      } else {
        pat += str[j];
      }
    }
    auto p = patterns.find(pat);
    if (p != patterns.end()) {
      v.push_back(p->second);
    }
  }
  return v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    string pat;
    cin >> pat;
    addPattern(pat, i);
  }
  vector<vi> gr(n);
  bool possible = true;
  for (int i = 1; i <= m; i++) {
    string s;
    int val;
    cin >> s >> val;
    val--;
    vi a = getMatches(s);
    // val must be in a
    bool hasVal = false;
    for (int aval : a) {
      if (val == aval) {
        hasVal = true;
      } else {
        gr[val].push_back(aval);
      }
    }
    if (!hasVal) {
      possible = false;
    }
  }
  // sorted[0] only has edges out.
  // sorted[0] contains the string which should come first
  // in the order.
  vi sorted = topoSort(gr);
  if (sorted.size() < n) {
    possible = false;
  }
  if (possible) {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      cout << sorted[i] + 1 << " ";
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}