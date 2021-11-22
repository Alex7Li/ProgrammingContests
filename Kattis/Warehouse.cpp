# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//https://open.kattis.com/problems/warehouse
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<pair<int, string>> toys;
        for (int i = 0; i < n; i++) {
            int num;
            string name;
            cin >> name >> num;
            bool upd = false;
            for (int j = 0; j < toys.size(); j++) {
                if (toys[j].second == name) {
                    toys[j].first -= num;
                    upd = true;
                    break;
                }
            }
            if (!upd) {
                toys.push_back(make_pair(-num, name));
            }
        }
        sort(toys.begin(), toys.end());
        cout << toys.size() << "\n";
        for(auto i = toys.begin(); i!= toys.end(); i++){
            cout << i->second << " " << -i->first << "\n";
        }
    }
    return 0;
}