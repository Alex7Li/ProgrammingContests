# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int query(int l, int r) {
    cout << "? " << l + 1 << " " << r << endl;
    int p;
    cin >> p;
    return p - 1;
}

void guess(int a) {
    cout << "! " << a + 1 << endl;
}

int solve(int l, int mid, int r, int lastPos) {
    if (l + 1 == r) {
        return l;
    }
    if (l + 2 == r) {
        if (lastPos == l) {
            return l + 1;
        } else {
            return l;
        }
    }
    if (l + 3 == r) {
        int nextPos = query(l, l + 2);
        if (lastPos == nextPos || lastPos == l + 2) {
            return l + 1 - nextPos;
        } else {
            return l + 2;
        }
    }
    if (lastPos >= mid) {
        int maxPosr = query(mid, r);
        if (maxPosr == lastPos) {
            return solve(mid, (mid + r) / 2, r, lastPos);
        } else {
            int maxPosl = query(l, mid);
            return solve(l, (l + mid) / 2, mid, maxPosl);
        }
    } else {// if (lastPos < mid) {
        int maxPosl = query(l, mid);
        if (maxPosl == lastPos) {
            return solve(l, (l + mid) / 2, mid, lastPos);
        } else {
            int maxPosr = query(mid, r);
            return solve(mid, (mid + r) / 2, r, maxPosr);
        }
    }
}

int main() {
    int n;
    cin >> n;
    guess(solve(0, n / 2, n, query(0, n)));
    return 0;
}