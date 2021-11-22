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
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        int s1 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s1 += a[i];
        }
        int s2 = 0;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            s2 += b[i];
        }
        if (s1 != s2) {
            cout << -1 << "\n";
        } else {
            vi sub;
            vi add;
            for (int i = 0; i < n; ++i) {
                while(a[i] < b[i]){
                    add.push_back(i + 1);
                    a[i]++;
                }
                while(a[i] > b[i]){
                    sub.push_back(i + 1);
                    a[i]--;
                }
            }
            assert(sub.size() == add.size());
            cout << add.size() <<"\n";
            for (int i = 0; i < add.size(); ++i) {
                cout << sub[i] << " " << add[i] << "\n";
            }
        }

    }
    return 0;
}