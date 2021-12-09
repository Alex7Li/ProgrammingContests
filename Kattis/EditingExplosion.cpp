// https://open.kattis.com/contests/nac20open/problems/editingexplosion
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int levD(string a, string b) {
  vector<vi> table(a.size() + 1, vi(b.size() + 1, a.size() + b.size()));
  for (int i = 0; i <= a.size(); i++) {
    table[i][0] = i;
  }
  for (int i = 0; i <= b.size(); i++) {
    table[0][i] = i;
  }
  for (int i = 1; i <= a.size(); i++) {
    for (int j = 1; j <= b.size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        // just concat
        table[i][j] = table[i - 1][j - 1];
      }
      // add or remove letter
      table[i][j] = min(table[i][j], table[i - 1][j] + 1);
      table[i][j] = min(table[i][j], table[i][j - 1] + 1);
      // edit letter
      table[i][j] = min(table[i][j], table[i - 1][j - 1] + 1);
    }
  }
  return table[a.size()][b.size()];
}
const ll MOD = 998'244'353;

ll solve(string s, int d) {
  map<char, int> letterCounts;
  for (char a : s) {
    letterCounts[a] = 1;
  }
  letterCounts['0'] = 26 - letterCounts.size();
  map<vi, int> states;
  int n = s.size();
  vi emptyStrState(n + 1);
  iota(emptyStrState.begin(), emptyStrState.end(), 0);
  ll equalCount = 0;
  if (emptyStrState[s.size()] == d) {
    equalCount++;
  }
  states[emptyStrState] = 1;
  for (int strLen = 1; strLen <= n + d; strLen++) {
    map<vi, int> next_states;
    for (auto p : states) {
      vi curState = p.first;
      int stateCount = p.second;
      for (auto l : letterCounts) {
        char letter = l.first;
        ll letterCount = l.second;
        // create next state if this is the next letter in the dp
        vi nextState(n + 1, d + 1);
        nextState[0] = strLen;
        for (int j = 1; j <= n; j++) {
          if (letter == s[j - 1]) {
            // just concat
            nextState[j] = curState[j - 1];
          }
          // add or remove letter
          nextState[j] = min(nextState[j], curState[j] + 1);
          nextState[j] = min(nextState[j], nextState[j - 1] + 1);
          // edit letter
          nextState[j] = min(nextState[j], curState[j - 1] + 1);
        }
        // update add this state to the possible next states
        if (next_states.count(nextState) == 0) {
          next_states[nextState] = (stateCount * letterCount) % MOD;
        } else {
          next_states[nextState] =
              (next_states[nextState] + stateCount * letterCount) % MOD;
        }
      }
    }
    states = next_states;
    for (auto p : states) {
      vi curState = p.first;
      int stateCount = p.second;
      if (curState[curState.size() - 1] == d) {
        equalCount = (equalCount + stateCount) % MOD;
      }
    }
  }
  return equalCount;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int d;
  cin >> d;
  cout << solve(s, d) << endl;
  return 0;
}