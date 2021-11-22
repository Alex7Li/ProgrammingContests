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
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vi b(n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            b[i] = a[n / 2 + i / 2];
        } else {
            b[i] = a[i / 2];
        }
    }
    int score = 0;
    for (int i = 1; i < n - 1; i++) {
        if (b[i] < b[i - 1] && b[i] < b[i + 1]) {
            score++;
        }
    }
    cout << score << "\n" << b[0];
    for (int i = 1; i < n; i++) {
        cout << " " << b[i];
    }
    return 0;
}