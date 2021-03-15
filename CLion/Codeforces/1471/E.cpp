# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solve(int pos) {
    cout << "! " << (pos + 1) << endl;
}

int query(int pos) {
    cout << "? " << (pos + 1) << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    int turn = 0;
    int pos = 0;
    int q = query(pos);
    while (q == k) {
        pos += turn++;
        q = query(pos);
    }
    int minInd = pos - min(turn, (n - 1) / 2);
    int maxInd = pos + min(turn, (n - 1) / 2);
    if (q < k) {
        minInd = pos + 1;
    } else {
        maxInd = pos - 1;
    }
    if (minInd < 0) {
        minInd += n;
        maxInd += n;
    }
    while (true) {
        int mid = (minInd + maxInd) / 2;
        q = query(mid % n);
        if (q == k) {
            solve(mid % n);
            return 0;
        } else if (q < k) {
            minInd = mid + 1;
        } else {
            maxInd = mid - 1;
        }
    }
}