# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct Node;
struct Community;

void add(Community &c, int i);

void remove(Community &c, int i);

int n;
int eTotal;
vector<Node *> graph;
vector<Community *> communities(0);

struct Node {
    int index;
    vector<Node *> edges;
    int community = -1;

    void assignCommunity(int comInd) {
        if (community != -1) {
            remove(*communities[community], index);
        }
        add(*communities[comInd], index);
        community = comInd;
    }
};

struct Community {
    set<int> elements = set<int>();
    int sumDegree = 0;
    int eIn = 0;

    bool inSet(int ind) {
        return elements.find(ind) != elements.end();
    }

    pii countAdj(int i) {
        int degree = 0;
        int eTouchIn = 0;
        for (Node *no: graph[i]->edges) {
            degree++;
            if (inSet(no->index)) {
                eTouchIn++;
            }
        }
        return pii(degree, eTouchIn);
    }

    double score() {
        double mod = (eIn + 0.0) / eTotal - pow(sumDegree / (2.0 * eTotal), 2);
        double density = (2.0 * eIn) / (elements.size() * (elements.size() - 1));
        double reg = .5 * (density / communities.size() - (1.0 * communities.size()) / n);
        return mod + reg;
    }
};

void add(Community &c, int i) {
    c.elements.insert(i);
    pii stats = c.countAdj(i);
    c.sumDegree += stats.first*2;
    c.eIn += stats.second;
}

void remove(Community &c, int i) {
    c.elements.erase(i);
    pii stats = c.countAdj(i);
    c.sumDegree -= stats.first*2;
    c.eIn -= stats.second;
}

int ccSize(int element) {
    queue<int> Q;
    vector<int> distances(n, -1);
    Q.push(element);
    distances[element] = 0;
    int size = 0;
    while (!Q.empty()) {
        int top = Q.front();
        Q.pop();
        size++;
        for (Node *no: graph[top]->edges) {
            if (distances[no->index] == -1) {
                distances[no->index] = distances[top] + 1;
                Q.push(no->index);
            }
        }
    }
    return size;
}

int furthest(vector<int> from) {
    queue<int> Q;
    vector<int> distances(n, -1);
    for (int i = 0; i < from.size(); i++) {
        Q.push(from[i]);
        distances[from[i]] = 0;
    }
    int top = 0;
    while (!Q.empty()) {
        top = Q.front();
        Q.pop();
        for (Node *no: graph[top]->edges) {
            if (distances[no->index] == -1) {
                distances[no->index] = distances[top] + 1;
                Q.push(no->index);
            }
        }
    }
    return top;
}

int assignDefault(vector<int> from) {
    queue<int> Q;
    vector<int> distances(n, -1);
    for (int i = 0; i < from.size(); i++) {
        Q.push(from[i]);
        distances[from[i]] = 0;
    }
    int top = 0;
    while (!Q.empty()) {
        top = Q.front();
        Q.pop();
        for (Node *no: graph[top]->edges) {
            if (distances[no->index] == -1) {
                distances[no->index] = distances[top] + 1;
                graph[no->index]->assignCommunity(graph[top]->community);
                Q.push(no->index);
            }
        }
    }
    return top;
}

int solveCC(int element, int cStartInd) {
    int sizeOfV = ccSize(element);
    int nCommunities = max(1, min(sizeOfV, (int) pow(sizeOfV, .2)));
    cout << sizeOfV << endl;
    for (int i = 0; i < nCommunities; i++) {
        communities.push_back(new Community());
    }
    vector<int> starts(1, element);
    graph[starts[0]]->assignCommunity(cStartInd);
    for (int i = 1; i < nCommunities; i++) {
        starts.push_back(furthest(starts));
        graph[starts[i]]->assignCommunity(i + cStartInd);
    }
    assignDefault(starts);
    double score = 0;
    for (int i = 0; i < nCommunities; i++) {
        score += communities[i]->score();
    }
    cout << "\nPrior score: " << (score+1)*100000 << endl;
    for(int i = 0; i < n; i++){
        for(Node* adj : graph[i]->edges){
            int ind1 = adj->community;
            int ind2 = graph[i]->community;
            if(ind1 != ind2){
                Community* c1 = communities[ind1];
                Community* c2 = communities[ind2];
                double curScore = c1->score() + c2->score();
                adj->assignCommunity(ind2);
                double twoScore = c1->score() + c2->score();
                adj->assignCommunity(ind1);
                graph[i]->assignCommunity(ind1);
                double oneScore = c1->score() + c2->score();
                if(!(oneScore>twoScore && oneScore > curScore)){
                    graph[i]->assignCommunity(ind2);
                    if(curScore < oneScore){
                        graph[i]->assignCommunity(ind1);
                    }
                }
            }
        }
    }
    cout << "End score: " << (score+1)*100000 << endl;
    return cStartInd + nCommunities;
}

void solve() {
    int cStart = 0;
    int st = furthest(vector<int>(1, 0));
    for (int j = 0; j < n; j++) {
        int i = (j + st) % n;
        if (graph[i]->community == -1) {
            cStart = solveCC(i, cStart);
        }
    }
}

void readGraph(int test) {
    ifstream in;
    in.open("C:/Users/Alex Li/CLionProjects/ProgrammingContests/CLion/a" + to_string(test) + ".in");
    in.tie(nullptr);
    vector<pii> input;
    eTotal = 0;
    n = 0;
    while (in.good()) {
        int a, b;
        in >> a;
        in >> b;
        input.push_back(pii(a, b));
        n = max(n, max(a, b));
        eTotal++;
    }
    graph = vector<Node *>(++n);
    for (int i = 0; i < n; i++) {
        graph[i] = new Node();
        graph[i]->index = i;
    }
    for (int i = 0; i < input.size(); i++) {
        graph[input[i].first]->edges.push_back(graph[input[i].second]);
        graph[input[i].second]->edges.push_back(graph[input[i].first]);
    }
    in.close();
}

void outputGraph(int test) {
    ofstream out;
    out.tie(nullptr);
    out.open("C:/Users/Alex Li/CLionProjects/ProgrammingContests/CLion/GraphMiningChallenge/a" + to_string(test) + ".out");
    cout << "OUTPUT: " << communities.size() << "\n";
    for (int i = 0; i < communities.size(); i++) {
        cout << communities[i]->elements.size() << " " << communities[i]->eIn << " ";
        cout << communities[i]->sumDegree << "\n";
        for (int j : communities[i]->elements) {
            out << j << " ";
        }
        out << "\n";
    }
    out.close();
}

int main() {
    ios::sync_with_stdio(false);
    int i = 1;
    readGraph(i);
    solve();
    outputGraph(i);
    return 0;
}