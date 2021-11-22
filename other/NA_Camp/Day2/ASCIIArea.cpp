# include <bits/stdc++.h>
using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
/*
int solve(int i, int j, vector<vector<char>> v) {
    assert(v[i][j] == '/');
    assert(v[i][j + 1] == '\\');
    char cur_char = '\\';
    bool go_up = false;
    int y = i;
    int x = j + 1;
    vi xloc;
    vi yloc;
    xloc.push_back(x);
    yloc.push_back(y);
    while (!(x == i && y == j)) {
        if (cur_char == '\\' && !go_up) {
            if (v[y + 1][x + 1] == '\\') {
                x++;
                y++;
            } else {
                xloc.push_back(x + 1);
                yloc.push_back(y + 1);
                assert(v[y + 1][x + 1] == '.');
                cur_char = '/';
                if(v[y + 1][x] == '/') {
                    y++;
                }else if(v[y][x + 1] == '/') {
                    x++;
                    go_up = true;
                }
            }
        } else if(cur_char == '\\' && go_up) {
            if (v[x - 1][y - 1] == '\\') {
                x--;
                y--;
            } else {
                xloc.push_back(x);
                yloc.push_back(y);
                assert(v[x - 1][y - 1] == '.');
                cur_char = '/';
                if(v[x][y - 1] == '/') {
                    y--;
                }else if(v[x - 1][y] == '/') {
                    x--;
                    go_up = false;
                }
            }
        } else if(cur_char == '/' && !go_up){
            if (v[x - 1][y + 1] == '/') {
                x--;
                y++;
            } else {
                xloc.push_back(x);
                yloc.push_back(y + 1);
                assert(v[x - 1][y + 1] == '.');
                cur_char = '\\';
                if(v[x][y + 1] == '\\') {
                    y++;
                }else if(v[x - 1][y] == '\\') {
                    x--;
                    go_up = true;
                }
            }
        } else if(cur_char == '/' && go_up){
            xloc.push_back(x + 1);
            yloc.push_back(y);
            if (v[x + 1][y - 1] == '/') {
                x++;
                y--;
            } else {
                assert(v[x + 1][y - 1] == '.');
                cur_char = '\\';
                if(v[x + 1][y] == '\\') {
                    x++;
                    go_up = false;
                }else if(v[x][y - 1] == '\\') {
                    y--;
                }
            }
        }
    }
    int area = 0;
    int count = xloc.size();
    for (int k = 0; k < count; ++k) {
        area += xloc[k] * yloc[(k + 1) % count];
        area -= xloc[(k  + 1) % count] * yloc[k];
    }
    area /= 2;
    if(area < 0){
        area *= -1;
    }
    return area;
}
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector <vector<char>> v(h + 2, vector<char>(w + 2, '.'));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> v[i + 1][j + 1];
        }
    }
    int ans = 0;
    for (int i = 0; i - 2 < h; ++i) {
        int st = -1;
        for (int j = 0; j - 2 < w; ++j) {
            if (v[i][j] != '.') {
                if(st == -1){
                    st = j;
                } else {
                    ans += j - st;
                    st = -1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}