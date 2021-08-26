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
    if(n%2==1){
        cout << "still running\n";
    }else {
        int st, end;
        int score = 0;
        for (int i = 0; i < n/2; i++) {
            cin >> st >> end;
            score += end -st;
        }
        cout <<score << "\n";
    }

    return 0;
}