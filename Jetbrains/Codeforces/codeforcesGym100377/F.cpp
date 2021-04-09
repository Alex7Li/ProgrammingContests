# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;

vector<vi> edges;
vi x;
vi r;

int dfs(int ind, int st) {
    int end = st + 2;
    for (int e: edges[ind]) {
        int d = dfs(e, end - 1);
        end += d;
    }
    x[ind] = (st + end) / 2;
    r[ind] = (end - st) / 2;
    return r[ind] * 2 + 2;
}

void dfsit() {
    stack<int> ind;
    stack<int> ei;
    stack<int> st;
    stack<int> end;
    ind.push(0);
    ei.push(0);
    st.push(0);
    end.push(2);
    while (!ind.empty()) {
        if (ei.top() == edges[ind.top()].size()) {
            int i = ind.top();
            x[i] = (st.top() + end.top()) / 2;
            r[i] = (end.top() - st.top()) / 2;
            ind.pop();
            ei.pop();
            st.pop();
            end.pop();
            if (!ind.empty()) {
                end.top() += r[i] * 2 + 2;
            }
        } else {
            int e = edges[ind.top()][ei.top()++];
            ind.push(e);
            ei.push(0);
            st.push(end.top() - 1);
            end.push(end.top() + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    edges = vector<vi>(n);
    int root = 0;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        if (j == -1) {
            root = i;
        } else {
            edges[j - 1].push_back(i);
        }
    }
    x = vi(n);
    r = vi(n);
    dfs(root, 0);
    rep(i, 0, n) {
        cout << x[i] << " 0 " << r[i] << "\n";
    }
    return 0;
}