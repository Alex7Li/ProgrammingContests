# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 1, t + 1) {
        string str;
        string input;
        int depth = 0;
        cin >> input;
        cout << "Case #" << tt << ": ";
        input.append("0");
        for (int i = 0; i < input.size(); i++) {
            int curDepth = (int) (input[i] - '0');
            int d = curDepth - depth;
            if (d >= 0) {
                for (int i = 0; i < d; i++) {
                    cout << "(";
                }
            } else {
                for (int i = 0; i < -d; i++) {
                    cout << ")";
                }
            }
            depth = curDepth;
            if (i != input.size()-1) {
                cout << input[i];
            }
        }
        cout << "\n";
    }
    return 0;
}