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

vector<

int solve(string &s) {
    // If s contains an even digit win
    for (int i = 0; i < s.size(); ++i) {
        int d = s[i] - '0';
        if (d % 2 == 0) {
            return s.size() - 1;
        }
    }
    if (s.size() < 5) {

    } else {
        // Just try them all
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(std::istream::failbit);
    int n_test_cases;
    cin >> n_test_cases;
    for (int cur_test = 1; cur_test <= n_test_cases; cur_test++) {
        string s;
        solve(s);
    }
}