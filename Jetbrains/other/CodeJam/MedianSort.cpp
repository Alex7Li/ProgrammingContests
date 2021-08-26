# include <bits/stdc++.h>
// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284
using namespace std;
typedef vector<int> vi;

int query(const set<int> &a) {
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl << flush;
    int x;
    cin >> x;
    if (x == -1) {
        exit(0);
    }
    return x;
}

bool answer(vi ans) {
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << endl << flush;
    int ok;
    cin >> ok;
    return ok == 1;
}

int main() {
    int t, n, q;
    cin >> t >> n >> q;
    for (int tt = 0; tt < t; tt++) {
        set<int> inds = {1, 2};
        for (int i = 3; i <= n; i++) {
            inds.insert(i);
            int x = query(inds);
            inds.erase(x);
        }
        int maxInd = *inds.begin();
        vi l(n);
        iota(l.begin(), l.end(), 1);
        stable_sort(l.begin(), l.end(), [maxInd](int i1, int i2) {
            if (i1 == maxInd || i1 == i2) {
                return false;
            }
            if (i2 == maxInd) {// i1 is less
                return true;
            }
            set<int> inds = {i1, i2, maxInd};
            int mid = query(inds);
            return mid == i2;
        });
        if (!answer(l)) {
            return 0; // we were wrong
        }
    }
    return 0;
}
