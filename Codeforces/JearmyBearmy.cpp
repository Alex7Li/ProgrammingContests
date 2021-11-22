# include <bits/stdc++.h>

# define ll long long
//https://codeforces.com/contest/1280/problem/C
using namespace std;

class Node;

int k;
vector<Node> nodes;

class Node {
    int subtreeSize = 1;
public:
    vector<pair<int, ll>> adj;
    int ind;

    pair<ll, ll> search(int pInd) {
        pair<ll, ll> ans;
        for (pair<int, ll> p: adj) {
            if (p.first != pInd) {
                pair<ll, ll> x = nodes[p.first].search(ind);
                ans.first += x.first;
                ans.second += x.second;
                int s1 = nodes[p.first].subtreeSize, s2 = 2 * k - s1;
                if (s1 % 2 == 1) {
                    ans.first += p.second;
                }
                ans.second += min(s1, s2) * p.second;
                subtreeSize += nodes[p.first].subtreeSize;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    scanf("%d", &cases);
    for (int t = 0; t < cases; t++) {
        scanf("%d", &k);
        nodes = vector<Node>(2 * k, Node());
        for (int i = 0; i < 2 * k; i++) {
            nodes[i].ind = i;
        }
        for (int i = 0; i < 2 * k - 1; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            nodes[a - 1].adj.push_back(pair<int, ll>(b - 1, c));
            nodes[b - 1].adj.push_back(pair<int, ll>(a - 1, c));
        }
        pair<ll, ll> ans = nodes[0].search(-1);
        printf("%lld %lld\n", ans.first, ans.second);
    }
    return 0;
}