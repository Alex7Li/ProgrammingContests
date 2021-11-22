# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1326/D1
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool isPalindrome(string s) {
    for (unsigned int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

struct CutString {
public:
    int wrongCount;
    unsigned int len;
    deque<char> prefix;
    deque<char> postfix;

    CutString(string start) {
        len = start.length();
        wrongCount = len / 2;
        for (unsigned int i = 0; i < len; i++) {
            prefix.push_back(start[i]);
        }
        for (unsigned int i = 0; i < len / 2; i++) {
            if (start[i] == start[len - i - 1]) {
                wrongCount--;
            }
        }
    }

    char at(unsigned int x) {
        if (x > len) {
            assert(false);
        }
        if (x < prefix.size()) {
            return prefix[x];
        } else {
            return postfix[x - prefix.size()];
        }
    }

    bool replacePre(char c) {
        int stInd = prefix.size() - 1;
        //cout << at(stInd) << " " << at(len- stInd -1) <<endl;
        bool wasOk = at(stInd) == at(len - stInd - 1);
        prefix.pop_back();
        postfix.push_front(c);
        bool isOk = at(stInd) == at(len - stInd - 1);
        wrongCount += wasOk - isOk;
        return isPalindrome();
    }

    bool isPalindrome() {
        return wrongCount == 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(x, 0, t) {
        string str;
        cin >> str;
        string best = "";
        for (unsigned int len = 1; len <= str.length(); len++) {
            string st = str.substr(0, len);
            CutString cs(st);
            if (cs.isPalindrome()) {
                string concat = st;
                best = concat;
                continue;
            }
            rep(i, 0, len) {
                if (cs.replacePre(str[str.length() - i - 1])) {
                    string concat = str.substr(0, len - i - 1) + str.substr(str.length() - i - 1);
                    best = concat;
                    break;
                }
            }
        }
        cout << best << endl;
    }

    return 0;
}