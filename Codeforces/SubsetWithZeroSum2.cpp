# include <bits/stdc++.h>

using namespace std;

int main() {
    int cases, n, i, j;
    cin >> cases;
    for(int t = 0; t < cases; ++t) {
        cin >> n;
        // input
        vector<int> input(n, 0);
        for (i = 0; i < n; i++) {
            cin >> input[i];
        }
        vector<int> path;
        //solution goes here
        for(i = 0; i < n; i++){
            input[i] = i - input[i];
        }
        int smallStep = 0; int bigStep = 0;
        for(;smallStep!=bigStep;) {
            smallStep = input[smallStep];
            bigStep = input[input[bigStep]];
        }
        path.push_back(smallStep+1);
        smallStep = input[smallStep];
        for(;smallStep!=bigStep; smallStep = input[smallStep]){
            path.push_back(smallStep+1);
        }
        //output
        cout << path.size() << "\n";
        for(i = 0; i < path.size(); i++){
           cout << path[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}