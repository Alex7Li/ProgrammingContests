# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1461/F
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<char> output(n + 1);
    if (s == "-+" || s == "+-") {
        s = '+';
    }
    if (s.size() == 1) {
        output = vector<char>(n + 1, s[0]);
    } else if (s == "-*" || s == "*-") { // Just * and -
        bool sawZero = a[0] == 0;
        rep(i, 0, n - 1) {
            if (a[i + 1] == 0 && !sawZero) {
                sawZero = true;
                output[i + 1] = '-';
            } else {
                output[i + 1] = '*';
            }
        }
    } else {// Just * and + (or *, +, -)
        vector<int> zeroLocs;
        zeroLocs.push_back(-1);
        rep(i, 0, n) {
            if (a[i] == 0) {
                zeroLocs.push_back(i);
                output[i] = '+';
                output[i + 1] = '+';
            }
        }
        zeroLocs.push_back(n);
        for (int i = 0; i < zeroLocs.size() - 1; i++) {
            int st = zeroLocs[i] + 1;
            int end = zeroLocs[i + 1];
            int prod = 1;
            vector<int> nonzero;
            while (a[st] == 1 && st < end) {
                output[++st] = '+';
            }
            while (a[end - 1] == 1 && st < end) {
                output[--end] = '+';
            }
            if (st >= end - 1) {
                continue;
            }
            rep(j, st, end) {
                if (a[j] > 1) {
                    prod *= a[j];
                    nonzero.push_back(j);
                    if (prod > 1E8) {
                        break;
                    }
                }
            }
            rep(j, st + 1, end) {
                output[j] = '*';
            }
            if (prod <= 1E8) {
                vector<int> lastPlus(end - st, st - 1);
                vector<int> bestAns(end - st, 0);
                int nonzeroIndex = 0;
                bestAns[0] = a[st];
                lastPlus[0] = st - 1;
                rep(j, st + 1, end) {
                    bestAns[j - st] = a[j] + bestAns[j - 1 - st];
                    lastPlus[j - st] = j - 1;
                    if (a[j] > 1) {
                        int prodSoFar = a[nonzero[++nonzeroIndex]];
                        for (int k = nonzeroIndex - 1; k >= 0; k--) {
                            prodSoFar *= a[nonzero[k]];
                            int score = prodSoFar;
                            if (nonzero[k] - 1 - st >= 0) {
                                score += bestAns[nonzero[k] - 1 - st];
                            }
                            if (score > bestAns[j - st]) {
                                bestAns[j - st] = score;
                                lastPlus[j - st] = nonzero[k] - 1;
                            }
                        }
                    }
                }
                for (int j = lastPlus[end - 1 - st]; j >= st; j = lastPlus[j - st]) {
                    output[j + 1] = '+';
                }
            }
        }
    }
    cout << a[0];
    rep(i, 1, n) {
        cout << output[i] << a[i];
    }
    cout << "\n";
    return 0;
}