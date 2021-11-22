# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int read() {
    int a;
    cin >> a;
    return a - 1;
}

void place(int color, int i, int j) {
    cout << color + 1 << " " << i + 1 << " " << j + 1 << "\n";
    cout.flush();
}

pii white(0, 0);
pii black(1, 0);

bool placeWhite(int color, int n) {
    if (white.second >= n) {
        return false;
    }
    if (white.first + 2 < n) {
        place(color, white.first, white.second);
        white.first += 2;
    } else {
        place(color, white.first, white.second);
        white.second += 1;
        white.first = white.second % 2;
    }
    return true;
}

bool placeBlack(int color, int n) {
    if (black.second >= n) {
        return false;
    }
    if (black.first + 2 < n) {
        place(color, black.first, black.second);
        black.first += 2;
    } else {
        place(color, black.first, black.second);
        black.first = black.second % 2;
        black.second += 1;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int color = read();
        if (color == 1) {
            if (!placeWhite(0, n)) {
                placeBlack(2, n);
            }
        } else if (color == 0) {
            if (!placeBlack(1, n)) {
                placeWhite(2, n);
            }
        } else if (color == 2) {
            if (!placeWhite(0, n)) {
                placeBlack(1, n);
            }
        }
    }
    return 0;
}