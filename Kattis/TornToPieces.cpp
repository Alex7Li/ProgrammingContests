# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<string, vector<string>> m;
    map<string, string> seen;
    for(int i = 0; i < n; i++){
        string input;
        getline(cin, input);
        int cur = input.find(" ");
        string st = input.substr(0, cur);
        m[st] = vector<string>(0);
        while(cur!=st.size()){
            int last = cur;
            cur = input.find(" ", cur);
            string end = input.substr(last, cur);
            for(int j = 0; j < m.size(); j++){
                m[st].push_back(end);
                if(m.find(end) == m.end()){
                    m[end] = vector<string>(0);
                }
                m[end].push_back(st);
            }
        }
    }
    string start;
    string end;
    cin >> start >> end;
    seen[start] = "!";
    vector<string> todo;
    todo.push_back(start);
    while(!todo.empty()){
        for()
    }
    if(seen[end]){

    }

    return 0;
}