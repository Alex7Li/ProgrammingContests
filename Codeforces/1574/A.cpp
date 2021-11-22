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
    int n_tests;
    cin >> n_tests;
    for(int cur_test = 1; cur_test <= n_tests; cur_test++) {
        
    int n;
    cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "(";
        }
        for (int j = 0; j < i; j++)
        {
            cout << ")";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "()";
        }
        cout << endl;
    }
    }
    
    return 0;
}