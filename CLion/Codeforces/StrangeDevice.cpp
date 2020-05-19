# include <bits/stdc++.h>
//https://codeforces.com/contest/1270/D
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, k;

int query(int notInd) {
    printf("? ");
    rep(i, 0, k + 1) {
        if (i != notInd) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
    fflush(stdout);
    int pos, val;
    cin >> pos >> val;
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    int v1 = query(0), c1 = 1, v2, c2 = 0;
    rep(i, 1, k + 1) {
        int v = query(i);
        if (v == v1) {
            c1++;
        } else {
            v2 = v;
            c2++;
            if(v2 > v1){
                swap(v1, v2);
                swap(c1, c2);
            }
        }
    }
    printf("! %d\n", c1);
    return 0;
}