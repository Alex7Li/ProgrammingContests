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
    for (int tt = 0; tt < t; tt++) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> ends(n);
        int sE = k;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'W') {
                sE++;
                while (sE < n && s[sE - 1] == 'W') {
                    sE++;
                }
            }
            if (sE >= n) {
                break;
            }
        }
        ends[0] = sE;
        for (int i = 1; i < n; i++) {
            if (ends[i] < n && s[i] == 'W') {
                int e = ends[i - 1];
                e++;
                while (e < n && s[e - 1] == 'W') {
                    e++;
                }
                ends[i] = e;
            } else {
                ends[i] = ends[i - 1];
            }
        }
        int mV = ends[0] - 0;
        int argM = 0;
        for(int i = 0; i < n; i++){
            int v = ends[i] - i;
            if(v > mV){
                mV = v;
                argM = i;
            }
        }
        for(int i = argM; i < mV; i++){
            s[i] = 'W';
        }
        // compute score
        int score = s[0] == 'W';
        for (int i = 1; i < n; i++) {
            if (s[i] == 'W') {
                score += 1;
                score += s[i - 1] == 'W';
            }
        }
        cout << score << "\n";
    }
    return 0;
}