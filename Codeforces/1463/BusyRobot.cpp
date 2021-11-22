# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 0, t) {
        int n;
        cin >> n;
        vector<int> times(n);
        vector<int> points(n);
        int completed = 0;
        int currentTime = 0;
        int currentLocation = 0;
        int currentGoal = 0;
        int lastPoint = -1;
        for (int i = 0; i < n; i++) {
            cin >> times[i] >> points[i];
            int dist = times[i] - currentTime;
            int nextLocation = currentGoal > currentLocation ?
                               min(currentGoal, currentLocation + dist) :
                               max(currentGoal, currentLocation - dist);
            int begin = min(nextLocation, currentLocation);
            int end = max(nextLocation, currentLocation);
            if (lastPoint >= begin && lastPoint <= end) {
                completed++;
            }
            currentLocation = nextLocation;
            if (nextLocation == currentGoal) {
                // Execute the command.
                currentGoal = points[i];
            }
            lastPoint = points[i];
            currentTime = times[i];
        }
        int begin = min(currentLocation, currentGoal);
        int end = max(currentLocation, currentGoal);
        if (lastPoint >= begin && lastPoint <= end) {
            completed++;
        }
        cout << completed << "\n";
    }

    return 0;
}