#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 111;
const int M = 30303;
ll a[N][2];
int m;

bool trySolve(ll prod, ll sum) {
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        while(prod % a[i][0] == 0) {
            prod /= a[i][0];
            sum -= a[i][0];
            cnt++;
        }
        if (cnt > a[i][1]) return false;
    }
    return prod == 1 && sum == 0;
}

ll solve() {
    ll sum = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &a[i][0], &a[i][1]);
        sum += a[i][0] * a[i][1];
    }
    for (ll x = 1; x < sum && x < M; x++) {
        if (trySolve(sum - x, x)) return sum - x;
    }
    return 0;
}

int main()
{
    startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: %lld\n", i, solve());
    }

    return 0;
}
