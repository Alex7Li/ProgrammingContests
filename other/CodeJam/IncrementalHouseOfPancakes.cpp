# include <bits/stdc++.h>
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019ffb9/00000000003384ea
using namespace std;
# define rep(i, a, b) for(int i = a; i < (b); ++i)
# define trav(a, x) for(auto& a : x)
# define all(x) begin(x), end(x)
# define sz(x) (int)(x).size()
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

//2 + 4 + ... + 2*(M/2)
ll sumEveryOtherEven(ll M) {
    return ((M / 2) * (M / 2 + 1));
}

//1 + 3 + ... + 2*(M/2)-1
ll sumEveryOtherOdd(ll M) {
    return sumEveryOtherEven(M+1) - (M+1) / 2;
}

// st + (st+2) + ... + end or end-1
ll sumEveryOtherFrom(ll st, ll end) {
    if (st % 2 == 0) {
        return sumEveryOtherEven(end) - sumEveryOtherEven(st - 2);
    } else {
        return sumEveryOtherOdd(end) - sumEveryOtherOdd(st - 2);
    }
}

ll sumEvery(ll end) {
    return (end * (end + 1)) / 2;
}

ll sumTo(ll st, ll end) {
    return sumEvery(end) - sumEvery(st - 1);
}

// minimal i such that stR + (stR + 2) + ... + i > h
int findT(ll stR, ll h) {
    ll minI = 0;
    ll maxI = 6;//1'500'000'000;
    while (minI + 1 < maxI) {
        ll mid = (maxI + minI) / 2;
        if (sumEveryOtherFrom(stR, mid) > h) {
            maxI = mid - 1;
        } else {
            minI = mid;
        }
    }
    while (sumEveryOtherFrom(stR, minI + 1) <= h) {
        minI = minI + 1;
    }
    return minI;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(tt, 1, t + 1) {
        bool swapped = false;
        cout << "Case #" << tt << ": ";
        ll l, r;
        cin >> l >> r;
        if (l < r) {
            ll temp = l;
            l = r;
            r = temp;
            swapped = true;
        }
        ll i = 1;
        while (l - i >= r){
            l -= i;
            i++;
        }
        if( l == r && swapped){
            swapped = false;
        }
        int stL = i;
        int stR = i + 1;
        int t1 = findT(stL, l);
        int t2 = findT(stR, r);
        int t3 = min(t1, t2);
        int endR = r - sumEveryOtherFrom(stR, t3);
        int endL = l - sumEveryOtherFrom(stL, t3);
        if (swapped) {
            swap(endL, endR);
        }
        cout << t3 << " " << endL << " " << endR << "\n";
    }
    return 0;
}