# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int main() {
    long long t1 = chrono::high_resolution_clock::now().time_since_epoch().count();
    srand((unsigned int)t1);
    int n = 5;
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << rand() % 100 << " " << rand() % 100 << "\n";
    }
}