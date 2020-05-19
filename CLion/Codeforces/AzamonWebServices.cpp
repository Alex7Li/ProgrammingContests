# include <bits/stdc++.h>
//https://codeforces.com/contest/1281/problem/B
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    for(int t =0; t < cases; t++) {
        string s, c;
        cin >> s >> c;
        int min[s.length()];
        min[s.length() - 1] = s[s.length() - 1];
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s[i] < min[i + 1]) {
                min[i] = s[i];
            } else {
                min[i] = min[i + 1];
            }
        }
        unsigned int stIndex = 0;
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[stIndex] == min[i]) {
                stIndex++;
            }else{
                break;
            }
        }
        int minIndex = stIndex;
        for (unsigned int i = stIndex + 1; i < s.length(); i++) {
            if (s[minIndex] >= s[i]) {
                minIndex = i;
            }
        }
        if (stIndex != s.length()) {
            int temp = s[stIndex];
            s[stIndex] = s[minIndex];
            s[minIndex] = temp;
        }
        if(s.compare(c)< 0){
            cout << s << "\n";
        }else{
            cout << "---\n";
        }
        cout << endl;
    }
    return 0;
}