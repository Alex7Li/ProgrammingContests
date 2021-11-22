# include <bits/stdc++.h>

using namespace std;
//https://codeforces.com/contest/1281/problem/A
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
       string nl;
       cin >> nl;
        unsigned int l = nl.length();
       if(nl.substr(l-2,l)=="po"){
           cout << "FILIPINO\n";
       }else if(nl.substr(l-4,l)=="desu" || nl.substr(l-4,l)=="masu"){
           cout << "JAPANESE\n";
       }else{
           cout << "KOREAN\n";
       }
    }
    return 0;
}