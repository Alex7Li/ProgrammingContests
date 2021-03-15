# include <bits/stdc++.h>

using namespace std;

int main() {
    int K;
    cin >> K;
    // want 10^n = 1 (mod K)
    int n = 1;
    int rem = 10 % K;
    while (rem != 1 && n < K) {
        rem = (rem * 10) % K;
        cout << rem << "\n";
        n++;
    }
    if (n == K) {
        cout << -1;
    } else {
        cout << n;
    }
    return 0;
}