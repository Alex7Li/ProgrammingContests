#include <iostream>
#include <vector>
//https://codeforces.com/contest/656/problem/G
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)

int main() {
    int f, I, t;
    cin >> f >> I >> t;
    int ans = 0;
    vector<vector<char>> arr(f, vector<char>(I));
    rep(i, 0, f) {
        char x;
        rep(j, 0, I){
            cin >> x;
            arr[i][j]  = x;
        }
    }
    rep(i, 0, I) {
        int count = 0;
        rep(j, 0, f) {
            if (arr[j][i] == 'Y') {
                count++;
            }
        }
//        cout<< count;
        if (count >= t) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}