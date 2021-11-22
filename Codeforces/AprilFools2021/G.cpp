# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pa(vi& a){
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vi a(5);
    int n = 0;
    for (int i = 0; i < 27; i++) {
       a[0] = i%3;
       a[1] = (i/3)%3;
       a[2] = (i/9)%3;
       for(int j = 0; j < 16; j++){
           a[3] = j%4;
           a[4]= (j/4)%4;
           if(a[0]+a[1]+a[2]==a[3]+a[4] && a[0] >){
               n++;
               pa(a);
           }
       }
    }
    cout << n;

    return 0;
}