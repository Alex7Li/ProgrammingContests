# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;

vector<int> divisors(int a) {
    vector<int> d;
    int i = 1;
    for (; i * i < a; i++) {
        if (a % i == 0) {
            d.push_back(i);
            d.push_back(a / i);
        }
    }
    if (i * i == a) {
        d.push_back(i);
    }
    return d;
}

int MAX = 20'000'007;
vector<int> nPrimeFactors(MAX, 0);

void setPrimes() {
    for (int i = 2; i < MAX; i++) {
        if (nPrimeFactors[i] == 0) {
            for (int j = i; j < MAX; j += i) {
                nPrimeFactors[j]++;
            }
        }
    }
}


int main() {
    setPrimes();
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int c, d, x;
        cin >> c >> d >> x;
        ll count = 0;
        vector<int> xDiv = divisors(x);
        trav(D, xDiv) {
            if ((d + x / D) % c == 0) {
                int e = (d + x / D) / c;
                count += 1LL << nPrimeFactors[e];
            }
        }
        cout << count << "\n";
    }
    return 0;
}