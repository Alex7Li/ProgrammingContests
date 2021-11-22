# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1287/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    set<vector<int>> cards;
    rep(i, 0, n) {
        string cardStr;
        vector<int> card(k);
        cin >> cardStr;
        rep(j, 0, k) {
            switch (cardStr[j]) {
                case 'S':
                    card[j] = 0;
                    break;
                case 'E':
                    card[j] = 1;
                    break;
                case 'T':
                    card[j] = 2;
                    break;
            }
        }
        cards.insert(card);
    }
    int count = 0;
    trav(c1, cards) {
        trav(c2, cards) {
            if(c1==c2){
                continue;
            }
            vector<int> needCard(k);
            rep(i, 0, k) {
                if (c1[i] == c2[i]) {
                    needCard[i] = c1[i];
                } else {
                    needCard[i] = 3 - c1[i] - c2[i];
                }
            }
            if (cards.find(needCard) != cards.end()) {
                count++;
            }
        }
    }
    cout << count/6;
    return 0;
}