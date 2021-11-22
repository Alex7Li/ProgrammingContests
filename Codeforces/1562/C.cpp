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

vi fix(const vi &in, const string & s){
    // if the second string is 0, swap it
    for (int i = in[2]; i <= in[3]; ++i) {
        if(s[i] == '1'){
            return in;
        }
    }
    vi cp(in);
    cp[0] = in[2];
    cp[1] = in[3];
    cp[2] = in[0];
    cp[3] = in[1];
    return cp;
}

vi solve(string &s) {
    int n = s.size();
    int mid = (n + 1) / 2;
    for (int i = mid; i < s.size(); ++i) {
        if (s[i] == '0') {
            return {0, i, 0, i - 1};
        }
    }
    if(s[mid - 1] == '1') {
        return {mid - 1, n - 2, mid, n - 1};
    } else {
        return fix({mid - 1, n - 1, mid, n - 1}, s);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(std::istream::failbit);
    int n_test_cases;
    cin >> n_test_cases;
    for (int cur_test = 1; cur_test <= n_test_cases; cur_test++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vi ans = solve(s);
        cout << ans[0] + 1 << " " << ans[1] + 1<< " " << ans[2] + 1 << " " << ans[3] + 1 << endl;
    }

}