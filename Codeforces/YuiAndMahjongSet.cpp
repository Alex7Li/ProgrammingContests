# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1334/B
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

pll query(int ind) {
    cout << "+ " << ind << endl;
    pll res;
    cin >> res.first >> res.second;
    return res;
}

void answer(vector<int> initialCounts) {
    cout << "!";
    for (uint i = 1; i < initialCounts.size(); i++) {
        cout << " " << initialCounts[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> counts(n + 1, 0);
    map<ll, int> mp; // if response is j, mp[j] is initial count
    for (int i = 0; i <= n + 1; i++) {
        int nc3 = (i * (i - 1) * (i - 2)) / 6;
        int npc3 = (i * (i - 1) * (i + 1)) / 6;
        mp[npc3 - nc3] = i;
    }
    pair<ll, ll> last = query(1);
    vector<pll> responses(n + 1);
    for (int i = 1; i < n; i++) {
        responses[i] = query(i);
        responses[i].first -= last.first;
        responses[i].second -= last.second;
        last = responses[i];
        counts[i] = mp[responses[i].first];
    }
    for (int i = 1; i < n; i++) {
        if (counts[i + 1] == 1) {
            int a = i < 3 ? 0 : (counts[i - 1] + 1);
            int b = i == 1 ? 0 : (counts[i - 2] + 1);
            int r = responses[i].second;
            r -= a * b;
            if (r == 0) {
                counts[i + 1] = 0;
            }
        }
    }
    counts[n] = responses[n].second / (counts[n - 1] + 1) / (counts[n - 2] + 1);
    counts[1]--;
    answer(counts);
    return 0;
}