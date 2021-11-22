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

void updateCounts(vector<int> &counts, int add1Ind) {
    int st = add1Ind / 16;
    for (int i = st + 1; i < counts.size(); i++) {
        counts[i]--;
    }
}

int main() {
    int t;
    cin >> n >> t;
    vector<int> counts;
    for (int i = 0; i < t; ++i) {
        int k;
        cin >> k;
        if (i == 0) {
            counts.push_back(0);
            for (int j = 16; j < n; j += 16) {
                counts.push_back(nZeros(0, j));
            }
            counts.push_back(nZeros(0, n));
        }
        int hi = 0;
        for (int j = 1; j < counts.size(); ++j) {
            if (counts[j] >= k) {
                hi = j * 16;
                break;
            }
        }
        for (int step = 8; step; step /= 2) {
            // cerr << 0 << " " << hi << " " << step << "\n";
            if (nZeros(0, hi - step) >= k) {
                hi -= step;
            }
        }
        guess(hi - 1);
        updateCounts(counts, hi - 1);
    }
    return 0;
}
