# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int time(int a, int b) {
    int t = 0;
    while (a > 0) {
        a /= b;
        t++;
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int a, b;
        cin >> a >> b;
        int best = a + 10;
        int ct = 0;
        if (b == 1) {
            b++;
            ct++;
        }
        while (time(a, b) + ct <= best) {
            best = time(a, b) + ct;
            b++;
            ct++;
        }
        cout << best << endl;
    }
    return 0;
}