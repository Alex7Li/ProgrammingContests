# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int score(const string &a, char c) {
    int ans = 0;
    for (char i : a) {
        if (i == c) {
            ans++;
        } else {
            ans--;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<pair<string, int>> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i].first;
            words[i].second = i + 1;
        }
        vector<pair<string, int>> ans;
        for (int i = 0; i < 26; ++i) {
            char c = (char) (i) + 'a';
            sort(words.begin(), words.end(),
                 [c](const pair<string, int> &a, const pair<string, int> &b) {
                     return score(a.first, c) > score(b.first, c);
                 });
            int tScore = 0;
            int j = 0;
            while (j < words.size()) {
                int s = score(words[j].first, c);
                tScore += s;
                if (tScore <= 0) {
                    break;
                }
                j++;
            }
            if(ans.size() < j){
                ans.clear();
                for (int k = 0; k < j; ++k) {
                    ans.push_back(words[k]);
                }
            }
        }
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}