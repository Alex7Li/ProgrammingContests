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
    vi a(4);
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
    }
    bool needSugar = a[0] < a[1];
    bool needPaste = a[2] < a[3];
    if(needSugar){
        if(needPaste){
            cout << "Go to the department store";
        } else {
            cout << "Go to the grocery store";
        }
    } else {
        if(needPaste){
            cout << "Go to the pharmacy";
        } else {
            cout << "Stay home";
        }
    }
    cout <<endl;


    return 0;
}