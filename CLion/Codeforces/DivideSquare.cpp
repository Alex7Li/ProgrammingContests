# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
    typedef int T;
    static constexpr T unit = 0;

    T f(T a, T b) { return a + b; } // (any associative fn)
    vector<T> s;
    int n;

    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}

    void update(int pos, T val) {
        for (s[pos += n] += val; pos /= 2;)
            s[pos] = s[pos * 2] + s[pos * 2 + 1];
    }

    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

struct Query {
    int x;
    int y;
    // 0 begin, 1 end, 2 query
    int type;
    int y2 = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    Tree tree(1000001);
    vector<Query> v;
    ll count = 1;
    for (int i = 0; i < n; i++) {
        int y, b, e;
        cin >> y >> b >> e;
        v.push_back(Query{b, y, 0});
        v.push_back(Query{e, y, 2});
        if(b==0 && e == 1000000){
            count++;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, b, e;
        cin >> x >> b >> e;
        v.push_back(Query{x, b, 1, e});
        if(b==0 && e == 1000000){
            count++;
        }
    }
    sort(v.begin(), v.end(), [](const Query& q1, const Query& q2){
        if(q1.x == q2.x){
            return q1.type < q2.type;
        }
        return q1.x < q2.x;
    });
    for (Query q : v) {
        switch (q.type) {
            case 0:
                tree.update(q.y, 1);
                break;
            case 2:
                tree.update(q.y, -1);
                break;
            case 1:
                count += tree.query(q.y, q.y2 + 1);
                break;
        }
    }
    cout << count << endl;
    return 0;
}