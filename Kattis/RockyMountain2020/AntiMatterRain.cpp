# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
    // (height, index)
    typedef stack<pii> T;

    vector<T> s;
    int n;

    explicit Tree(int n = 0) : s(2 * n), n(n) {}

    set<int> removedInd;
    stack<int> toRemove;
    int lastPos = -1;

    int query(int pos, int y) {
        //cerr << "Q " << pos;
        int bestInd = -1;
        int maxH = 0;
        if (y > lastPos) {
            while (!toRemove.empty()) {
                removedInd.insert(toRemove.top());
                toRemove.pop();
            }
        }
        lastPos = y;
        for (pos = pos + n; pos != 0; pos /= 2) {
            while (!s[pos].empty() && removedInd.find(s[pos].top().second) != removedInd.end()) {
                s[pos].pop();
            }
            if (!s[pos].empty()) {
                if (maxH < s[pos].top().first) {
                    maxH = s[pos].top().first;
                    bestInd = s[pos].top().second;
                }
            }
        }
        toRemove.push(bestInd);
        //cerr << "(" << maxH << " " << bestInd << ")" << endl;
        return maxH;
    }

    void update(int b, int e, int h, int ind) { // add a thing at [b, e) with height h and index ind
        //cerr << "UPD " << b << " " << e << " " << h << "\n";
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) {
                s[b++].push({h, ind});
            }
            if (e % 2) {
                s[--e].push({h, ind});
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int D, S;
    cin >> D >> S;
    set<int> xCoords;
    // y, type, x1, x2(if relevant)
    vector<tuple<int, bool, int, int>> events(D + S);
    vector<pii> d(D);
    for (int i = 0; i < D; i++) {
        cin >> d[i].first >> d[i].second;
        events[i] = {d[i].second, true, d[i].first, i};
        xCoords.insert(d[i].first);
    }
    vector<pair<pii, int>> s(S);
    for (int i = 0; i < S; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        events[D + i] = {y, false, x1, x2};
        xCoords.insert(x1);
        xCoords.insert(x2);
    }
    map<int, int> undoX;
    int maxInd = 1;
    for (int x: xCoords) {
        undoX[x] = maxInd++;
    }
    sort(events.begin(), events.end());
    Tree t(maxInd);
    vector<int> ans(D);
    for (int i = 0; i < events.size(); ++i) {
        if (get<1>(events[i])) { // a drop falls
            int ind = get<3>(events[i]);
            ans[ind] = t.query(undoX[get<2>(events[i])], get<0>(events[i]));
        } else { // create a platform
            int stX = undoX[get<2>(events[i])];
            int endX = undoX[get<3>(events[i])] + 1;
            t.update(stX, endX, get<0>(events[i]), i);
        }
    }
    for (int i = 0; i < D; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}