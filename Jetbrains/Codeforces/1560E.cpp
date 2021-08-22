//
// Created by alex on 8/22/21.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int getWordLength(map<char, int> &letterCount, vector<char> &letterOrder) {
    string word;
    vector<int> expectedCounts(letterOrder.size());
    for (int i = 0; i < letterOrder.size(); ++i) {
        int copies = letterOrder.size() - i;
        expectedCounts.push_back(letterCount[letterOrder[i]] / copies);
    }
    int wordLength = 0;
    for(auto c: expectedCounts) {
        wordLength += c;
    }
    return wordLength;
}

bool isValid(string s, const string& t, const vector<char>& letterOrder) {
    int curPos = 0;
    for (int i = letterOrder.size() - 1; i >= 0; --i) {
        // write to t
        if(t.substr(curPos, s.size()) != s){
            return false;
        }
        // update s
        curPos += s.size();
        string s2;
        for (char j : s) {
            if(j != letterOrder[i]) {
                s2 += j;
            }
        }
        s = s2;
    }
    return s.empty() && curPos == t.size();
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(std::istream::failbit);
    int n_test_cases;
    cin >> n_test_cases;
    for (int cur_test = 1; cur_test <= n_test_cases; cur_test++) {
        string t;
        cin >> t;
        map<char, int> letterCount;
        vector<char> letterOrder;
        for (int i = t.size() - 1; i >= 0; --i) {
            char letter = t[i];
            if (letterCount.count(letter) == 0) {
                letterOrder.push_back(letter);
                letterCount.insert({letter, 0});
            }
            letterCount[letter]++;
        }
        int sLen = getWordLength(letterCount, letterOrder);
        string s = t.substr(0, sLen);
        if(isValid(s, t, letterOrder)) {
            cout << s << " ";
            for(int i = letterOrder.size() - 1; i >= 0; i--) {
                cout << letterOrder[i];
            }
        }else {
            cout << -1;
        }
        cout << "\n";
    }
}