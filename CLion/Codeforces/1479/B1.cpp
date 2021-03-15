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
    int n;
    cin >> n;
    vector<int> a(n);
    int score = 0;
    int last = 0;
    vector<int> extra;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != last) {
            score++;
            last = a[i];
        } else {
            extra.push_back(a[i]);
        }
    }
    if(extra.size() > 0){
        score++;
    }
    for (int i = 1; i < extra.size(); i++) {
        if (extra[i] != extra[i - 1]) {
            score++;
        }
    }
    cout << score << endl;
    return 0;
}