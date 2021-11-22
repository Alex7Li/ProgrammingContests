# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/0000000000051679/0000000000146183
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define endVases 6
typedef unsigned int uint;

int day;

void put(int pot, int label);

unordered_set<int> check(int pot) {
    cin >> day;
    if (day == -1) {
        exit(0);
    }
    cout << 1 + pot << " " << 0 << endl;
    int n;
    cin >> n;
    unordered_set<int> contents(n);
    rep(i, 0, n) {
        int a;
        cin >> a;
        contents.insert(a);
    }
    return contents;
}

int addToPot(int pot, unordered_set<int> s) {
    for (int i = 0; i < 100; i++) {
        if (s.find(i) == s.end()) {
            s.insert(i);
            put(pot, i);
            return i;
        }
    }
    check(0);
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 1, t + 1) {
        // 6 in the last 14 pots: 84 queries
        for (int i = endVases; i < 20; i++) {
            for (int j = 0; j < 6; j++) {
                put(i, 0);
            }
        }
        vector<unordered_set<int>> count(endVases);
        int argmin = 0;
        for (int i = 0; i < endVases; i++) {
            count[i] = check(i); // check: 90 queries
            if (count[i].size() < count[argmin].size()) {
                argmin = i;
            }
        }
        uint bar = count[argmin].size();
        while (day!=99) {
            for (int i = 0; i < endVases; i++) {
                if (day != 99 && i != argmin && count[i].size() <= bar) {
                    addToPot(i, count[i]);
                }
            }
            bar++;
        }
        put(argmin, 99); // drop: 94 queries
        assert(day==100);
    }
    return 0;
}

void put(int pot, int label) {
    cin >> day;
    if (day == -1) {
        exit(0);
    }
    cout << 1 + pot << " " << 1 + label << endl;
}






