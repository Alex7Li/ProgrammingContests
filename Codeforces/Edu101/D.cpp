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
    vi seq = {2, 3, 5, 22, 448};
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vi ax;
        vi ay;
        int lastVal = n;
        int lastInd = n - 1;
        while (1 < lastInd) {
            if (lastVal == 3 && lastInd == 3) {
                ax.push_back(3);
                ay.push_back(n);
                lastInd--;
            }
            if (lastInd == 2) {
                assert(2 <= lastVal && lastVal <= 4);
                ax.push_back(n);
                ay.push_back(2);
                ax.push_back(2);
                ay.push_back(n);
                break;
            }
            int st = sqrt(lastVal);
            for (int i = st + 1; i <= lastInd; i++) {
                ax.push_back(i);
                ay.push_back(n);
            }
            lastInd = st;
            ax.push_back(n);
            ay.push_back(st);
            lastVal = (lastVal + st - 1) / st;
        }
        vi test(n + 1);
        rep(i, 1, n + 1) {
            test[i] = i;
        }
        cout << ax.size() << "\n";
        rep(i, 0, ax.size()) {
            cout << ax[i] << " " << ay[i] << endl;
            test[ax[i]] = (test[ax[i]] + test[ay[i]] - 1) / test[ay[i]];
        }
        rep(i, 1, n + 1) {
           // cerr << test[i] << " ";
        }
    }
    return 0;
}
