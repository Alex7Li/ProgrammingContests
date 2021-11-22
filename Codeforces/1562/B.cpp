//
// Created by alex on 8/26/21.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vector<int> minPrimeFact;

// Factor every number up until n in O(n) time.
// minFact[i] = the minimum factor of i higher than 1. minFact[0] = minFact[1] = 0
// primes[i] = the ith prime.
vector<int> factorAll(int n) {
    vector<int> primes(0);
    vector<int> minFact(n + 1);
    for (int i = 2; i <= n; i++) {
        if (minFact[i] == 0) {
            primes.push_back(i);
            minFact[i] = i;
        }
        for (int j = 0; j < primes.size() && primes[j] <= minFact[i] && i * primes[j] <= n; ++j) {
            minFact[i * primes[j]] = primes[j];
        }
    }
    return minFact;
}

string solve(string &s) {
    string ans;
    // If s contains an even digit win
    for (char i : s) {
        int d = i - '0';
        if (d == 1 || d == 4 || d == 6 || d == 8 || d == 9) {
            ans += std::to_string(d);
            return ans;
        }
    }
    if (s.size() > 5) {
        // s contains a repeated digit 2, 3, 5,7
        vi cnt(5, 0);
        for (char i : s) {
            if(i == '2'){
                cnt[4]++;
            }else {
                cnt[(i -'0')/ 2]++;
            }
        }
        for (int i = 0; i < cnt.size(); ++i) {
            if (cnt[i] > 1) {
                if(i == 4){
                    return "22";
                } else {
                    ans += std::to_string((1 + 2 * i));
                    ans += std::to_string((1 + 2 * i));
                    return ans;
                }
            }
        }
        assert(false);
    } else {
        // Just try them all
        int best = -9;
        string bestStr;
        for (int mask = 1; mask < 1 << s.size(); mask++) {
            string res;
            int cnt = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (mask & (1 << i)) {
                    res += s[i];
                    cnt++;
                }
            }
            int val;
            stringstream stream(res);
            stream >> val;
            if (minPrimeFact[val] != val) {
                if (best < (int)(s.size() - cnt)) {
                    best = s.size() - cnt;
                    bestStr = res;
                }
            }
        }
        return bestStr;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(std::istream::failbit);
    int n_test_cases;
    cin >> n_test_cases;
    minPrimeFact = factorAll(1'000'000);
    for (int cur_test = 1; cur_test <= n_test_cases; cur_test++) {
        string s;
        int n;
        cin >> n;
        cin >> s;
        string ans = solve(s);
        cout << ans.size() << "\n" << ans << endl;
    }
}