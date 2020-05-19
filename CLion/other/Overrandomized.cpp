# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef4/00000000003179a1
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        int l;
        cin >> l;
        cout << "Case #" << i << ": ";
        map<char, int> fmap;
        set<char> all;
        for (int x = 0; x < 10000; x++) {
            string str;
            cin >> str;
            cin >> str;
            fmap[str[0]]++;
            trav(s, str){
                all.insert(s);
            }
        }
        map<int, char> rmap;
        trav(a, fmap) {
            rmap.insert(pair<int, char>(-a.second, a.first));
            all.erase(a.first);
        }
        cout << *all.begin();
        for (auto x : rmap) {
            cout << x.second;
        }
        cout << "\n";
    }
    return 0;
}