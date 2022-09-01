// https://oj.uz/problem/view/APIO14_palindrome
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct PalindromeTree {
  struct Node {
    // largest palindromic suffix
    Node *suffix;
    // add a letter to the right and left side of the palindrome
    Node *next[26];
    // length of this palindrome
    int length;
    // number of occurrences
    ll occurrences;
    ll occLazy;
  };
  Node *rootm1 = new Node();
  Node *root0 = new Node();
  vector<Node *> creationOrder;
  void init() {
    rootm1->length = -1;
    rootm1->suffix = rootm1;
    root0->length = 0;
    root0->suffix = rootm1;
  }
  Node *makeNode(const string &s, int i, Node *prevNode) {
    Node *newNode = new Node(); // allocate on heap
    char c = s[i];
    prevNode->next[c - 'a'] = newNode;
    newNode->length = prevNode->length + 2;
    newNode->occurrences = 0;
    newNode->occLazy = 0;
    if (newNode->length == 1) {
      newNode->suffix = root0;
    } else {
      do {
        prevNode = prevNode->suffix;
      } while (s[i - (prevNode->length + 1)] != c);
      if (!(newNode->suffix = prevNode->next[c - 'a'])) {
        newNode->suffix = makeNode(s, i, prevNode);
      }
    }
    creationOrder.push_back(newNode);
    return newNode;
  }
  PalindromeTree(string s) {
    init();
    Node *state = rootm1;
    s = '@' + s;
    for (int i = 1; i < s.length(); i++) {
      char c = s[i];
      while (s[i - (state->length + 1)] != c) {
        state = state->suffix;
      }
      Node *endState = state->next[c - 'a'];
      if (!endState) {
        endState = makeNode(s, i, state);
      }
      endState->occLazy++;
      state = endState;
    }
  }
  ll bestCount() {
    for (int i = creationOrder.size() - 1; i >= 0; i--) {
      creationOrder[i]->occurrences += creationOrder[i]->occLazy;
      creationOrder[i]->suffix->occLazy += creationOrder[i]->occLazy;
      creationOrder[i]->occLazy = 0;
    }
    ll best = 0;
    for (int i = 0; i < creationOrder.size(); i++) {
      best =
          max(best, creationOrder[i]->occurrences * creationOrder[i]->length);
    }
    return best;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  PalindromeTree tree(s);
  cout << tree.bestCount() << endl;
  return 0;
}
