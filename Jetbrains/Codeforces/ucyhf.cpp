# include <bits/stdc++.h>
//https://codeforces.com/contest/171/problem/F
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/* * Description: Prime sieve for generating all primes up to a certain limit. isprime$[i]$ is true iff $i$ is a prime.*/
const int MAX_PR = 5'000'000;
bitset<MAX_PR> isprime;
vi eratosthenes_sieve(int lim) {
    isprime.set(); isprime[0] = isprime[1] = 0;
    for (int i = 4; i < lim; i += 2) isprime[i] = 0;
    for (int i = 3; i*i < lim; i += 2) if (isprime[i])
            for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
    vi pr;
    rep(i,2,lim) if (isprime[i]) pr.push_back(i);
    return pr;
}
bool isOK(int v) {
    if (isprime[v]) {
        string a = to_string(v);
        string b = to_string(v);
        reverse(a.begin(), a.end());
        if (a!=b && isprime[stoi(a)]) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    eratosthenes_sieve(4000000);
    int d;
    cin >> d;
    int count = 0;
    int v = 0;
    while(true){
        v++;
        if(isOK(v)){
            count++;
        }
        if(count ==d){
            cout << v;
            return 0;
        }
    }
    return 0;
}