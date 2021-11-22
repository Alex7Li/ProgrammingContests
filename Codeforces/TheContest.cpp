# include <bits/stdc++.h>

//https://codeforces.com/problemset/problem/1257/E
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k[3];
    scanf("%d %d %d", &k[0], &k[1], &k[2]);
    set<int> a[3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < k[i]; ++j) {
            int el;
            scanf("%d", &el);
            a[i].insert(el);
        }
    }
    int n = k[0] + k[1] + k[2];
    // min elements that must be moved to use the first two sets up to n
    int cost[n + 1];
    cost[0] = 0;
    int diffSincePivot = 0;
    for (int i = 1; i <= n; i++) {
        cost[i] = cost[i - 1];
        if (a[0].find(i) != a[0].end()) {
            diffSincePivot++;
            if (diffSincePivot > 0) {// it's 1
                diffSincePivot = 0;
            }else {
                cost[i]++;
            }
        } else if (a[1].find(i) != a[1].end()) {
            diffSincePivot--;
        }else{
            cost[i]++;
        }
    }
    int cost2[n+1];
    cost2[n] = 0;
    for(int i = n-1; i>= 0; i--){
        cost2[i] = cost2[i+1];
        if(a[2].find(i+1) == a[2].end()){
            cost2[i]++;
        }
    }
    int best = n;
    for (int i = 0; i <= n; ++i) {
        best = min(best, cost[i] + cost2[i]);
    }
    cout<<best;
    return 0;
}