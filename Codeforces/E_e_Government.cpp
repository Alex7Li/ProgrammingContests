// https://codeforces.com/problemset/problem/163/E
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct Tree {
    typedef ll T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
struct AhoCorasick {
  enum { alpha = 26, first = 'a' }; // change this!
  struct Node {
    int back, next[alpha], start = -1, end = -1;
    Node(int v) { memset(next, v, sizeof(next)); }
  };
  vector<Node> N;
  vi backp;
  vector<vi> fps;
  void insert(string &s, int j) {
    assert(!s.empty());
    int n = 0;
    for (char c : s) {
      int &m = N[n].next[c - first];
      if (m == -1) {
        n = m = sz(N);
        N.emplace_back(-1);
      } else
        n = m;
    }
    if (N[n].end == -1)
      N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
  }

  Tree tour;
  vi startt;
  vi endt;
  ll get_nmatches(int n) {
    if(n == -1) { // root node
      return 0;
    }
    return tour.query(0, startt[n + 1] + 1);
  }
  void build_euler_tour(int root, int& t)
  {
    for (int next : fps[root])
    {
      startt[next] = t;
      tour.update(t++, 1);
      build_euler_tour(next, t);
      endt[next] = t;
      tour.update(t++, -1);
    }
  }
  void delete_word(int wordInd){
    tour.update(startt[wordInd], 0);
    tour.update(endt[wordInd], 0);
  }
  void insert_word(int wordInd){
    tour.update(startt[wordInd], 1);
    tour.update(endt[wordInd], -1);
  }
  AhoCorasick(vector<string> &pat) : N(1, -1) {
    rep(i, 0, sz(pat)) insert(pat[i], i);
    N[0].back = sz(N);
    N.emplace_back(0);

    // setup back ptrs
    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      rep(i, 0, alpha) {
        int &ed = N[n].next[i], y = N[prev].next[i];
        if (ed == -1)
          ed = y;
        else {
          N[ed].back = y;
          (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
          q.push(ed);
        }
      }
    }
    // setup forward ptrs
    fps = vector<vi>(pat.size() + 1);
    for (int i = sz(N) - 2; i >= 0; i--)
    {
      if(N[i].start != -1) {
        fps[backp[N[i].start] + 1].push_back(N[i].start + 1);
      }
    }
    tour = Tree(2 * (pat.size() + 2));
    startt = vi(pat.size() + 1);
    endt = vi(pat.size() + 1);
    int t = 0;
    build_euler_tour(0, t);
  }
  ll count_politization(string word) {
    ll count = 0;
    int n = 0;
    for (char c : word)
    {
      n = N[n].next[c - first];
      count += get_nmatches(N[n].end);
    }
    return count;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<string> pats;
  for(int i = 0; i < k; i++) {
    string s;
    cin >> s;
    pats.push_back(s);
  }
  AhoCorasick ac(pats);
  for (int i = 0; i < n; i++)
  {
    string q;
    cin >> q;
    string qsub = q.substr(1);
    if (q[0] == '?')
    {
      cout << ac.count_politization(qsub) << "\n";
    }
    else {
      stringstream stream(qsub);
      int v;
      stream >> v;
      if (q[0] == '+')
      {
        ac.insert_word(v);
      }
      else
      {
        assert(q[0] == '-');
        ac.delete_word(v);
      }
    }
  }
  return 0;
}
