# include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, k;
    cin >> t >> k;
    int pos = 0;
    for(int i = 2; i <= t; i++){
        pos = (pos + k) % i;
    }
    cout << pos << endl;
    return 0;
}
