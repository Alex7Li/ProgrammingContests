# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//http://codeforces.com/gym/102465

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, n;
    cin >> x >> y >> n;
    map<int, pii> segmentMap;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (segmentMap.find(a) == segmentMap.end()) {
            segmentMap[a] = pii(b, b);
        } else {
            segmentMap[a].first = min(segmentMap[a].first, b);
            segmentMap[a].second = max(segmentMap[a].second, b);
        }
    }
    list<int> events;//ordered set
    for (auto &a : segmentMap) {
        pii seg  = a.second;
        events.push_back(seg.first);
        events.push_back(seg.second);//make distinct
    }
    events.sort();
    int bestH = 0;
    // we want to minimize the number of intervals that we are outisde of
    int count = 0;
    for (int event: events) {
        count++;
        if(count == segmentMap.size()){
            bestH = event;
            break;
        }
    }
    ll ans = 0;
    for (auto &a : segmentMap) {
        pii seg = a.second;
        if(seg.first > bestH){
            ans += seg.second - bestH;
        }else if(seg.second < bestH){
            ans += bestH - seg.first;
        }else{
            ans += seg.second- seg.first;
        };
    }
    cout << 2*ans+(x-1) << endl;

    return 0;
}