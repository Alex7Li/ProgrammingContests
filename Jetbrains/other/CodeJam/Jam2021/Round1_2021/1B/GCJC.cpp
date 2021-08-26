# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<ll, ll> hash_v(vector<int> &h, int n, int b) {
    ll pow = 1;
    ll hash = 0;
    for (int i = 0; i < n / 2; ++i) {
        hash += h[i] * pow;
        pow *= b;
    }
    pow = 1;
    ll hash2 = 0;
    for (int i = n / 2; i < n; ++i) {
        hash2 += h[i] * pow;
        pow *= b;
    }
    return {hash, hash2};
}

pair<int, double> best(int n, int b, vector<int> &h, map<pair<ll, ll>, double> &scores, int val) {
    double curBest = 0;
    int bestInd = -1;
    for (int i = 0; i < n; ++i) {
        if (h[i] != b && (i == 0 || (h[i] < h[i - 1]))) {
            h[i]++;
            double expectedGain = scores[hash_v(h, n, b)];
            h[i]--;
            double realGain = pow(10, h[i]) * val;
            double gain = expectedGain + realGain;
            if (gain > curBest) {
                curBest = gain;
                bestInd = i;
            }
        }
    }
    return {bestInd, curBest};
}

void make_dp(int n, int b, vector<int> &h, map<pair<ll, ll>, double> &scores) {
    double expected = 0;
    for (int i = 0; i <= 9; ++i) {
        pair<int, double> bestInd = best(n, b, h, scores, i);
        expected += bestInd.second / 10;
    }
    scores[hash_v(h, n, b)] = expected;
}

void gen_order(int n, int b, int ind, vector<int> &v, map<pair<ll,ll>, double> &scores) {
    if (ind == -1) {
        make_dp(n, b, v, scores);
 //       cerr << v[0] << " " << v[1] << " " << v[2] << " " << scores[hash(v)] << endl;
        return;
    }
    int st = v[ind];
    int bound = ind + 1 == n ? 0 : v[ind + 1];
    for (int i = st; i >= bound; --i) {
        v[ind] = i;
        gen_order(n, b, ind - 1, v, scores);
    }
    v[ind] = st; //maintain invariant
}

int read_v() {
    int val;
    cin >> val;
    return val;
}

void write_ind(int ind) {
    cout << (ind + 1) << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, b, p;
    cin >> t >> n >> b >> p;
    vector<int> v(n, b);
    map<pair<ll,ll>, double> scores;
    gen_order(n, b, n - 1, v, scores);
    for (int tt = 0; tt < t; tt++) {
        v = vector<int>(n, 0);
        vi inds = vi(n, 0);
        iota(inds.begin(), inds.end(), 0);
        for (int i = 0; i < n * b; ++i) {
            int val = read_v();
            int ind = inds[best(n, b, v, scores, val).first];
            for (int j = 0; j < n - 1; ++j) {
                if (v[j] < v[j + 1]) {
                    swap(v[j], v[j + 1]);
                    swap(inds[j], inds[j + 1]);
                }
            }
            v[ind]++;
            write_ind(ind);
        }
        read_v(); // hope it's 1
    }
    return 0;
}