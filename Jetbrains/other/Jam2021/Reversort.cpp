# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void swap(vi &a, int st, int end) {
    for (int i = 0; st + i < end - i; i++) {
        swap(a[st + i], a[end - i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int c, n;
        cin >> n >> c;
        c -= n - 1;
        int flips = 0;
        int size = n - 1;
        while (c >= size && size > -1 && c > 0) {
            flips++;
            c -= size;
            size--;
        }
        string ans = "IMPOSSIBLE";
        if (0 <= size && 0 <= c) {
            int st = n - size - 1;
            vi a(n);
            rep(i, 0, n) {
                a[i] = i + 1;
            }
            swap(a, st, st + c);
            for (int i = st - 1; i >= 0; --i) {
                swap(a, i, n - 1);
            }
            ans = to_string(a[0]);
            for (int i = 1; i < a.size(); i++) {
                ans += " " + to_string(a[i]);
            }
        }
        cout << "Case #" << tt + 1 << ": " << ans << endl;
    }
    return 0;
}