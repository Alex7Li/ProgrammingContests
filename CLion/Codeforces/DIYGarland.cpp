# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1283/F
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n - 1, 0);
    vector<bool> used(n, false);
    rep(i, 0, n - 1) {
        cin >> a[i];
    }
    vector<int> parent(n + 1, 0);
    parent[a[0]] = a[0];
    int last = a[0];
    int maxUnused = n + 1;
    rep(i, 1, n - 1) {
        if (parent[a[i]]) {
            while (parent[--maxUnused]);
            parent[maxUnused] = last;
        } else {
            parent[a[i]] = last;
        }
        last = a[i];
    }
    while (parent[--maxUnused]);
    parent[maxUnused] = last;
    cout << a[0] << "\n";
    rep(i, 1, sz(parent)) {
        if(i!=a[0]) {
            cout << i << " " << parent[i] << "\n";
            assert(parent[i]!=0);
        }
    }
    return 0;
}