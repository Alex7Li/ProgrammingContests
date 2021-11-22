//
// Created by alex on 8/26/21.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(std::istream::failbit);
    int n_test_cases;
    cin >> n_test_cases;
    for (int cur_test = 1; cur_test <= n_test_cases; cur_test++) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vi a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = (s[i] == '+' ^ i % 2 == 1) ? 1 : -1;
        }
        vi aSum(n + 1);
        for (int i = 0; i < n; ++i) {
            aSum[i + 1] = aSum[i] + a[i];
        }
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            int nRods = r - l + 1;
            r--;
            l--;
            if (aSum[l] == aSum[r + 1]) {
                cout << "0" << endl;
            } else {
                if (nRods % 2 == 0) {
                    cout << "2" << "\n";
                    cout << r + 1 << " ";
                    r--;
                } else {
                    cout << "1" << "\n";
                }
                int lo = l, hi = r, mid;
                while (true) {
                    mid = (hi + lo) / 2;
                    // Charge of both sides of the rod after deleting mid
                    int chargeRight = aSum[r + 1] - aSum[mid + 1];
                    int chargeLeft = aSum[mid] - aSum[l];
                    if(chargeLeft == chargeRight) {
                        break;
                    }
                    // Try to equalize the charges by shrinking the size
                    // of the segment with greater absolute magnitude charge
                    if (abs(chargeLeft) > abs(chargeRight + a[mid])) {
                        hi = mid - 1;
                    } else { lo = mid + 1; }
                }
                cout << mid + 1;
                cout << endl;
            }
        }
    }
}