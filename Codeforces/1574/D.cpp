#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int best_score = 0;
vi best_ans;

int score(const int n, const vector<vi>& items, const vi& st){
    int score = 0;
    for (int i = 0; i < n; i++)
    {
        score += items[i][st[i]];
    }
    if (score > best_score)
    {
        best_ans = st;
        best_score = score;
    }
    // cout << score << ": ";
    // for(int i = 0; i < n; i++){
    //     cout << " " << st[i];
    // }
    // cout << "\n";
    return score;
}

void solve(int n, vector<vi>& items, set<vi>& banned, int ind, vi st) {
    if(ind == n) {
        assert(banned.count(st) == 1);
        return;
    }
    while(st[ind] < items[ind].size() && banned.count(st) == 1){
        solve(n, items, banned, ind + 1, st);
        st[ind]++;
    }
    if(st[ind] < items[ind].size()) {
        // current build not banned
        score(n, items, st);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vi> items(n);
    for (int i = 0; i < n; i++)
    {
        int n_items;
        cin >> n_items;
        vector<int> slot(n_items);
        for (size_t j = 0; j < n_items; j++)
        {
            cin >> slot[n_items - j - 1];
        }
        items[i] = slot;
    }
    int m;
    cin >> m;
    set<vi> banned;
    for (int i = 0; i < m; i++){
        vector<int> build(n);
        for (size_t j = 0; j < n; j++)
        {
            cin >> build[j];
            build[j] = items[j].size() - build[j];
        }
        banned.insert(build);
    }
    vi st(n);
    solve(n, items, banned, 0, st);
    assert(best_ans.size() == n);
    for (int i = 0; i < best_ans.size(); i++)
    {
        cout << items[i].size() - best_ans[i] << " ";
    }
    return 0;
}