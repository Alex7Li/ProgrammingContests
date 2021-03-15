# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool turnsRight(pii a, pii b) {
    return (a.first * b.second - a.second * b.first) < 0;
}


vector<pii> make_hull_top(vector<pii> poles) {
    vector<pii> hull;
    hull.push_back(poles[0]);
    for (int i = 1; i < poles.size(); i++) {
        bool works = hull.size() == 1;
        while (!works) {
            pii last2 = hull[hull.size() - 2];
            pii last = hull[hull.size() - 1];
            pii lastLine = pii(last.first - last2.first, last.second - last2.second);
            pii thisLine = pii(poles[i].first - last.first, poles[i].second - last.second);
            if (!turnsRight(lastLine, thisLine)) {
                hull.pop_back();
                works = hull.size() == 1;
            } else {
                works = true;
            }
        }
        hull.push_back(poles[i]);
    }
    hull.pop_back();
    return hull;
}

double dist(pii a, pii b) {
    double squared = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    return sqrt(squared);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> treeMeters(n);
    vector<int> treeTime(n);
    rep(i, 0, n) {
        cin >> treeMeters[i] >> treeTime[i];
    }
    vector<pii> poles(m);
    rep(i, 0, m) {
        cin >> poles[i].first >> poles[i].second;
    }
    sort(poles.begin(), poles.end());
    vector<pii> hull = make_hull_top(poles);
    reverse(poles.begin(), poles.end());
    vector<pii> hullBottom = make_hull_top(poles);
    rep(i, 0, hullBottom.size()) {
        hull.push_back(hullBottom[i]);
    }
    double length = 0.0;
    rep(i, 0, hull.size()) {
        length += dist(hull[i], hull[(i + 1) % hull.size()]);
    }
    cerr << "THE LENGTH IS " << length << "\n";

    int l = ceil(length);
    // Min weight that can be held to give value i
    vector<int> dp(l + 1005, 500'000'000);
    dp[0] = 0;
    rep(j, 0, n) {
        for (int i = dp.size() - 1; i >= 0; i--) {
            int w = treeMeters[j];
            if (i - w >= 0) {
                dp[i] = min(dp[i], dp[i - w] + treeTime[j]);
            }
        }
    }
    int minW = dp[l];
    rep(i, l, l + 1001){
        minW = min(minW, dp[i]);
    }
    cout << minW;
    return 0;
}