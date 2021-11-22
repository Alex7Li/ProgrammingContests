# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> factor(int a) {
    vector<int> v;
    int i;
    for (i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            v.push_back(i);
            a /= i;
        }
    }
    if (a != 1) {
        v.push_back(a);
    }
    return v;
}

void print_factorization(vector<int> factors) {
    sort(factors.begin(), factors.end());
    int ind = 0;
    int cur = -1;
    int count = 0;
    while (ind < factors.size()) {
        if (cur == factors[ind]) {
            count++;
        } else {
            if (count != 0) {
                cout << cur;
                if (count != 1) {
                    cout << "^" << count;
                }
                cout << " ";
            }
            count = 1;
            cur = factors[ind];
        }
        ind++;
    }
    if (count != 0) {
        cout << cur;
        if (count != 1) {
            cout << "^" << count;
        }
        cout << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    getline(cin, line);
    int val;
    while (!line.empty()) {
        stringstream line_stream(line);
        line_stream >> val;
        if (val < 0) {
            cout << -1 << " ";
            val *= -1;
        }
        vector<int> factored = factor(val);
        print_factorization(factored);
        cout << "\n";
        getline(cin, line);
    }
    cout << "\n";
    return 0;
}