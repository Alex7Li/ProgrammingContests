#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// https://martin-thoma.com/fractions-in-cpp/
class Fraction {
private:
  // Calculates the greates common divisor with
  // Euclid's algorithm
  // both arguments have to be positive
  long long gcd(long long a, long long b) {
    if (a == 0) {
      return b;
    }
    return gcd(b % a, a);
  }

public:
  long long numerator, denominator;

  Fraction() {
    numerator = 0;
    denominator = 1;
  }

  Fraction(long long n, long long d) {
    if (d == 0) {
      cerr << "Denominator may not be 0." << endl;
      exit(0);
    } else if (n == 0) {
      numerator = 0;
      denominator = 1;
    } else {
      ll sign = 1;
      if (n < 0) {
        sign *= -1;
        n *= -1;
      }
      if (d < 0) {
        sign *= -1;
        d *= -1;
      }

      long long tmp = gcd(n, d);
      numerator = n / tmp * sign;
      denominator = d / tmp;
    }
  }

  operator int() { return (numerator) / denominator; }
  operator float() { return ((float)numerator) / denominator; }
  operator double() { return ((double)numerator) / denominator; }
};

Fraction operator+(const Fraction &lhs, const Fraction &rhs) {
  Fraction tmp(lhs.numerator * rhs.denominator +
                   rhs.numerator * lhs.denominator,
               lhs.denominator * rhs.denominator);
  return tmp;
}

Fraction operator+=(Fraction &lhs, const Fraction &rhs) {
  Fraction tmp(lhs.numerator * rhs.denominator +
                   rhs.numerator * lhs.denominator,
               lhs.denominator * rhs.denominator);
  lhs = tmp;
  return lhs;
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs) {
  Fraction tmp(lhs.numerator * rhs.denominator -
                   rhs.numerator * lhs.denominator,
               lhs.denominator * rhs.denominator);
  return tmp;
}

Fraction operator-=(Fraction &lhs, const Fraction &rhs) {
  Fraction tmp(lhs.numerator * rhs.denominator -
                   rhs.numerator * lhs.denominator,
               lhs.denominator * rhs.denominator);
  lhs = tmp;
  return lhs;
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs) {
  Fraction tmp(lhs.numerator * rhs.numerator,
               lhs.denominator * rhs.denominator);
  return tmp;
}

Fraction operator*=(Fraction &lhs, const Fraction &rhs) {
  Fraction tmp(lhs.numerator * rhs.numerator,
               lhs.denominator * rhs.denominator);
  lhs = tmp;
  return lhs;
}

Fraction operator/(const Fraction &lhs, const Fraction &rhs) {
  Fraction tmp(lhs.numerator * rhs.denominator,
               lhs.denominator * rhs.numerator);
  return tmp;
}

std::ostream &operator<<(std::ostream &strm, const Fraction &a) {
  if (a.denominator == 1) {
    strm << a.numerator;
  } else {
    strm << a.numerator << "/" << a.denominator;
  }
  return strm;
}

ll get_ans(Fraction d, ll n){
  d.numerator = abs(d.numerator);
  if (d.numerator / d.denominator > n)
  {
    return 0;
  }
    else if (d.denominator == 1)
    {
      ll num = d.numerator;
      return min(2LL * n, (n - num) * 2 + 1);
    }
    else
    {
      return (n - d.numerator / d.denominator) * 2;
    }
}

ll solve(ll x1, ll y1, ll x2, ll y2, ll n) {
  if (y1 == y2) {
    return get_ans(Fraction(abs(y1), 1), n);
  }
  if (x1 == x2) {
    return get_ans(Fraction(abs(x1), 1), n);
  }
  Fraction m = Fraction(y1 - y2, x1 - x2);
  Fraction b = Fraction(y1, 1) - Fraction(x1, 1) * m;
  Fraction bByM = Fraction(y1, 1) / m - Fraction(x1, 1);
  return max(get_ans(b, n), get_ans(bByM, n));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll d = solve(x1, y1, x2, y2, n);
    cout << d << "\n";
  }

  return 0;
}