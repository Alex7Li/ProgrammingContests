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
int f(int a, int b, int c) {
  if(a == 0) {
    if(b == 0){
      if(c == 0) {
        return 0;
      } else {
        return 1;
      }
    } else {
      if(c == 0) {
        return 1;

      } else {
        return 1;

      }
    }
  } else {
    if(b == 0){
      if(c == 0) {
        return 0;

      } else {
        return 1;

      }
    } else {
      if(c == 0) {
        return 1;

      } else {

        return 0;
      }
    }

  }
}
vector<int> simulate(vector<int>& in) {
  int n = in.size();
  vector<int> out(in.size());
  out[0] = f(0, in[0], in[1]);
  out[n - 1] = f(in[n - 2], in[n - 1], 0);
  for (int i = 1; i < in.size()-1; i++) {
    out[i] = f(in[i-1], in[i], in[i + 1]);
  }
  return out;
}
string tostr(vi& a) {
  string str = "";
  for (int i = 0; i < a.size(); i++) {
    if(a[i] == 0) {
    str.push_back('0');
    }
    else {
    str.push_back('1');
    }
  }
  return str;
}
int countones(vi& a) {
  int c = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 1) {
      c += 1;
    }
    return c;
  }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<int> st(s.size());
    if(s.size() == 1) {
      cout << s << endl;
      return 0;
    }
    for (int i = 0; i < s.size(); i++) {
      if(s[i] == '0'){
        st[i] = 0;
      } else {
        st[i] = 1;
      }
    }
    ll n;
    cin >> n;
    map<vi, int> seen;
    vi cur = st;
    int i = 0;
    vector<ll> one_counts;
    one_counts.push_back(0);
    while (seen.count(cur) == 0) {
      one_counts.push_back(one_counts[one_counts.size() - 1] + countones(cur));
      if (i == n) {
        cout << one_counts[one_counts.size() - 1] << endl;
        return 0;
      }
      seen[cur] = i++;
      cur = simulate(cur);
    }
    int cycle_st = seen[cur];
    ll one_count = one_counts[cycle_st + 1];
    int cycle_end = i;
    n -= cycle_st;
    ll cycles = n / (cycle_end - cycle_st);
    one_count += cycles * (one_counts[cycle_end + 1] - one_counts[cycle_st + 1]);
    n = n % (cycle_end - cycle_st);
    one_count += one_counts[n + cycle_st] - one_counts[cycle_st + 1];
    cout << tostr(cur) << endl;
    return 0;
}