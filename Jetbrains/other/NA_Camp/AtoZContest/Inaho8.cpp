#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 1'000'000'007;
int K;
int get_gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return get_gcd(b, a % b);
    }
}

struct value_struct {
    int maximum;
    int minimum;
    int64_t sum;
    int64_t product;
    int gcd;
    int AND;
    int OR;
    int XOR;
    int aboveK;
    int belowK;
    int minvMinusK;
    int minKMinusv;

    value_struct(int value) {
        maximum = minimum = value;
        sum = value;
        product = value % MOD;
        gcd = AND = OR = XOR = value;
        aboveK = belowK = 0;
        minvMinusK = max(value, K);
        minKMinusv = min(value, K);
        if (value > K) {
            aboveK++;
        }
        if (value < K) {
            belowK++;
        }
    }
    value_struct() {
        maximum = numeric_limits<int>::min();
        minimum = numeric_limits<int>::max();
        sum = 0;
        product = 1;
        AND = (1 << 30) - 1;
        gcd = OR = XOR = 0;
        aboveK = belowK = 0;
        minvMinusK = K;
        minKMinusv = K;
    }
    bool is_empty() const {
        return maximum == numeric_limits<int>::min();
    }
};

value_struct value_merge(const value_struct &a, const value_struct &b) {
    value_struct c;
    c.maximum = max(a.maximum, b.maximum);
    c.minimum = min(a.minimum, b.minimum);
    c.sum = a.sum + b.sum;
    c.product = (a.product * b.product) % MOD;
    c.gcd = get_gcd(a.gcd, b.gcd);
    c.AND = a.AND & b.AND;
    c.OR = a.OR | b.OR;
    c.XOR = a.XOR ^ b.XOR;
    c.belowK = a.belowK + b.belowK;
    c.aboveK = a.aboveK + b.aboveK;
    if(a.aboveK) {
        if(b.aboveK) {
            c.minvMinusK = min(a.minvMinusK, b.minvMinusK);
        } else {
            c.minvMinusK = a.minvMinusK;
        }
    }else{
        c.minvMinusK = b.minvMinusK;
    }
    c.minKMinusv = a.belowK ? (b.belowK ? max(a.minKMinusv, b.minKMinusv) : a.minKMinusv) : b.minKMinusv;
    return c;
}

struct segment_change {
    // TODO: make sure the default constructor is the identity segment_change.
    value_struct value;
    explicit segment_change() {
        value = value_struct();
    }
    explicit segment_change(int val) {
        value = value_struct(val);
    }
    explicit segment_change(value_struct value_st){
        value = value_st;
    }
    void reset() {
        value = value_struct();
    }
    bool has_change() const {
        return !value.is_empty();
    }

    // Return the combined result of applying this segment change followed by `other`.
    // TODO: make sure to check for sentinel values.
    segment_change combine(const segment_change &change) const {
        return segment_change(value_merge(this->value, change.value));
    }
};

struct segment {
    value_struct value;
    // TODO: make sure the default constructor is the identity segment.
    explicit segment(int val = -1) {
        if(val == -1){
            this->value = value_struct();
        } else {
            this->value = value_struct(val);
        }
    }
    bool empty() const {
        return value.is_empty();
    }
    void apply(int length, const segment_change &change) {
        value = value_merge(change.value, value);
    }
    void join(const segment &other) {
        if (empty()) {
            *this = other;
            return;
        } else if (other.empty()) {
            return;
        }
        this->value = value_merge(this->value, other.value);
    }
    // TODO: decide whether to re-implement this for better performance. Mainly relevant when segments contain arrays.
    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

pair<int, int> right_half[32];

struct seg_tree {
    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;
    seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }
    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }
    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }
    void apply_and_combine(int position, int length, const segment_change &change) {
        tree[position].apply(length, change);

        if (position < tree_n)
            changes[position] = changes[position].combine(change);
    }
    void push_down(int position, int length) {
        if (changes[position].has_change()) {
            apply_and_combine(2 * position, length / 2, changes[position]);
            apply_and_combine(2 * position + 1, length / 2, changes[position]);
            changes[position].reset();
        }
    }
    // Calls push_down for all necessary nodes in order to query the range [a, b).
    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = highest_bit(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }
    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }
    // Calls join for all necessary nodes after updating the range [a, b).
    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;

        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }
    template<typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1)
                range_op(a++, length);

            if (b & 1)
                right_half[r_size++] = {--b, length};
        }

        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i].first, right_half[i].second);

        if (needs_join)
            join_all(original_a, original_b);
    }
    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }
    segment query_full() const {
        return tree[1];
    }
    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(a, b, true, [&](int position, int length) {
            apply_and_combine(position, length, change);
        });
    }
};

struct subtree_heavy_light {
    int n = 0;
    bool vertex_mode;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> tour_start, tour_end;
    vector<int> chain_root;
    seg_tree full_tree;
    subtree_heavy_light() {}
    subtree_heavy_light(int _n, bool _vertex_mode) {
        init(_n, _vertex_mode);
    }
    void init(int _n, bool _vertex_mode) {
        n = _n;
        vertex_mode = _vertex_mode;

        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);

        tour_start.resize(n);
        tour_end.resize(n);
        chain_root.resize(n);
    }
    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;

        // Erase the edge to parent.
        adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());

        for (int child : adj[node]) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }

        // Heavy-light subtree reordering.
        sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
            return subtree_size[a] > subtree_size[b];
        });
    }
    int tour;
    void chain_dfs(int node, bool heavy) {
        chain_root[node] = heavy ? chain_root[parent[node]] : node;
        tour_start[node] = tour++;
        bool heavy_child = true;

        for (int child : adj[node]) {
            chain_dfs(child, heavy_child);
            heavy_child = false;
        }

        tour_end[node] = tour;
    }
    void build(const segment &initial) {
        tour = 0;
        parent.assign(n, -1);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                dfs(i, -1);
                chain_dfs(i, false);
            }

        full_tree.init(n);
        full_tree.build(vector<segment>(n, initial));
    }
    template<typename T_tree_op>
    int process_path(int u, int v, T_tree_op &&op) {
        while (chain_root[u] != chain_root[v]) {
            // Always pull up the chain with the deeper root.
            if (depth[chain_root[u]] > depth[chain_root[v]])
                swap(u, v);

            int root = chain_root[v];
            op(full_tree, tour_start[root], tour_start[v] + 1);
            v = parent[root];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        // u is now an ancestor of v.
        op(full_tree, tour_start[u] + (vertex_mode ? 0 : 1), tour_start[v] + 1);
        return u;
    }
    int get_lca(int u, int v) {
        return process_path(u, v, [&](seg_tree &, int, int) {});
    }
    segment query_path(int u, int v) {
        segment answer;

        process_path(u, v, [&](seg_tree &tree, int a, int b) {
            answer.join(tree.query(a, b));
        });

        return answer;
    }
    void update_path(int u, int v, const segment_change &change) {
        process_path(u, v, [&](seg_tree &tree, int a, int b) {
            tree.update(a, b, change);
        });
    }
};

int main() {
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q >> K;
    subtree_heavy_light HLD(N, true);
    vector<pair<int, int>> edges;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        HLD.add_edge(a, b);
        edges.emplace_back(a, b);
    }

    HLD.build(segment());
    for (int i = 0; i < N; ++i) {
        HLD.update_path(i, i, segment_change(v[i]));
    }
    int root = 1;
    for (int q = 0; q < Q; q++) {
        int type, a, b;
        cin >> type >> a;
        a--;

        if (type != 1) {
            cin >> b;
            b--;
        }
        if(type == 1){
            root = a + 1;
        }else if(type == 2){
            cout << root << endl;
        } else {
            value_struct query_valu = HLD.query_path(a, b).value;
            int64_t ans = 0;
            // cout << type << " ";
            switch(type){
                case 3: ans = query_valu.sum; break;
                case 4: ans = query_valu.product; break;
                case 5: ans = query_valu.minimum; break;
                case 6: ans = query_valu.maximum; break;
                case 7: ans = query_valu.gcd; break;
                case 8: ans = query_valu.AND; break;
                case 9: ans = query_valu.OR; break;
                case 10: ans = query_valu.XOR; break;
                case 11: ans = query_valu.aboveK; break;
                case 12: ans = query_valu.belowK; break;
                case 13: ans = query_valu.minvMinusK; break;
                case 14: ans = query_valu.minKMinusv; break;
                default: assert(false);
            }
            cout << ans << endl;
        }
    }
}
