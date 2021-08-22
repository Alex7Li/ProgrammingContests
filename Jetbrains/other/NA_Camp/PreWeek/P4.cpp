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
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    int tmp;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        if(tmp != -1) {
            a.insert(tmp - i);
        }
    }
    int collision = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> tmp;
        if(tmp == -1) {
            continue;
        }
        auto p = a.find(tmp - i);
        if (p != a.end()) {
            collision++;
            a.erase(p);
        }
    }
    cout << collision << endl;
    return 0;
}