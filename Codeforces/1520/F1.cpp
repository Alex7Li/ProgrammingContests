# include <bits/stdc++.h>

using namespace std;
int n;

// zeros in  [l, r)
int nZeros(int l, int r) {
    if (l >= r) {
        return 0;
    }
    if (r > n) {
        r = n;
    }
    cout << "? " << l + 1 << " " << r << endl << flush;
    int count = 0;
    cin >> count;
    int ret = (r - l) - count;
    return ret;
}

void guess(int x) {
    cout << "! " << (x + 1) << endl << flush;
}

int main() {
    int t;
    cin >> n >> t;
    vector<int> counts;
    for (int i = 0; i < t; ++i) {
        int k;
        cin >> k;
        int hi = n;
        for (int step = 1 << (int)log2(n); step; step /= 2) {
            if (nZeros(0, hi - step) >= k) {
                hi -= step;
            }
            cerr << hi << " " << step << "\n";
        }
        guess(hi - 1);
    }
    return 0;
}
