#include<bits/stdc++.h>
using namespace std;
#define A2 26
#define ll long long

char recipes [50009];

int optimalpartition.datastructures.disjointsetunion.math.implementation.main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n=0;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf(" %c",&recipes[i]);
	}
	ll aPow = 1;
	//assume any sequences of length over maxL are distinct
	ll maxL = min(13LL, n);
	ll ans = 2LL*(n-maxL)*n;
	for (int len = 1; len <= maxL; len++) {
		unordered_set<ll> hashes;
		ll curHash = 0;
		for (int i = 0; i < len; i++) {
			curHash = curHash*A2 + recipes[i];
		}
		for (int st = 0; st < n; st++) {
			hashes.insert(curHash);
			curHash -= aPow * recipes[st];
			curHash = curHash*A2 +recipes[(len + st) % n];
		}
		curHash = 0;
		for (int i = len - 1; i >= 0; i--) {
			curHash = curHash*A2 + recipes[i];
		}
		for (int st = n - 1; st >= 0; st--) {
			hashes.insert(curHash);
			curHash -= aPow * recipes[(st + len) % n];
			curHash = curHash*A2+recipes[st % n];
		}
		ans += hashes.size();
		aPow *= A2;
	}
	printf("%lld\n", ans);
	return 0;
}

