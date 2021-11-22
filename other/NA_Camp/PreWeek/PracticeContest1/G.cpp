# include <bits/stdc++.h>
#include  <iostream>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, string> dict;
    string key;
    string value;
    string str;
    string line;
    getline(cin, line);
    while (!line.empty()) {
        stringstream line_stream(line);
        line_stream >> value >> key;
        dict[key] = value;
        getline(cin, line);
    }
    string word;
    getline(cin, line);
    while (!line.empty()) {
        stringstream line_stream(line);
        line_stream >> word;
        if (dict.end() == dict.find(word)) {
            cout << "eh\n";
        } else {
            cout << dict[word] << "\n";
        }
        getline(cin, line);
    }
    cout << endl;
    return 0;
}