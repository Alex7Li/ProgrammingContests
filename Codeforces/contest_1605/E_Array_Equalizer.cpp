#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define N 1000004

// geeksforgeeks
int lpf[N];

// Function to calculate least
// prime factor of each number
void least_prime_factor() {
  for (int i = 2; i < N; i++)

    // If it is a prime number
    if (!lpf[i])

      for (int j = i; j < N; j += i)

        // For all multiples which are not
        // visited yet.
        if (!lpf[j])
          lpf[j] = i;
}
int mobius[N];
// Function to find the value of Mobius function
// for all the numbers from 1 to n
void Mobius() {
  least_prime_factor();

  for (int i = 1; i < N; i++) {

    // If number is one
    if (i == 1)
      mobius[i] = 1;
    else {

      // If number has a squared prime factor
      if (lpf[i / lpf[i]] == lpf[i])
        mobius[i] = 0;

      // Multiply -1 with the previous number
      else
        mobius[i] = -1 * mobius[i / lpf[i]];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Mobius();
  int n;
  cin >> n;
  vi a(n + 1);
  vi b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int n_q;
  cin >> n_q;
  vi q(n_q);
  for (int i = 0; i < n_q; i++) {
    cin >> q[i];
  }
  vi offsets(n + 1);
  b[1] = 0;
  for (int i = 1; i <= n; i++) {
    offsets[i] = b[i] - a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) {
      offsets[j] -= offsets[i];
    }
  }
  // answers to the queries
  vector<ll> ans(N);
  vi upd(N);
  ll d = 0;
  for (int i = 1; i <= n; i++)
  {
    ans[0] += abs(offsets[i]);
    if (mobius[i] != 0) {
      int x = -offsets[i] * mobius[i];
      if (x > 0) {
        d--;
        if(x < N){
          upd[x]++;
        }
      } else {
        d++;
      }
    }
  }
  for (int i = 1; i < ans.size(); i++) {
    ans[i] = ans[i - 1] + d;
    d += 2 * upd[i];
  }
  for(int i = 0; i < n_q; i++) {
    cout << ans[q[i]] << "\n";
  }
  return 0;
}