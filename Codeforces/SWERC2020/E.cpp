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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    int max_cakes = 10000;
    for (size_t i = 0; i < n; i++)
    {
      cin >> a[i];
      cin >> b[i];
      max_cakes = min(max_cakes, b[i] / a[i]);
    }
    cout << max_cakes;

    return 0;
}