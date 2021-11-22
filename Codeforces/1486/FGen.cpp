# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
    int seed;
    cin >> seed;
    srand(seed);
    int n = 16;
    cout << n << "\n";
    for (int i = 2; i <= n; i++) {
        cout << (rand() % (i-1)) + 1 << " " << i << "\n";
    }
    int p = rand() % 500;
    cout << p << endl;
    for (int i = 1; i <= p; i++) {
        cout << (rand() % n) + 1 << " " << (rand() % n) + 1 << "\n";
    }
    cout << endl;
    return 0;
}
