# include <bits/stdc++.h>
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    vector<int> counts(26);
    for (int i = 0; i < s.size(); i++) {
      int v = s[i] - 'a';
      counts[v]++;
    }
    for (int i = 0; i < t.size(); i++) {
      int w = t[i] - 'a';
      counts[w]--;
    }
    bool hasPos = false;
    bool hasMinus = false;
    for (int i = 0; i < 26; i++){
      if(counts[i] > 0){
        hasPos = true;
      } else if (counts[i] < 0){
        hasMinus = true;
      }
    }
    if(!hasPos && !hasMinus) {
      cout << "array\n";
    } else if (!hasMinus) { // s contains t
      int ind = 0;
      int matched = 0;
      for (char c : t)
      {
        while(ind < s.length()){
          if(s[ind] == c){
            matched++;
            ind++;
            break;
          }
          ind++;
        }
      }
      if(matched == t.length()){
        cout << "automaton\n";
      } else {
        cout << "both\n";
      }
    } else {
      cout << "need tree\n";
    }

    return 0;
}