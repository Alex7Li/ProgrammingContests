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
    vector<pair<int, pii>> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
      int x, y, w;
      cin >> x >> y >> w;
      x--;
      y--;
      edges[i].second = pii(x, y);
      edges[i].first = w;
    }
    sort(edges.begin(), edges.end());
    vector<ll> pCount(n);
    queue<pair<int, ll>> pending;
    int lastC = 0;
    for(auto x : edges){
      int c = x.first;
      if(c > lastC){
        while(!pending.empty()) {
          pair<int, ll> a = pending.front();
          pending.pop();
          pCount[a.first] += a.second;
        }
      }
      lastC = c;
      pii e = x.second;
      // cout << e.first << " " << e.second << "\n";
      // cout << pCount[0] << " " << pCount[1] << " "<<pCount[2] << " " << pCount[3] << " " << pCount[4] <<"\n";
      pending.push(pair<int, ll>(e.first, pCount[e.second] + 1));
      pending.push(pair<int, ll>(e.second, pCount[e.first] + 1));
    }
    while(!pending.empty()) {
      pair<int, ll> a = pending.front();
      pending.pop();
      pCount[a.first] += a.second;
    }
    ll totalW = 0;
    for (int i = 0; i < pCount.size(); i++) {
      totalW += pCount[i];
    }
    cout << totalW << "\n";
    return 0;
}