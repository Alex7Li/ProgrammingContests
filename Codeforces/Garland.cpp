# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1286/A
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int opt(vector<pii> valueCostPair, int maxCost) {
    vector<int> bestWithCost(maxCost + 1);
    trav(vc, valueCostPair) {
        int val = vc.first;
        int cost = vc.second;
        for (int i = maxCost - cost; i >= 0; i--) {
            bestWithCost[i + cost] = max(bestWithCost[i] + val, bestWithCost[i + cost]);
        }
    }
    return bestWithCost[maxCost];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if(n==1){
        cout << 0;
        return 0;
    }
    vector<int> p(n);
    int evens = n / 2;
    int odds = (n + 1) / 2;
    // (get, pay)
    vector<pii> oddCosts;
    vector<pii> evenCosts;
    int cost = 0;
    int lastInd = -1;
    rep(i, 0, n) {
        cin >> p[i];
        if (p[i] != 0) {
            if (p[i] % 2 == 0) {
                evens--;
            } else {
                odds--;
            }
            if (i - lastInd != 1) {
                if (lastInd == -1) {
                    //first segment
                    if (p[i] % 2 == 0) {
                        evenCosts.push_back(pii(1, i - lastInd - 1));
                    } else {
                        oddCosts.push_back(pii(1, i - lastInd - 1));
                    }
                    cost++;
                } else if (p[i] % 2 == 0 && p[lastInd] % 2 == 0) {
                    evenCosts.push_back(pii(2, i - lastInd - 1));
                    cost += 2;
                } else if (p[i] % 2 != 0 && p[lastInd] % 2 != 0) {
                    oddCosts.push_back(pii(2, i - lastInd - 1));
                    cost += 2;
                } else {
                    cost++;
                }
            } else if (lastInd != -1) {
                cost += p[i] % 2 != p[i - 1] % 2;
            }
            lastInd = i;
        }
    }
    // last segment
    if (lastInd != n - 1) {
        if (p[lastInd] % 2 == 0) {
            evenCosts.push_back(pii(1, n - lastInd - 1));
        } else {
            oddCosts.push_back(pii(1, n - lastInd - 1));
        }
        cost++;
    }
    cost -= opt(evenCosts, evens);
    cost -= opt(oddCosts, odds);
    cout << cost;
    return 0;
}

