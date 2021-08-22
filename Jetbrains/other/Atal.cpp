# include <bits/stdc++.h>
// atal wants to consider a game with a row of n 1's and 0's where you use pascale triangle rule to
// generate n-1 more rows. Players take turns putting the n 1's/0's down, winner is the one who has more
// of their number on the final triangle. Here is some analysis.
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void printArr(int a, int n, int extra) {
    for (int i = 0; i < extra; ++i) {
        cout << " ";
    }
    for (int i = 0; i < n; ++i) {
        cout << ((a & (1 << i)) ? 1 : 0) << " ";
    }
    cout << "\n";
}

int score2(int a, int n) {
    int points = 0;
    //printArr(a, n, 0);
    for (int i = 0; i < n; ++i) {
        a = (a ^ (a >> 1)) & ((1 << (n - i - 1)) - 1);
        points += __builtin_popcount(a);
        //printArr(a, n - i - 1, i + 1);
    }
    return points;
}

int score(vector<int> &a) {
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        ans |= a[i] << i;
    }
    return score2(ans, n);
}

void read_score_game(int n) {
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    int oneS = score(a);
    int t = (n * (n - 1)) / 2;
    cout << "One: " << oneS << " Zero: " << (t - oneS) << endl;
}

void analyze_games(int n) {
    ll oneT = 0;
    ll zeroT = 0;
    int oneWins = 0;
    int zeroWins = 0;
    for (int i = 0; i < (1 << n); ++i) {
        int p = __builtin_popcount(i);
        if (p != n / 2) {
            continue;
        }
        int oneS = score2(i, n);
        int t = (n * (n - 1)) / 2;
        oneT += oneS;
        zeroT += t - oneS;
        if (oneS > t - oneS) {
            oneWins++;
        }
        if (t - oneS > oneS) {
            zeroWins++;
        }
    }
    cout << "ONEW: " << oneWins << " ZEROW: " << zeroWins << " " << (0.0 + oneWins) / (oneWins + zeroWins) << "\n";
    cout << "ONET: " << oneT << " ZEROT: " << zeroT << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (true) {
        cin >> n;
        analyze_games(n);
    }
    /*
   while (true) {
       cin >> n;
       read_score_game(n);
   }
    */
    return 0;
}
