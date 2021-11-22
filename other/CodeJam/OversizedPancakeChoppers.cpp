# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef4/00000000003172d1
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        ll n, d;
        cin >> n;
        cin >> d;
        cout << "Case #" << t << ": ";
        vector<ll> a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        double sizeMin = 0;
        double sizeMax = 360'000'000'000;
        double eps = .000'000'1f;
        while (abs(sizeMax - sizeMin) / sizeMax > eps) {
            double mid = (sizeMin + sizeMax) / 2.0f;
            ll slices = 0;
            list<ll> savedCuts;
            for (int j = 0; j < n; j++) {
                slices += a[j] / mid;
            }
            if (slices >= d) {
                sizeMin = mid;
            } else {
                sizeMax = mid;
            }
        }
        set<pair<ll, ll>> skip;
        ll minC = d - 1;
        rep(i, 0, n) {
            ll size = a[i];
            ll cutInto = (size + sizeMin) / sizeMax;
            if (cutInto > d) {
                continue;
            }
            for (ll cutIn = max(1LL, cutInto); cutIn <= d; cutIn++) {
                ll gc = gcd(size, cutIn);
                size /= gc;
                cutIn /= gc;
                if (skip.find(pair<ll, ll>(size, cutIn)) != skip.end()) {
                    continue;
                }
                skip.insert(pair<ll, ll>(size, cutIn));
                vector<ll> divSize;
                for (int j = 0; j < n; j++) {
                    if ((a[j] * cutIn) % size == 0) {
                        divSize.push_back((a[j] * cutIn) / size);
                    }
                }
                sort(divSize.begin(), divSize.end());
                ll saved = 0;
                ll left = d;
                for (int s = 0; s < divSize.size(); s++) {
                    if (divSize[s] <= left) {
                        saved++;
                        left -= divSize[s];
                    } else {
                        break;
                    }
                }
                minC = min(d - saved, minC);
            }
        }
        cout << minC << endl;
    }
    return 0;
}