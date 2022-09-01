#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define dbg(x) cerr << ">>> " << #x << " = " << x << '\n';
#define _ << " _ " <<
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int map1(int loc) {
  switch (loc) {
    case 4:
      return 12;
    case 12:
      return 19;
    case 19:
      return 4;

    case 1:
      return 2;
    case 2:
      return 6;
    case 6:
      return 1;

    case 3:
      return 11;
    case 11:
      return 10;
    case 10:
      return 3;

    case 5:
      return 7;
    case 7:
      return 20;
    case 20:
      return 5;

    case 8:
      return 21;
    case 21:
      return 18;
    case 18:
      return 8;

    case 9:
      return 13;
    case 13:
      return 25;
    case 25:
      return 9;

    case 14:
      return 26;
    case 26:
      return 17;
    case 17:
      return 14;

    case 22:
      return 30;
    case 30:
      return 16;
    case 16:
      return 22;

    case 23:
      return 28;
    case 28:
      return 29;
    case 29:
      return 23;

    case 15:
      return 27;
    case 27:
      return 24;
    case 24:
      return 15;
    default:
      assert(false);
      return -1;
  }
}
int map2(int loc) {
  switch (loc) {
    case 1:
      return 2;
    case 2:
      return 3;
    case 3:
      return 4;
    case 4:
      return 5;
    case 5:
      return 1;

    case 6:
      return 7;
    case 7:
      return 8;
    case 8:
      return 9;
    case 9:
      return 10;
    case 10:
      return 6;

    case 11:
      return 13;
    case 13:
      return 15;
    case 15:
      return 17;
    case 17:
      return 19;
    case 19:
      return 11;

    case 12:
      return 14;
    case 14:
      return 16;
    case 16:
      return 18;
    case 18:
      return 20;
    case 20:
      return 12;

    case 21:
      return 22;
    case 22:
      return 23;
    case 23:
      return 24;
    case 24:
      return 25;
    case 25:
      return 21;

    case 26:
      return 27;
    case 27:
      return 28;
    case 28:
      return 29;
    case 29:
      return 30;
    case 30:
      return 26;
    default:
      assert(false);
      return -1;
  }
}

vector<int> apply(vector<int>& orig, int type) {
  vector<int> newV(orig.size());
  for (unsigned int i = 0; i < orig.size(); i++) {
    if (type == 0) {
      newV[i] = map1(orig[i]);
    } else {
      newV[i] = map2(orig[i]);
    }
  }
  return newV;
}

int path_result(int to) {
  int position = 1;
  while (to > 1) {
    if (to % 2 == 0) {
      position = map1(position);
    } else {
      position = map2(position);
    }
    to /= 2;
  }
  return position;
}

vector<int> get_order(int to) {
  vi order = {};
  if (to > 30) {
    order = {0, 1, 1, 1, 1};
    to -= 30;
  }
  int path = 1;
  for (; path_result(path) != to; path++)
    ;
  while (path > 1) {
    order.push_back(path % 2);
    path /= 2;
  }
  return order;
}

vector<int> apply_order(vector<int> orig, vector<int> order) {
  for (int t : order) {
    orig = apply(orig, t);
  }
  return orig;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> orders;
  for (int i = 1; i <= 60; i++) {
    orders.push_back(get_order(i));
  }
  int n1, n2, n3;
  cin >> n1;
  vi a1(n1);
  for (int i = 0; i < n1; i++) {
    cin >> a1[i];
  }
  cin >> n2;
  vi a2(n2);
  for (int i = 0; i < n2; i++) {
    cin >> a2[i];
  }
  cin >> n3;
  vi a3(n3);
  for (int i = 0; i < n3; i++) {
    cin >> a3[i];
  }
  if (n1 + n2 + n3 == 30) {
    for (int i = 0; i < 60; i++) {
      for (int j = 0; j < 60; j++) {
        vector<int> b2 = apply_order(a2, orders[i]);
        vector<int> b3 = apply_order(a3, orders[j]);
        assert(b2[0] == i % 30 + 1);
        assert(b3[0] == j % 30 + 1);
        set<int> ok;
        for (int x : a1) {
          ok.insert(x);
        }
        for (int x : b2) {
          ok.insert(x);
        }
        for (int x : b3) {
          ok.insert(x);
        }
        if (ok.size() == 30) {
          cout << "Yes\n";
          return 0;
        }
      }
    }
  }
  cout << "No\n";
  return 0;
}