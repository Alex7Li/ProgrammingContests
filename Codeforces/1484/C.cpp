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
        int n, days;
        cin >> n >> days;
        vector<vi> available(days, vi(0));
        vector<int> count(n + 1);
        rep(i, 0, days) {
            int k;
            cin >> k;
            rep(j, 0, k) {
                int next;
                cin >> next;
                available[i].push_back(next);
                count[next]++;
            }
        }
        bool possible = true;
        vector<int> used(n + 1);
        vi assignments(days, -1);
        rep(i, 0, days) {
            int choices = 0;
            trav(j, available[i]) {
                if (count[j] <= (days + 1) / 2) {
                    assignments[i] = j;
                }
                choices++;
            }
            if (choices == 1) {
                trav(j, available[i]) {
                    if (count[j] > (days + 1) / 2) {
                        if (used[j] < (days + 1) / 2) {
                            assignments[i] = j;
                            used[assignments[i]]++;
                        } else {
                            possible = false;
                        }
                    }
                }
            }
        }
        rep(i, 0, days) {
            if (assignments[i] == -1) {
                trav(j, available[i]) {
                    if (used[j] < (days + 1) / 2) {
                        assignments[i] = j;
                    }
                }
                if (assignments[i] == -1) {
                    possible = false;
                } else {
                    used[assignments[i]]++;
                }
            }
        }
        if (possible) {
            cout << "YES\n";
            rep(i, 0, days) {
                cout << to_string(assignments[i]);
                cout << ((i == days - 1) ? "\n" : " ");
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}