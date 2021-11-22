# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//https://codeforces.com/contest/1305/problem/B
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    vector<char> seq(str.begin(), str.end());
    string ans;
    bool done = false;
    int iterations = 0;
    while (!done) {
        vi forward;
        vi backward;
        rep(i, 0, seq.size()) {
            if (seq[i] == '(') {
                forward.push_back(i);
            }else if (seq[i] == ')') {
                backward.push_back(i);
            }
        }
        unsigned int ind = 0;
        while (forward.size() > ind && backward.size() > ind && forward[ind] < backward[backward.size() - ind - 1]) {
            ind++;
        }
        if (ind == 0) {
            done = true;
        } else {
            ans.append(to_string(2*ind) + "\n" + to_string(forward[0]+1));
            seq.erase(seq.begin()+forward[0]);
            ind--;
            int offset = 1;
            for (int i = 1; i <= ind; i++) {
                int rem = forward[i];
                ans.append(" " + to_string(rem+1));
                seq.erase(seq.begin()+rem-(offset++));
            }
            for (int i = backward.size()-ind-1; i  < backward.size(); i++) {
                int rem = backward[i];
                ans.append(" " + to_string(rem+1));
                seq.erase(seq.begin()+rem-(offset++));
            }
            ans.append("\n");
        }
        iterations++;
    }
    cout << iterations-1 << "\n";
    cout << ans;
    return 0;
}