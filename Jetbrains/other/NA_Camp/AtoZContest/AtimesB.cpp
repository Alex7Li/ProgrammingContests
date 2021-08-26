# include <bits/stdc++.h>
using namespace std;
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1); // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i,k,2 * k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            C z = rt[j+k] * a[i+j+k]; // (25% faster if hand−rolled)
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}
vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return {} ;
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i,0,sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}
int main() {
    string a, b;
    cin >> a;
    cin >> b;
    int size = max(2 << (int) (log2(a.size())), 2 << (int) (log2(b.size())));
    vector<double> av(size, 0);
    for (int i = 0; i < a.size(); ++i) {
        av[i + size - a.size()] = a[i] - '0';
    }
    vector<double> bv(size, 0);
    for (int i = 0; i < b.size(); ++i) {
        bv[i + size - b.size()] = b[i] - '0';
    }
    vector<double> cv = conv(av, bv);
    vector<int> intV(cv.size() + 10);
    for (int i = 0; i < cv.size(); ++i) {
        intV[i + 10] = lround(cv[i]);
    }
    for (int i = intV.size() - 1; i >= 0; --i) {
        if(intV[i] >= 10) {
            intV[i - 1] += intV[i]/10;
            intV[i] = intV[i] % 10;
        }
    }
    bool started = false;
    for (int i = 0; i < intV.size(); ++i) {
        if(intV[i] != 0 || started) {
            cout << intV[i];
            started = true;
        }
    }
    if(!started){
        cout << 0;
    }
    cout << endl;
    return 0;
}

