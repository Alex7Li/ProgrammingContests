# include <bits/stdc++.h>
//https://maps20.kattis.com/problems/maps20.keywords
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<string> words;
    string word;
    getline(cin, word);
    rep(i, 0, n){
        getline(cin, word);
        for(unsigned int j = 0; j < word.size(); j++){
            word[j] = tolower(word[j]);
            if(word[j] == ' '){
                word[j] = '-';
            }
        }
        words.insert(word);
    }
    cout << words.size();
    return 0;
}