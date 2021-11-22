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
    int n, a, b;
    cin >> n >> b >> a;
    string s;
    cin >> s;
    vector<int> ap;
    vector<int> bp;
    for (int i = 0; i < n; i++) {
        if (i != n - 1 && s[i] == '0' && s[i + 1] == '0' && b > 0) {
            b--;
            bp.push_back(i);
            i++;
        } else if (s[i] == '0' && a > 0) {
            a--;
            ap.push_back(i);
        }
    }
    if (a == 0 && b == 0) {
        cout << "YES" << "\n";
        for (int i = 0; i < bp.size(); i++) {
            cout << bp[i] + 1<< " " << bp[i] + 2 << "\n";
        }
        for (int i = 0; i < ap.size(); i++) {
            cout << ap[i] + 1<< "\n";
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}