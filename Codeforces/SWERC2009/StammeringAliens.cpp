# include <bits/stdc++.h>
// TLE. The bounds aren't clear from the statement (how many test cases??) but
// this is loglinear so...
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// ll MOD = 10000000002065383LL;
ll MOD = 1e9 + 7;

vector<ll> precomputeInvMod(int n, ll mod) {
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
    return inv;
}

int works(vector<int> &s, int len, int times) {
    unordered_map<ll, int> timesSeen;
    ll hash = 0;
    ll pow = 1;
    for (int i = 0; i < len; ++i) {
        hash = (26 * hash + s[i]) % MOD;
        if(i != 0) {
            pow = pow * 26 % MOD;
        }
    }
    int maxSeen = 0;
    int maxSeenInd = 0;
    for (int i = len; i < s.size(); ++i) {
        timesSeen[hash] += 1;
        if (timesSeen[hash] >= maxSeen) {
            maxSeen = timesSeen[hash];
            maxSeenInd = i - len;
        }
        hash = ((hash - s[i - len] * pow) % MOD + MOD) % MOD;
        hash = (26 * hash + s[i]) % MOD;
    }
    timesSeen[hash] += 1;
    if (timesSeen[hash] >= maxSeen) {
        maxSeen = timesSeen[hash];
        maxSeenInd = s.size() - len;
    }
    if (maxSeen >= times) {
        return maxSeenInd;
    } else {
        return -1;
    }
}

int main() {
    int m;
    string s;
    vector<ll> inv = precomputeInvMod(27, MOD);
    while (true) {
        cin >> m;
        if (m == 0) {
            break;
        }
        cin >> s;
        vector<int> sv(s.size());
        for (int i = 0; i < s.size(); ++i) {
            sv[i] = s[i] - 'a';
        }
        int minL = 0;
        int maxL = s.size();
        while (minL < maxL) {
            int mid = (minL + maxL) / 2;
            if (minL + 1 == maxL) {
                mid = maxL;
            }
            if (works(sv, mid, m) != -1) {
                minL = mid;
            } else {
                maxL = mid - 1;
            }
        }
        if (minL == 0) {
            cout << "none";
        } else {
            cout << minL << " " << works(sv, minL, m);
        }
        cout << "\n";
    }
    return 0;
}