# include <bits/stdc++.h>
//https://codeforces.com/contest/290/problem/C
using namespace std;

int main() {
    int tux = 0;
    cin >> tux;
    int foo = 0;
    int bar = 0;
    int baz = 0;
    int quz = 1;
    for(;tux!=0; tux--){
        int pur;
        cin >> pur;
        foo = foo+pur;
        bar++;
        bool it = (max(foo*quz, bar*baz)==foo*quz);
        if(it){
            baz = foo;
            quz = bar;
        }
    }
    cout << (float)(baz)/quz << endl;
    return 0;
}