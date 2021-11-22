# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll MOD = 43200000000000LL;
ll elevenInv = 15709090909091LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    assert((elevenInv * 11) % MOD == 1LL);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        vector<ll> hands(3);
        cin >> hands[0] >> hands[1] >> hands[2];
        vector<int> perm = {0, 1, 2};
        bool done = false;
        do {
            ll HM = (MOD + hands[perm[1]] - hands[perm[0]]) % MOD;
            ll MS = (MOD + hands[perm[2]] - hands[perm[1]]) % MOD;
            ll HS = (MOD + hands[perm[2]] - hands[perm[0]]) % MOD;
            // HM * 11^{-1} = tick % MOD
            ll a = elevenInv % 20'000;
            ll left = elevenInv / 20'000;
            ll b = left % 20'000;
            ll c = left / 20'000;
            ll tick = (HM * a) % MOD;
            tick = (tick + (20'000 * ((HM * b) % MOD))) % MOD;
            ll temp = (20'000 * ((HM * c) % MOD)) % MOD;
            ll temp2 = (20'000 * temp) % MOD;
            tick = (tick + temp2) % MOD;
            assert(((tick * 11) % MOD) == HM);
            if ((708 * tick) % MOD == MS) {
                if ((719 * tick) % MOD == HS) {
                    done = true;
                    ll ten9 = 1000000000;
                    ll ns = tick % ten9;
                    tick /= ten9;
                    ll sec = tick % 60;
                    tick /= 60;
                    ll m = tick % 60;
                    tick /= 60;
                    assert(0 <= tick && tick < 12);
                    cout << "Case #" << (tt + 1) << ": ";
                    cout << tick << " " << m << " " << sec << " " << ns << endl;
                }
            }
        } while (!done && next_permutation(perm.begin(), perm.end()));
    }
    return 0;
}