# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)

void get_heights(string root, map<string, vector<string>> &children_edges, map<string, string> &parent_edges,
                 map<string, int> &height) {
    trav(child, children_edges[root]) {
        height[child] = height[root] + 1;
        get_heights(child, children_edges, parent_edges, height);
    }
}

string get_ancestor(string r1, string r2, map<string, string> &parent_edges,
                    map<string, int> &height) {
    if (height[r1] < height[r2]) {
        swap(r1, r2);
    }
    // r1 >= r2
    while (height[r2] < height[r1]) {
        r1 = parent_edges[r1];
    }
    while (r2 != r1) {
        r1 = parent_edges[r1];
        r2 = parent_edges[r2];
    }
    return r1;
}

string nify(int n) {
    if (n != 11 && n != 12 && n != 13) {
        if (n % 10 == 1) {
            return to_string(n) + "st";
        }
        if (n % 10 == 2) {
            return to_string(n) + "nd";
        }
        if (n % 10 == 3) {
            return to_string(n) + "rd";
        }
    }
    return to_string(n) + "th";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, p;
    cin >> t >> p;
    map<string, vector<string>> children_edges;
    map<string, string> parent_edges;
    rep(i, 0, t) {
        string parent;
        cin >> parent;
        int n;
        cin >> n;
        vector<string> children(n);
        rep(j, 0, n) {
            cin >> children[j];
            parent_edges[children[j]] = parent;
            // If children[j] is not in children_edges (no children have been assigned to the
            // children[j] yet)
            if (children_edges.end() == children_edges.find(children[j])) {
                children_edges[children[j]] = vector<string>(0);
            }
        }
        children_edges[parent] = children;
        // If parent is not in parent_edges (i.e. there is no parent yet)
        if (parent_edges.end() == parent_edges.find(parent)) {
            parent_edges[parent] = "";
        }
    }
    string root = "";
    trav(s, parent_edges) {
        // s= (my_name, parent_name)
        if (s.second == "") {
            assert(root == "");
            root = s.first;
        }
    }

    map<string, int> height;
    height[root] = 0;
    get_heights(root, children_edges, parent_edges, height);

    rep(i, 0, p) {
        string r1, r2;
        cin >> r1 >> r2;
        string r3 = get_ancestor(r1, r2, parent_edges, height);
        int d1 = height[r1] - height[r3];
        int d2 = height[r2] - height[r3];
        bool swapped = false;
        if (d1 > d2) {
            swap(d1, d2);
            swap(r1, r2);
            swapped = true;
        }
        // d1 <= d2
        if (d1 == 0) {
            if (d2 == 1) {
                cout << r2 << " is the child of " << r1;
            } else {
                cout << r2 << " is the ";
                for (int j = 0; j < d2 - 2; j++) {
                    cout << "great ";
                }
                cout << "grandchild of " << r1;
            }
        } else if (d1 == d2) {
            if (swapped) {
                cout << r2 << " and " << r1;
            } else {
                cout << r1 << " and " << r2;
            }
            if (d1 == 1) {
                cout << " are siblings";
            } else {
                cout << " are " << nify(d1 - 1) << " cousins";
            }
        } else {
            if (swapped) {
                cout << r2 << " and " << r1;
            } else {
                cout << r1 << " and " << r2;
            }
            assert(d1 < d2);
            cout << " are " << nify(d1 - 1) << " cousins, ";
            if (d2 - d1 == 1) {
                cout << "1 time removed";
            } else {
                cout << d2 - d1 << " times removed";
            }
        }
        cout << "\n";
    }
    return 0;
}