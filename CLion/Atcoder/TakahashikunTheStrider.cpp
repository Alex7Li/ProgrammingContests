# include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(a==0){
        return b;
    }
    return gcd(b%a, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    cout << 360/gcd(x,360);
    return 0;
}