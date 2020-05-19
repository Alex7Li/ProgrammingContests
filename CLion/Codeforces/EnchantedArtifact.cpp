# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1282/D
using namespace std;

int query(vector<char> q) {
    for (char c: q) {
        cout << c;
    }
    cout << endl;
    int response;
    cin >> response;
    if (response <= 0) {
        exit(0);
    }
    return response;
}

template<class T> void insertAt(vector<T>& v, T val, int ind) {
    v.push_back(val);
    for (int i = v.size()-2; i >= ind; i--) {
        v[i+1] = v[i];
    }
    v[ind] = val;
}
template<class T> void removeAt(vector<T>& v, int ind) {
    for (unsigned int i = ind; i < v.size(); i++) {
        v[i] = v[i + 1];
    }
    v.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    int l = query({'a'})+1;
    if(l==301){
        query(vector<char>(300, 'b'));
    }
    vector<char> allAs(l, 'a');
    int numAs = l - query(allAs);
    vector<char> solution(numAs, 'a');
    int ind = 0;
    int last = l - numAs;
    while(ind <= l){
        insertAt(solution, 'b', ind);
        int cur = query(solution);
        if (cur >= last) {
            // not a good choice
            removeAt(solution, ind);
        }else {
            last = cur;
        }
        ind++;
    }
    return 0;
}