# include <bits/stdc++.h>
// https://codeforces.com/contest/1428/problem/E
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Carrot {
    ll nextCost;
    ll curCost;
    int length;
    int pieces;

    bool operator<(const Carrot &o) const {
        return nextCost - curCost > o.nextCost - o.curCost;
    }
};

void setNextCost(Carrot &c) {
    c.curCost = c.nextCost;
    c.pieces++;
    ll min = c.length / c.pieces;
    int rem = c.length % c.pieces;
    c.nextCost = 0;
    // rem pieces of length min + 1
    c.nextCost += rem * (min + 1) * (min + 1);
    // pieces - rem pieces of length min
    c.nextCost += (c.pieces - rem) * min * min;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<Carrot> a(n);
    priority_queue<Carrot> pq;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll l;
        cin >> l;
        ans += l * l;
        a[i].length = l;
        a[i].pieces = 1;
        a[i].nextCost = l * l;
        setNextCost(a[i]);
        pq.push(a[i]);
    }
    for(int i = n; i < k; i++){
        Carrot top = pq.top();
        pq.pop();
        ans -= top.curCost - top.nextCost;
        setNextCost(top);
        pq.push(top);
    }
    cout << ans << "\n";
    return 0;
}