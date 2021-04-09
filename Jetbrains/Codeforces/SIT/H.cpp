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
    int n;
    cin >> n;
    vi t1;
    vi t2;
    rep(i, 0, n) {
        int c, t;
        cin >> c >> t;
        if (t == 1) {
            t1.push_back(c);
        } else {
            t2.push_back(c);
        }
    }
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    int p1 = 0;
    int p2 = 0;
    ll tc = 0;
    while (p1 + p2 < n) {
        if (p1 >= t1.size()) {
            if (p2 < (p1 + 1) * 2 && p2 < t2.size()) {
                tc += t2[p2];
                p2++;
                cout << tc << "\n";
            } else {
                p2++;
                cout << "-1" << "\n";
            }
        } else if (p2 >= t2.size()) {
            if (p1 < (p2 + 1) * 2 && p1 < t1.size()) {
                tc += t1[p1];
                p1++;
                cout << tc << "\n";
            } else {
                p1++;
                cout << "-1" << "\n";
            }
        } else {
            if (t1[p1] < t2[p2]) {
                if (p1 < (p2 + 1) * 2) {
                    tc += t1[p1];
                    p1++;
                    cout << tc << "\n";
                } else {
                    tc += t2[p2];
                    p2++;
                    cout << tc << "\n";
                }
            } else {
                if (p2 < (p1 + 1) * 2) {
                    tc += t2[p2];
                    p2++;
                    cout << tc << "\n";
                } else {
                    tc += t1[p1];
                    p1++;
                    cout << tc << "\n";
                }
            }
        }
    }
    return 0;
}