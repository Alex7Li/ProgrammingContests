# include <bits/stdc++.h>
// https://open.kattis.com/contests/nac20open/problems/letterwheels
// AC
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int> VI;

void buildPi(string &p, VI &pi) {
    pi = VI(p.length());
    int k = -2;
    for (int i = 0; i < p.length(); i++) {
        while (k >= -1 && p[k + 1] != p[i])
            k = (k == -1) ? -2 : pi[k];
        pi[i] = ++k;
    }
}

vi KMP(string &t, string &p) {
    VI pi;
    buildPi(p, pi);
    vi ans;
    int k = -1;
    for (int i = 0; i < t.length(); i++) {
        while (k >= -1 && p[k + 1] != t[i])
            k = (k == -1) ? -2 : pi[k];
        k++;
        if (k == p.length() - 1) {
            ans.push_back(i - k);
            k = (k == -1) ? -2 : pi[k];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1;
    string s2;
    string s3;
    cin >> s1 >> s2 >> s3;
    s3 = s3 + s3;
    int n = s1.size();
    int best = n * 3;
    for (int i = 0; i < n; ++i) {
        string desired = "";
        bool bad = false;
        for (int j = 0; j < n; j++) {
            if (s1[j] == s2[(i + j) % n]) {
                bad = true;
                break;
            }
            char next = 3 - s1[j] - s2[(i + j) % n] + 3 * 'A';
            desired += next;
        }
        if (bad) {
            continue;
        }
        vi ok = KMP(s3, desired);
        for (auto &j :ok) {
            best = min(best, min(i, j) + abs(i - j));
            best = min(best, (n - max(i, j)) + abs(i - j));
            best = min(best, (n - max(i, j)) + min(i, j));
            // cout << i << " " << j << "\n";
        }
    }
    cout << (best == 3 * n ? -1 : best) << endl;

    return 0;
}