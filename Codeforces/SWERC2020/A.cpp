#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n'
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    int k, n;
    cin >> n >> k;
    string s;
    getline(cin, s);
    map<string, pii> priority;
    for (int i = 0; i < 3 * n; i++) {
      getline(cin, s);
      if (priority.count(s)) {
        priority[s] = {priority[s].first - 1, -i};
      } else {
        priority[s] = {0, -i};
      }
    }
    map<pii, string> invP;
    vector<pii> priorities;
    for (auto x : priority) {
      invP[x.second] = x.first;
      priorities.push_back(x.second);
    }
    sort(priorities.begin(), priorities.end());
    for (int i = 0; i < min(int(priorities.size()), k); i++){
      cout << invP[priorities[i]] << "\n";
    }
    return 0;
}