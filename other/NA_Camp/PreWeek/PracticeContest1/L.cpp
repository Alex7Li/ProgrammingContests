# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

ll last_possible_time;
struct Command {
    char dir;
    ll dist;
};

pll last_pos(vector<Command> &commands) {
    last_possible_time = 1;
    ll stX = 0;
    ll stY = 0;
    for (Command c : commands) {
        switch (c.dir) {
            case 'u':
                stY += c.dist;
                break;
            case 'r':
                stX += c.dist;
                break;
            case 'l':
                stX -= c.dist;
                break;
            case 'd':
                stY -= c.dist;
                break;
        }
        last_possible_time += c.dist;
    }
    return {stX, stY};
}

vector<vll> latest_times(ll h, ll w, vector<Command> &commands) {
    vector<set<int>> rows(h);
    for(ll i = 0; i < h; i++){
        for(ll j = -1; j < w + 1; j++){
            rows[i].insert(j);
        }
    }
    vector<set<int>> cols(w);
    for(ll i = 0; i < w; i++){
        for(ll j = -1; j < h + 1; j++){
            cols[i].insert(j);
        }
    }
    vector<vll> last_times(w, vll(h, -1));
    pll end = last_pos(commands);
    ll curX = end.first;
    ll curY = end.second;
    ll t = last_possible_time;
    reverse(commands.begin(), commands.end());
    for (Command c: commands) {
        ll stT = t;
        switch (c.dir) {
            case 'd': // go up
                for(auto y = cols[curX].lower_bound(curY); *y < curY + c.dist; y = cols[curX].erase(y)) {
                    t = stT - (*y - curY);
                    last_times[curX][*y] = t;
                    rows[*y].erase(curX);
                }
                curY = curY + c.dist;
                break;
            case 'u': // go down
                for(auto y = --cols[curX].upper_bound(curY); *y >= curY - c.dist; y = --cols[curX].erase(y)) {
                    t = stT - (curY  - *y);
                    last_times[curX][*y] = t;
                    rows[*y].erase(curX);
                }
                curY = curY - c.dist;
                break;
            case 'l': // go right
                for(auto x = rows[curY].lower_bound(curX); *x < curX + c.dist; x = rows[curY].erase(x)) {
                    t = stT - (*x - curX);
                    last_times[*x][curY] = t;
                    cols[*x].erase(curY);
                }
                curX = curX + c.dist;
                break;
            case 'r': // go left
                for(auto x = --rows[curY].upper_bound(curX); *x >= curX - c.dist; x = --rows[curY].erase(x)) {
                    t = stT - (curX  - *x);
                    last_times[*x][curY] = t;
                    cols[*x].erase(curY);
                }
                curX = curX - c.dist;
                break;
        }
        t = stT - c.dist;
    }
    return last_times;
}

pll get_times(vector<vector<ll>> ltimes, vector<string> & grid){
    ll earliest = 0;
    ll latest = last_possible_time;
    for (ll i = 0; i < ltimes.size(); ++i) {
        for (ll j = 0; j < ltimes[i].size(); ++j) {
            ll t = ltimes[i][j];
            if(grid[j][i] == '.' && t != -1){
                // must stop before time t to erase.
                latest = min(latest, t - 1);
            }
            if(grid[j][i] == '#'){
                if(t == -1){
                    return {-1, -1};
                }else{
                    earliest = max(earliest, t);
                }
            }
        }
    }
    if(earliest > latest){
        return {-1, -1};
    }
    return {earliest, latest};
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll h, w, n;
    cin >> h >> w >> n;
    vector<string> grid(h);
    for (ll i = 0; i < h; ++i) {
        cin >> grid[i];
    }
    reverse(grid.begin(), grid.end());
    vector<Command> commands(n);
    for (ll i = 0; i < n; ++i) {
        string direction;
        cin >> direction >> commands[i].dist;
        commands[i].dir = direction[0];
    }
    vector<vector<ll>> latest_time_vec = latest_times(h, w, commands);
    pll ans = get_times(latest_time_vec, grid);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}
