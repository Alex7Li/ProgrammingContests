# include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
//http://codeforces.com/gym/102465
auto hashUp = [](const pii& pair){
return hash<int>()(pair.first)^hash<int>()(pair.second);
};

unordered_map<pii, pii, decltype(hashUp)> parent(1000000,hashUp);
unordered_set<pair<int, int>, decltype(hashUp)> points(1000000, hashUp);
pii root(pii x) {
    while(parent.at(x) != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unionA(pii x, pii y){
    parent[root(x)] = parent[y];
}

unordered_map<pii, vector<pii>, decltype(hashUp)> getComponents(){
    for(auto& p:points){
        parent[p] = p;
    }

    for(auto& p:points){
        int i = p.first, j=p.second;
        auto n = pii(i+1, j+1);
        if(points.find(n) != points.end()){
            unionA(p, n);
            //cout << i << " " << j << endl;
        }
        n = pii(i, j+1);
        if(points.find(n) != points.end()){
            unionA( p, n);
        }
        n = pii(i-1, j+1);
        if(points.find(n) != points.end()){
            unionA(p, n);
        }
        n = pii(i-1, j);
        if(points.find(n) != points.end()){
            unionA(p, n);
        }
    }

    unordered_map<pii, vector<pii>, decltype(hashUp)> components(0, hashUp);
    for(auto& p:points){
        //cout << "processing " << p.first << " " << p.second << endl;
        auto rp = root(p);
        if(components.find(rp) == components.end()){
            components[rp] = vector<pii>(1, p);
            //cout << "new root" << rp.first << rp.second << endl;
        } else {
            components[rp].push_back(p);
        }
    }
    return components;
}

int detLetter(vector<pii>& comp) {
    if (comp.size() == 1) {
        return 0;
    }
    int mini=99999999, maxi=0, maxj=0, minj=99999999;
    for(pii& p : comp){
        mini = min(mini, p.first);
        maxi = max(maxi, p.first);
        maxj = max(maxj, p.second);
        minj = min(minj, p.second);
    }
    if(mini == 0){
        return 0;
    }
    int midi = (maxi+mini)/2;
    int midj = (maxj+minj)/2;
    bool c = false;
    bool a = false;
    for(pii& p : comp){
        if(p==pii(midi, maxj)){
            c = true;
        }
        if(p==pii(maxi, midj)){
            a = true;
        }
    }
    if(!c){
        return 3;
    }
    if(!a){
        return 1;
    }
    return 2;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cols, rows;
    cin >> cols >> rows;
    string lines[rows];

    for(int i=0; i<rows; i++){
        cin >> lines[i];
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(lines[i][j] == '#'){
                points.insert(pair<int, int>(i, j));
            }
        }
    }
    auto comps = getComponents();
    vector<int> v(4,0);
    for(auto& c: comps){
        vector<pii> p = c.second;
        v[detLetter(p)]++;
    }
    cout<< v[1] << " " << v[2] << " " << v[3] << endl;
    return 0;
}