# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> sortInds(const vector<int> &v) {
    // initialize original index locations
    vector<int> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    // sort indexes based on comparing values in v
    // using std::stable_sort instead of std::sort
    // to avoid unnecessary index re-orderings
    // when v contains elements of equal values
    stable_sort(idx.begin(), idx.end(),
                [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });

    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> inds = sortInds(a);
        bool pos = true;
        stable_sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            int st = i;
            while (i < n - 1 && a[i] == a[i + 1]) {
                i++;
            }
            // compare from st to i inclusive
            int evenC = 0;
            int oddC = 0;
            for (int j = st; j <= i; ++j) {
                if (inds[j] % 2 == 0) {
                    evenC++;
                } else {
                    oddC++;
                }
            }
            int reqEven = (i + 2)/2  - (st + 1)/2;
            int reqOdd = (i + 1)/2  - st/2;
            if(!(evenC == reqEven && oddC == reqOdd)){
                pos = false;
            }
        }
        if(pos){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}