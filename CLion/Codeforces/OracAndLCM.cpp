# include <bits/stdc++.h>
//http://codeforces.com/contest/1349/problem/A
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> primeSieve(int M) {
    vector<bool> isPrime(M + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= M; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= M; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 0; i <= M + 1; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vector<int> primes = primeSieve(200'000);
    ll ans = 1;
    for (int i = 0; i < primes.size(); i++) {
        bool powOK = true;
        ll val = 1;
        while (powOK) {
            int missed = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] % (val * primes[i]) != 0) {
                    missed++;
                }
                if (missed >= 2) {
                    powOK = false;
                    break;
                }
            }
            if (missed < 2) {
                val *= primes[i];
            }
        }
        ans *= val;
    }
    cout << ans << "\n";
    return 0;
}