# include <bits/stdc++.h>
//https://open.kattis.com/problems/communicationssatellite
using namespace std;

int getComponent(int i, vector<int> &component) {
    if (i == component[i]) {
        return i;
    } else {
        int ans = getComponent(component[i], component);
        component[i] = ans;
        return ans;
    }
}

void shareComp(int i, int j, vector<int> &component) {
    component[getComponent(j, component)] = getComponent(i, component);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<double, double, double>> ants;
    for (int i = 0; i < n; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        ants.push_back(make_tuple(x, y, r));
    }
    vector<tuple<int, int, double>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = hypot(get<0>(ants[i]) - get<0>(ants[j]), get<1>(ants[i]) - get<1>(ants[j]))
                       - get<2>(ants[i]) - get<2>(ants[j]);
            edges.push_back(make_tuple(i, j, d));
        }
    }
    sort(edges.begin(), edges.end(), [](auto const &a, auto const &b) { return get<2>(a) < get<2>(b); });
    vector<int> component = vector<int>(n);
    for (int i = 0; i < n; i++) {
        component[i] = i;
    }
    double score = 0;
    for (auto e : edges) {
        int i = get<0>(e);
        int j = get<1>(e);
        int c0 = getComponent(i, component);
        int c1 = getComponent(j, component);
        if (c0 != c1) {
            shareComp(c0, c1, component);
            score += get<2>(e);
        }
    }
    printf("%.8f\n", score);
    return 0;
}
