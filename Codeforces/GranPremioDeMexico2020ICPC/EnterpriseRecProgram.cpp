# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;


ll propScores(int root, vector<vi>& under, vi& score, vi& scoreUp){
    trav(next, under[root]){
        scoreUp[root] += propScores(next, under, score, scoreUp);
    }
    score[root] += scoreUp[root];
    return scoreUp[root];
}

ll subtreeScores(int root, vector<vi>& under, vi& score, vi& subTreeScores){
    trav(next, under[root]){
        subTreeScores[root] += subtreeScores(next, under, score, subTreeScores);
    }
    subTreeScores[root] += score[root];
    return subTreeScores[root];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, q;
    cin >> n >> m >> q;
    vi manager(n + 1);
    vector<vi> under(n+1, vi(0));
    ll root = -1;
    rep(i, 1, n + 1) {
        cin >> manager[i];
        if (manager[i] == 0) {
            root = i;
        }else{
            under[manager[i]].push_back(i);
        }
    }
    vi score(n + 1, 0);
    vi scoreUp(n + 1, 0);
    rep(i, 0, m) {
        ll mi, e, v;
        cin >> mi >> e >> v;
        if (mi == 1) {
            score[e] += v;
        } else {
            scoreUp[e] += v;
        }
    }
    propScores(root, under, score, scoreUp);
    vi subTreeScores(n+1, 0);
    subtreeScores(root, under, score, subTreeScores);
    rep(i, 0, q){
        int t, e;
        cin >> t >> e;
        if(t==1){
            cout << score[e];
        }else{
            cout << subTreeScores[e];
        }
        cout << "\n";
    }
    return 0;
}