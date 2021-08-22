# include <bits/stdc++.h>
using namespace std;
//not finished
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Trie {
    bool leaf;  //if the node is a leaf then, a word in the dictionary ends at this node.
    Trie *child[26];
    Trie() {
        for (auto & i : child)i = nullptr;
        leaf = false;
    }
    void add(string &s) {
        Trie *root = this;
        for (char i : s) {
            if (root->child[i - 'a'] == nullptr) {
                root->child[i - 'a'] = new Trie();
            }
            root = root->child[i - 'a'];
        }
        root->leaf = true;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    Trie root;

    return 0;
}

