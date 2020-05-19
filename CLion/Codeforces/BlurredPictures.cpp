# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//http://codeforces.com/gym/102465
bool fits(int q, int N, int *rowmins, int *rowmaxes, int *colmins, int *colmaxes){
    bool finished;
    int min_i = 0, max_i = N-1;
    int min_j = 0, max_j = N-1;

    while (1){
        finished = true;
        // Check bottom row.
        if(min(rowmaxes[min_i], max_j)-max(rowmins[min_i], min_j) + 1 < q){
            // top
            min_i++;
            finished = false;
        }
        else if(min(rowmaxes[max_i], max_j)-max(rowmins[max_i], min_j) + 1 < q){
            // bottom
            max_i--;
            finished = false;
        }
        if(min(colmaxes[min_j], max_i)-max(colmins[min_j], min_i) + 1 < q){
            // left
            min_j++;
            finished = false;
        }
        else if(min(colmaxes[max_j], max_i)-max(colmins[max_j], min_i) + 1 < q){
            // right
            max_j--;
            finished = false;
        }
        if (max_j - min_j + 1 < q || max_i - min_i + 1 < q){
            // too small
            return false;
        }
        if(finished){
            //big enough, no more to do.
            return true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int rowmins[N];
    int rowmaxes[N];
    int colmins[N];
    int colmaxes[N];

    for(int i=0; i<N; i++){
        cin >> rowmins[i];
        cin >> rowmaxes[i];
    }

    // COLMINS
    for(int j=rowmins[0]; j <= rowmaxes[0]; j++){
        colmins[j] = 0;
    }
    for(int i=1; i<N; i++){
        for(int j=rowmins[i-1]-1; j>=rowmins[i]; j--) {
            colmins[j] = i;
        }
        for(int j=rowmaxes[i-1]+1; j<=rowmaxes[i]; j++){
            colmins[j] = i;
        }
    }

    // COLMAXES
    for(int j=rowmins[N-1]; j <= rowmaxes[N-1]; j++){
        colmaxes[j] = N-1;
    }
    for(int i=N-2; i>=0; i--){
        for(int j=rowmins[i+1]-1; j>=rowmins[i]; j--) {
            colmaxes[j] = i;
        }
        for(int j=rowmaxes[i+1]+1; j<=rowmaxes[i]; j++){
            colmaxes[j] = i;
        }
    }

    int lo = 0, hi = N;

    while (lo < hi){
        int mid = (lo + hi + 1) / 2;
        if (fits(mid, N, rowmins, rowmaxes, colmins, colmaxes)){
//            cout << mid << " fits." << endl;
            lo = mid;
        } else {
//            cout << mid << " does not fit." << endl;
            hi = mid - 1;
        }
    }

    cout << lo;

    return 0;
}