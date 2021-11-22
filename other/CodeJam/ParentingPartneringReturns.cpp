# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Event {
    int start, end, ind;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 1, t + 1) {
        cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        vector<Event> events(n);
        vector<int> order(n);
        for (int i = 0; i < n; i++) {
            cin >> events[i].start >> events[i].end;
            events[i].ind = i;
        }
        auto compare = [](Event e1, Event e2) {
            return e1.start > e2.start;
        };
        priority_queue<Event, vector<Event>, decltype(compare)> Q(compare);
        trav(e, events) {
            Q.push(e);
        }
        int busyTill[] = {-1, -1, -1};
        while (!Q.empty()) {
            Event next = Q.top();
            Q.pop();
            for (uint i = 0; i < sizeof(busyTill) / sizeof(int); i++) {
                if (busyTill[i] <= next.start) {
                    busyTill[i] = next.end;
                    order[next.ind] = i;
                    break;
                }
            }
        }
        if (busyTill[2] > -1) {
            cout << "IMPOSSIBLE" << "\n";
            continue;
        }
        for (uint i = 0; i < order.size(); i++) {
            if (order[i] == 0) {
                cout << 'C';
            } else {
                cout << 'J';
            }
        }
        cout << "\n";
    }
    return 0;
}