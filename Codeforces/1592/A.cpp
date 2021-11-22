//
// Created by alex on 8/26/21.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solve(int l, int r){
    if(l == r) {
        return 0;
    }
    int b = max(l, (r + 2) / 2);
    int a = r;
    return a % b;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(std::istream::failbit);
    int n_test_cases;
    cin >> n_test_cases;
    for(int cur_test = 1; cur_test <= n_test_cases; cur_test++) {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r) << "\n";
    }
}