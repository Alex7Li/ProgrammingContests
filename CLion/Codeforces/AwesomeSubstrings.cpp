# include <bits/stdc++.h>
//https://codeforces.com/contest/1270/problem/F
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef unsigned int uint;
int n;
vi oneLoc, cnt;

ll update(vi &counts, int k, int multiplier){
    ll ways = 0;
    for(int i = 0; i <= n; i++){
        int ind = k*cnt[i] - i + n;
        ways += counts[ind];
        counts[ind] += multiplier;
    }
    return ways;
}

ll solve() {
    int T = sqrt(n);
    ll ans = 0;
    // check any string with exactly i ones and k>T
    for(int i = 1; i <= n/T; i++){
        int st1, st2 = 0, end1, end2;
        for(uint j = 0; j + i < oneLoc.size(); j++) {
            // count intervals that start in [st1, st2)
            // and end in [end1, end2) - these have exactly i ones
            st1 = st2, st2 = oneLoc[j] + 1;
            end1 = oneLoc[j + i - 1], end2 = oneLoc[j + i];
            rep(l, st1, st2) {
                // only count intervals with k>T, so d + 1 = st - end > T(cnt[st] - cnt[end]) = Ti.
                int d1 = max(end1 - l,T*i), d2 = end2-l;
                if(d1 < d2) {
                    ans += d2 / i - d1 / i;
                }
            }
        }
    }
    // check any string with k <= T. This is all of them since any string with k>T
    // has no more than n/T ones.
    // want k*cnt[i] - i = k*cnt[j] - j
    vi counts = vi(n*(T+1), 0);
    for(int k = 1; k <= T; k++){
        ans += update(counts, k, 1);
        update(counts, k, -1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    cin >> input;
    n = input.size();
    cnt = vi(n+1, 0);
    cnt[0] = 0;
    rep(i, 0,n) {
        cnt[i+1] = cnt[i];
        if (input[i]=='1') {
            oneLoc.push_back(i);
            cnt[i+1]++;
        }
    }
    oneLoc.push_back(n);
    cout << solve();
    return 0;
}