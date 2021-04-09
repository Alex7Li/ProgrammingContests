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
    rep(tt, 0, t) {
        int n;
        cin >> n;
        vector<char> a(n);
        vector<int> runLengths;
        rep(i, 0, n) {
            cin >> a[i];
        }
        runLengths.push_back(1);
        rep(i, 1, n) {
            if (a[i] == a[i - 1]) {
                runLengths[runLengths.size() - 1]++;
            } else {
                runLengths.push_back(1);
            }
        }
        int score = 0;
        if (runLengths.size() == 1) {
            if(n < 3){
                score = 0;
            }else{
                score = (runLengths[0] + 2 )/ 3;
            }
        } else {
            if (runLengths.size() % 2 == 1) {
                runLengths[0] += runLengths[runLengths.size()-1];
                runLengths.pop_back();
            }
            rep(i, 0, runLengths.size()){
                score += runLengths[i]/3;
            }
        }
        cout << score << "\n";
    }

    return 0;
}