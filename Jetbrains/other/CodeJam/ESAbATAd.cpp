# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void guess(vector<int> &array) {
    for (int i = 0; i < sz(array); i++) {
        cout << array[i];
    }
    cout << endl;
    char response;
    cin >> response;
    if (response == 'N') {
        exit(0);
    }
}

void fluctuate(vector<int> &array, pii same, pii opp);

int numberOfQueries = 0;

int query(int ind, vector<int> &array, pii same, pii opp) {
    numberOfQueries++;
    if (numberOfQueries % 10 == 1) {
        fluctuate(array, same, opp);
    }
    cout << (ind + 1) << endl;
    char response;
    cin >> response;
    if (response == 'N') {
        exit(0);
    }
    return response == '1';
}

void fluctuate(vector<int> &array, pii same, pii opp) {
    if (same.first != -1) {
        if (query(same.first, array, same, opp) != array[same.first]) {
            // bits got flipped.
            for (int i = 0; i < array.size(); i++) {
                array[i] ^= 1;
            }
        }
    }
    if (opp.first != -1) {
        if (query(opp.first, array, same, opp) != array[opp.first]) {
            // bits got reversed.
            for (int i = 0; i < array.size() / 2; i++) {
                int temp = array[array.size() - i - 1];
                array[array.size() - i - 1] = array[i];
                array[i] = temp;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, b;
    cin >> t >> b;
    for (int tt = 0; tt < t; tt++) {
        numberOfQueries = 0;
        vector<int> array(b, -1);
        pii same_pair = pii(-1, -1);
        pii opp_pair = pii(-1, -1);
        for (int i = 0; i <= b / 2; i++) {
            int s = query(i, array, same_pair, opp_pair);
            if (numberOfQueries % 10 == 0) {
                continue;
            }
            int e = query(b - i - 1, array, same_pair, opp_pair);
            array[i] = s;
            array[b - i - 1] = e;
            if (s == e) {
                same_pair = pii(i, b - i - 1);
            } else {
                opp_pair = pii(i, b - i - 1);
            }
        }
        guess(array);
    }
    return 0;
}