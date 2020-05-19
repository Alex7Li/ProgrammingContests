# include <bits/stdc++.h>

using ll = long long;
//https://codeforces.com/problemset/problem/1280/D
using namespace std;

struct Node;

int n, m;
vector<Node> nodes;

struct Group {
    int win;
    ll adv;

    Group(int win = -1, ll adv = 0) : win(win), adv(adv) {}

    Group operator+(const Group &o) const {
        return Group(o.win + win, adv + o.adv);
    }

    Group finalize() const {
        return Group(win + (adv > 0), 0);
    }

    bool operator<(const Group &o) const {
        return win < o.win || (win == o.win && adv < o.adv);
    }

};

/*
 * Merge two partitions given the optimal # of wins/advantage for 1...p1.size groups (head node)
 * and 1...p2.size groups (child node)
 */
vector<Group> mergePartitions(const vector<Group> &p1, const vector<Group> &p2) {
    vector<Group> partitions = vector<Group>(min(p1.size() + p2.size() - 1, m + 2u));
    for (auto i = 1u; i < p1.size(); i++) {
        for (auto j = 1u; j < p2.size() && i + j < partitions.size(); j++) {
            partitions[i + j - 1] = max(partitions[i + j - 1], p1[i] + p2[j]); //merge
            partitions[i + j] = max(partitions[i + j], p1[i] + p2[j].finalize()); //split
        }
    }
    return partitions;
}

struct Node {
    int ind;
    ll diff;
    vector<int> neighbors;
    vector<Group> partitions;

    void search(int pInd) {
        partitions.push_back(Group(0, 0));
        partitions.push_back(Group(0, diff));
        for (int c : neighbors) {
            if (c != pInd) {
                Node child = nodes[c];
                child.search(ind);
                partitions = mergePartitions(partitions, child.partitions);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases, tmp;
    cin >> cases;
    for (int t = 0; t < cases; t++) {
        cin >> n >> m;
        nodes = vector<Node>(n, Node());
        for (int i = 0; i < n; i++) {
            nodes[i].ind = i;
            cin >> tmp;
            nodes[i].diff -= tmp;
        }
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            nodes[i].diff += tmp;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a - 1].neighbors.push_back(b - 1);
            nodes[b - 1].neighbors.push_back(a - 1);
        }
        nodes[0].search(-1);
        cout << nodes[0].partitions[m].finalize().win << "\n";
    }
    return 0;
}