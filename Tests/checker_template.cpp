# include <bits/stdc++.h>

using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    string fname;
    cin >> fname;
    ifstream infile("../Input/" + fname);
    ifstream outfile("../Output/" + fname);
    // If you are running the file with Clion rather than
    // the bash script, use
    // ifstream infile("../Tests/Input/" + fname);
    // ifstream outfile("../Tests/Output/" + fname);

    int n, m;
    infile >> n;
    outfile >> m;


    infile.close();
    outfile.close();
    return 0;
}
