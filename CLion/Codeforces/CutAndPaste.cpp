# include <bits/stdc++.h>

# define MOD 1000000007LL
using namespace std;
//https://codeforces.com/problemset/problem/1280/A
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    for (int t = 0; t < cases; t++) {
        int x;
        string s;
        cin >> x >> s;
        vector<int> str;
        long long curLen = s.length();
        for (unsigned int i = 0; i < s.length(); i++) {
            str.push_back(s[i] - '0');
        }
        bool done = curLen >= x;
        for (int i = 0; i < x; i++) {
            long long cutLen = (curLen - i - 1 + MOD)%MOD;
            if (!done) {
                for (int j = 1; j < str[i]; j++) {
                    int count = i + 1;
                    while (count + j * cutLen < x && count < curLen) {
                        str.push_back(str[count]);
                        count++;
                    }
                    if (count + j * cutLen == x) {
                        done = true;
                    }
                }
            }
            curLen = (curLen + cutLen * (str[i] - 1)) % MOD;
        }
        cout << curLen << '\n';
    }
    return 0;
}