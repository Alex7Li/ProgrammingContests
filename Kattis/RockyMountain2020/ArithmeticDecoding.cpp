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
    int N;
    cin >> N;
    int d;
    cin >> d;
    string msg;
    cin >> msg;
    double message = 0;
    for (unsigned int i = msg.size() - 1; i >= 2; --i) {
        message += msg[i] - '0';
        message /= 2;
    }
    for (int i = 0; i < 1 << N; ++i) {
        double l = 0;
        double r = 1;
        for (int j = 0; j < N; ++j) {
            double c = l + (d / 8.0) * (r - l);
            if (i & (1 << j)) {
                // A
                r = c;
            } else {
                // B
                l = c;
            }
        }
        if (l == message) {
            for (int j = 0; j < N; ++j) {
                if (i & (1 << j)) {
                    cout << "A";
                } else {
                    cout << "B";
                }
            }
            cout << "\n";
            exit(0);
        }
    }
    return 0;
}