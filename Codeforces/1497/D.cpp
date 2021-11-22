# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 2000000000;

int getValid(vector<pii> valid, int ban1, int ban2) {
    rep(i, 0, valid.size()) {
        if (valid[i].first != ban1 && valid[i].first != ban2 && valid[i].first != -1 && valid[i].first != INF) {
            return valid[i].second;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vi tag(n);
        vector<ll> score(n);
        rep(i, 0, n) {
            cin >> tag[i];
        }
        rep(i, 0, n) {
            cin >> score[i];
        }
        // best[i][j] is the best from i if we jumped from index j
        vector<map<int, ll>> best(n, map<int, ll>());
        rep(i, 0, n) {
            best[i][0] = 0;
        }
        ll veryBest = 0;
        // smallest, next smallest, next smallest (tag, score)
        vector<vector<pii>> tagMin(n, vector<pii>(3, pii(-1, INF)));
        vector<vector<pii>> tagMax(n, vector<pii>(3, pii(-1, -1)));
        rep(i, 0, n) {
            if (i != 0) {
                tagMin[i] = tagMin[i - 1];
                tagMax[i] = tagMax[i - 1];
            }
            for (int k = 0; k < 3; k++) {
                if (tagMin[i][k].second > score[i]) {
                    for (int l = 2; l > k; l--) {
                        tagMin[i][l] = tagMin[i][l - 1];
                    }
                    tagMin[i][k] = pii(tag[i], score[i]);
                }
                if (tag[i] == tagMin[i][k].first) {
                    break;
                }
            }
            for (int k = 0; k < 3; k++) {
                if (tagMax[i][k].second < score[i]) {
                    for (int l = 2; l > k; l--) {
                        tagMax[i][l] = tagMax[i][l - 1];
                    }
                    tagMax[i][k] = pii(tag[i], score[i]);
                }
                if (tag[i] == tagMax[i][k].first) {
                    break;
                }
            }
            trav(prev, best[i]) {
                if (prev.first != 0) {
                    // jump back to a pos j, then forwards to k.
                    // requires that tag[j]!=tag[k] and tag[i] != tag[j].
                    rep(k, i + 1, n) {
                        ll minValid = getValid(tagMin[prev.first - 1], tag[i], tag[k]);
                        if (minValid != -1) {
                            best[k][0] = max(best[k][0],
                                             prev.second + abs(minValid - score[i]) + abs(score[k] - minValid));
                        }
                        ll maxValid = getValid(tagMax[prev.first - 1], tag[i], tag[k]);
                        if (maxValid != -1) {
                            best[k][0] = max(best[k][0],
                                             prev.second + abs(maxValid - score[i]) + abs(score[k] - maxValid));
                        }
                    }

                    rep(j, 0, prev.first) {
                        if (tag[i] != tag[j]) {
                            // might also just jump back and end
                            veryBest = max(veryBest, prev.second + abs(score[j] - score[i]));
                        }
                    }
                }
            }
            trav(p, best[i]) {
                best[i][0] = max(p.second, best[i][0]);
            }
            rep(k, i + 1, n) {
                // just jump forwards to k. It's only beneficial to do this if k is
                // 1) The next in the sequence or
                // 2) jumping to any of the numbers between this and k will make it impossible
                // to jump to k later.
                //
                // I.E only when tags from i and k-1 are all the same
                if (tag[i] != tag[k]) {
                    best[k][i] = max(best[k][i], best[i][0] + abs(score[i] - score[k]));
                    break;
                }
            }
        }
        trav(v, best) {
            trav(theScore, v) {
                veryBest = max(theScore.second, veryBest);
            }
        }
        cout << veryBest << "\n";
    }

    return 0;
}