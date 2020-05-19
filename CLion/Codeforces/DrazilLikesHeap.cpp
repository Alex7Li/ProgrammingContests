# include <bits/stdc++.h>
//https://codeforces.com/contest/1330/problem/E
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef unsigned int uint;
typedef long long ll;

int h, g;
vector<bool> pos;
vector<int> heap;
int location;

bool pop(int st) {
    if (!pos[st]) {
        return false;
    }
    int left = 2 * st;
    int right = 2 * st + 1;
    if (heap[left] == 0 && heap[right] == 0) {
        pos[st] = false;
        if (st >= (1 << g)) {
            heap[st / 2] = heap[st];
            heap[st] = 0;
            return true;
        }
    } else {
        int branch = heap[left] > heap[right] ? left : right;
        int val = heap[st];
        if (pop(branch)) {
            if (st != location) {
                heap[st / 2] = val;
            }
        } else {
            pos[st] = false;
        }
    }
    return pos[st];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(ntimes, 0, t) {
        cin >> h >> g;
        heap = vector<int>((2 << h), 0);
        pos = vector<bool>((1 << h), true);
        for (int i = 1; i < (1 << h); i++) {
            cin >> heap[i];
        }
        location = 1;
        vector<int> operations;
        for (int i = 0; i < (1 << h) - (1 << g); i++) {
            while (!pop(location)){
                location++;
            }
            assert(location < (1 << g));
            operations.push_back(location);
        }
        ll sum = 0;
        for (int i = 1; i < 1 << g; i++) {
            sum += heap[i];
        }
        cout << sum << "\n";
        for (uint i = 0; i < operations.size(); i++) {
            cout << operations[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}