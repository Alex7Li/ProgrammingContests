# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, m;
        cin >> n >> m;
        vi a(n);
        rep(i, 0, n) {
            cin >> a[i];
            a[i] = a[i] % m;
        }
        sort(a.begin(), a.end());
        int count = 0;
        int end = a.size() - 1;
        int st = 0;
        while (st <= end && a[st] == 0) {
            st++;
            count = 1;
        }
        for (int i = st; i <= end; i++) {
            while (i < end && a[i] + a[end] > m) {
                count++;
                end--;
            }
            if (a[i] + a[end] == m) {
                int c1 = 1, c2 = 1;
                while (i < end && a[i] == a[i + 1]) {
                    i++;
                    c1++;
                }
                while (i < end && a[end] == a[end - 1]) {
                    end--;
                    c2++;
                }
                if (i == end) {
                    count += 1;
                } else {
                    int together = min(c1, c2) * 2 + 1;
                    int intervals = c1 + c2 - together + 1;
                    count += max(1, intervals);
                }
                end--;
            } else {
                count++;
            }
        }
        cout << max(1, count) << endl;
    }
    return 0;
}