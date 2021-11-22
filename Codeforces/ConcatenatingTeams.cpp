# include <bits/stdc++.h>
//https://codeforces.com/gym/102861
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> HASH_T;
// ll MOD = 10000000002065383LL;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

vector<ll> precomputeInvMod(int n, ll mod) {
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
    return inv;
}

const ll inv37 = precomputeInvMod(38, MOD)[37];
const ll inv31 = precomputeInvMod(32, MOD2)[31];

map<HASH_T, set<int>> getPostfix(vector<vi> &a, bool forward) {
    sort(a.begin(), a.end(), [](vi &a1, vi &a2) {
        return a1.size() < a2.size();
    });
    map<HASH_T, int> strs; // strings of a seen so far -> index of that string
    map<HASH_T, set<int>> postfix; // postfix -> set of indexes of strings that only differ by that postfix
    for (int sInd = 0; sInd < a.size(); ++sInd) {
        vi s = a[sInd];
        HASH_T hash = {0, 0};
        vector<ll> pow37(s.size());
        pow37[0] = 1;
        vector<ll> pow31(s.size());
        pow31[0] = 1;
        for (int i = 1; i < s.size(); ++i) {
            pow37[i] = (37LL * pow37[i - 1]) % MOD;
            pow31[i] = (31LL * pow31[i - 1]) % MOD2;
        }
        vector<pair<int, int>> matchInds; // oldMatchInd -> curMatchInd
        for (int i = 0; i < s.size(); ++i) {
            if (forward) {
                hash = {(37LL * hash.first + s[i]) % MOD, (31LL * hash.second + s[i]) % MOD2};
            } else {
                hash = {(hash.first + s[i] * pow37[i]) % MOD, (hash.second + s[i] * pow31[i]) % MOD2};
            }
            if (strs.find(hash) != strs.end()) {
                matchInds.emplace_back(strs.find(hash)->second, i);
            }
        }
        strs.insert({hash, sInd});
        assert(hash.first >= 0);
        assert(hash.second >= 0);
        int ind = 0;
        for (int i = 0; i < s.size(); ++i) {// ind < matchInds.size(); ++i) {
            if (forward) {
                hash = {(hash.first - (s[i] * pow37[s.size() - i - 1])) % MOD,
                        (hash.second - (s[i] * pow31[s.size() - i - 1])) % MOD2};
            } else {
                hash = {((hash.first - s[i]) * inv37) % MOD,
                        ((hash.second - s[i]) * inv31) % MOD2};
            }
            hash = {(hash.first + MOD) % MOD, (hash.second + MOD2) % MOD2};
            if (ind < matchInds.size() && i == matchInds[ind].second) {
                int oldStrInd = matchInds[ind].first;
                if (postfix.find(hash) != postfix.end()) {
                    postfix.find(hash)->second.insert(sInd);
                    postfix.find(hash)->second.insert(oldStrInd);
                } else {
                    set<int> shared = {sInd, oldStrInd};
                    postfix[hash] = shared;
                }
                ind++;
            }
        }
        assert(hash == make_pair(0LL, 0LL));
    }
    return postfix;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    assert((inv37 * 37) % MOD == 1);
    assert((inv31 * 31) % MOD2 == 1);
    int m, n;
    cin >> m >> n;
    vector<vi> a(m, vi(0));
    string temp;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        for (char c : temp) {
            // must be 1 indexed so a, aa don't have the same hash
            a[i].push_back(c - 'a' + 1);
        }
    }
    vector<vi> b(n);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        reverse(temp.begin(), temp.end());
        for (char c : temp) {
            b[i].push_back(c - 'a' + 1);
        }
    }
    map<HASH_T, set<int>> postfixa = getPostfix(a, true);
    map<HASH_T, set<int>> postfixb = getPostfix(b, false);
    set<int> seena;
    set<int> seenb;
    for (auto &hash: postfixa) {
        auto f = postfixb.find(hash.first);
        assert(hash.second.size() > 1);
        if (f != postfixb.end()) {
            assert(f->second.size() > 1);
            for (int ind: hash.second) {
                seena.insert(ind);
            }
            for (int ind: f->second) {
                seenb.insert(ind);
            }
        }
    }
    cout << a.size() - seena.size() << " " << b.size() - seenb.size() << "\n";
    return 0;
}