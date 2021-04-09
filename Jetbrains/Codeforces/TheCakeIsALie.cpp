# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1282/E
using namespace std;
deque<int> enumeration;
deque<int> cutOrder;

struct Edge {
    Edge(int from, int to, int ind) : from(from), to(to), ind(ind) {}

    int from, to, ind;
    shared_ptr<Edge> nxt = nullptr;//next edge
    shared_ptr<Edge> rev = nullptr; //edge in reverse direction
    shared_ptr<Edge> flip = nullptr; //flip to other side of line
};

void search(shared_ptr<Edge> e, int end){
    //    cout << e->from << " " << e->to;
    if (e->flip == nullptr) {
        //        cout << " " << "!" << endl;
        enumeration.push_back(e->from);
        if (e->to != end) {
            search(e->nxt, end);
        }
    } else {
        //        cout << endl;
        search(e->flip->rev->nxt, e->to);
        if(e->to!=end) {
            search(e->nxt, end);
        }
    }
    if (e->to == end) {
        cutOrder.push_back(e->ind);
    }
}

auto hashf = [](pair<int, int> p) {
    return p.first + (p.second << 15);
};

unordered_map<pair<int, int>, shared_ptr<Edge>, decltype(hashf)> edgeSet(1000, hashf);

shared_ptr<Edge> addFlip(shared_ptr<Edge> e) {
    pair<int, int> p(e->from, e->to);
    shared_ptr<Edge> flip = edgeSet[p];
    if (flip == nullptr) {
        edgeSet[p] = e;
    } else {
        assert(flip->flip == nullptr);
        e->flip = flip;
        flip->flip = e;
    }
    return e;
}

void addTriangle(int a, int b, int c, int i) {
    shared_ptr<Edge> e1, e2, e3, e1r, e2r, e3r;
    e1 = make_shared<Edge>(a, b, i);
    e2 = make_shared<Edge>(b, c, i);
    e3 = make_shared<Edge>(c, a, i);
    e1->nxt = e2;
    e2->nxt = e3;
    e3->nxt = e1;

    e1r = make_shared<Edge>(b, a, i);
    e2r = make_shared<Edge>(c, b, i);
    e3r = make_shared<Edge>(a, c, i);
    e1r->nxt = e3r;
    e2r->nxt = e1r;
    e3r->nxt = e2r;

    e1->rev = e1r;
    e2->rev = e2r;
    e3->rev = e3r;
    e1r->rev = e1;
    e2r->rev = e2;
    e3r->rev = e3;
    addFlip(e1);
    addFlip(e2);
    addFlip(e3);
    addFlip(e1r);
    addFlip(e2r);
    addFlip(e3r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    cin >> t;
    for (int caseNum = 0; caseNum < t; caseNum++) {
        cin >> n;
        enumeration.clear();
        cutOrder.clear();
        edgeSet.clear();
        for (int i = 1; i <= n - 2; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            addTriangle(a, b, c, i);
        }
        shared_ptr<Edge> e1 = edgeSet.begin()->second;
        search(e1, e1->from);
        for (auto e: enumeration) {
            cout << e << " ";
        }
        cout << "\n";
        for (auto e: cutOrder) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}