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
    string a, b;
    cin >> a >> b;
//    int bInd = 0;
//    for (int i = 0; i < n; ++i) {
//        while (bInd < n && b[bInd] == a[i]) {
//            bInd++;
//        }
//    }
    bool flipflop = (n + 1) % 2;
    for (int i = 0; i < n; ++i) {
        if ((a[i] == 'R') != (i + (a[0] == 'R')) % 2) {
            flipflop = false;
        }
        if ((b[i] == 'R') == (i + (a[0] == 'R')) % 2) {
            flipflop = false;
        }
    }
    int hasR = false;
    int hasB = false;
    int aD = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 'R') {
            hasR |= 1;
        } else {
            hasB |= 1;
        }
        if (b[i] == 'R') {
            hasR |= 2;
        } else {
            hasB |= 2;
        }
        if (a[i] != a[(i + 1) % n]) {
            aD++;
        }
        if (b[i] != b[(i + 1) % n]) {
            aD--;
        }
    }
    if (aD >= 0 && hasR % 3 == 0 && hasB % 3 == 0 && !flipflop) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
    return 0;
}