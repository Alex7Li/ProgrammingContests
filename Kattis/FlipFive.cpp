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
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int x = 0;
        int grid = 0;
        for (int i = 0; i < 3; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 3; j++) {
                if (s[j] == '*') {
                    grid += (1 << x);
                }
                x++;
            }
        }
        int best = 10;
        for (int perm = 0; perm < (1 << 9); perm++) {
            int count = 0;
            int result = 0;
            for (int i = 0; i < 9; i++) {
                if (perm & (1 << i)) {
                    count++;
                    x = i % 3;
                    int y = i / 3;
                    int delta = (1 << i);
                    if (x != 0) {
                        delta += (1 << (i - 1));
                    }
                    if(x != 2){
                        delta += (1 << (i + 1));
                    }
                    if(y!= 0){
                        delta += (1 << (i - 3));
                    }
                    if(y!= 2){
                        delta += (1 << (i + 3));
                    }
                    result ^= delta;
                }
            }
            if(result == grid){
                best = min(best, count);
            }
        }
        cout << best << "\n";
    }
    return 0;
}