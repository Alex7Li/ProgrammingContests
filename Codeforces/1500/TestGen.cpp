# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int seed;
    cin >> seed;
    srand(seed);
    int n = rand() % 5 + 1;
    int m = rand() % 5 + 1;
    int k = rand() % 10;
    cout << n << " " <<  m << " " << k << "\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
    }
    cout << '\n';
    set<int> used;
    int max = n + m + 1;
    for (int i = 0; i < m; i++) {
        int r = rand() % max + 1;
        while (used.find(r) != used.end()) {
            r = rand()%max + 1;
        }
        used.insert(r);
        cout << r << " ";
    }
    cout << '\n';
    return 0;
}