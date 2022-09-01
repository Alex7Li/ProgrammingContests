#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
bool more_crew(int a, int b, int c) {
  a++;
  b++;
  c++;
  cout << "? " << a << " " << b << " " << c << endl;
  int x;
  cin >> x;
  return (bool)x;
}
void guess(vi &roles) {
  vi bad;
  for (int i = 0; i < roles.size(); i++) {
    if (roles[i] == 0) {
      bad.push_back(i + 1);
    }
  }
  cout << "! " << bad.size();
  for (int i = 0; i < bad.size(); i++) {
    cout << " " << bad[i];
  }
  cout << endl;
}

// B is bad, G is good, exactly one of g1/g2 are good.
// at least 1 of b1, b2 are bad
pii check2(int G, int g1, int g2, int B, int b1, int b2, vi &ans) {
  ans[B] = 0;
  ans[G] = 1;
  ans[b1] = more_crew(G, B, b1);
  ans[b2] = more_crew(G, B, b2);
  ans[g1] = more_crew(G, B, g1);
  ans[g2] = 1 - ans[g1];
  return {G, B};
}

// if z=1, assume at most 1 of {b1, b2, b3} are bad instead
void atmost1good(int G, int b1, int b2, int b3, vi &ans, int z) {
  if (z ^ more_crew(G, b1, b2)) {
    // b1 or b2 is 1
    if (z ^ more_crew(G, b2, b3)) {
      // b2 or b3 is 1, so b2 is 1
      ans[b1] = z ^ 0;
      ans[b2] = z ^ 1;
      ans[b3] = z ^ 0;
    } else {
      // b2 and b3 are both 0
      ans[b1] = z ^ 1;
      ans[b2] = z ^ 0;
      ans[b3] = z ^ 0;
    }
  } else {
    // b1 and b2 are both bad
    ans[b1] = z ^ 0;
    ans[b2] = z ^ 0;
    ans[b3] = more_crew(b1, G, b3);
  }
}

// 2+ of g are good(1), 2+ of bad are bad(0)
// return (def good, def bad)
pii check(int g1, int g2, int g3, int b1, int b2, int b3, vi &ans) {
  int G;
  int B;
  if (more_crew(b1, g1, g2)) {
    if (more_crew(b2, g1, g2)) {
      ans[g1] = 1;
      ans[g2] = 1;
      G = g1;
      if (more_crew(b1, G, g3)) {
        if (more_crew(b2, G, g3)) {
          ans[g3] = 1;
          atmost1good(G, b1, b2, b3, ans, 0);
          B = ans[b1] ? b2 : b1;
        } else {
          ans[g3] = 0;
          B = g3;
          ans[b1] = more_crew(G, B, b1);
          ans[b2] = 0;
          ans[b3] = more_crew(G, B, b3);
        }
      } else {
        ans[b1] = 0;
        ans[g3] = 0;
        B = b1;
        ans[b2] = more_crew(G, B, b2);
        ans[b3] = more_crew(G, B, b3);
      }
    } else {
      return check2(g3, g1, g2, b2, b1, b3, ans);
    }
  } else {
    return check2(g3, g1, g2, b1, b2, b3, ans);
  }
  return {G, B};
}

int main() {
  int n_tests;
  cin >> n_tests;
  for (int cur_test = 1; cur_test <= n_tests; cur_test++) {
    int n;
    cin >> n;
    vi groups(n / 3);
    int crewG = -1;
    int impG = -1;
    for (int i = 0; i < n; i += 3) {
      groups[i / 3] = more_crew(i, i + 1, i + 2);
      if (groups[i / 3]) {
        crewG = i;
      } else {
        impG = i;
      }
    }
    vi ans(n, -1);
    pii al = check(crewG, crewG + 1, crewG + 2, impG, impG + 1, impG + 2, ans);
    // vi t = {a1.second, al.first}
    int G = al.first;
    int B = al.second;
    for (int i = 0; i < ans.size(); i += 3) {
      if (ans[i] == -1) {
        atmost1good(groups[i/3] ? B : G, i, i + 1, i + 2, ans, groups[i/3]);
      }
    }
    guess(ans);
  }
  return 0;
}