# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    int x;
    cin >> x;
    srand(x);
    int t = 21;
    cout << t << endl; // t
    for (int tt = 0; tt < t; ++tt) {
        vi primes = {2, 3, 5, 7, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};
        int n = 1 + rand() % (primes.size() - 1);
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << primes[i] << " " << 1 + rand() % 20 << endl;
        }
    }
    return 0;
}