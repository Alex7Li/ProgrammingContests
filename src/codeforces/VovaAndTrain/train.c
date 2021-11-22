/*http://codeforces.com/problemset/problem/1066/A*/
#include <stdio.h>
#include <stdlib.h>

int solve(){
	int length;
	int interval;
	int l;
	int r;
	int ans;
	scanf("%i", &length);
	scanf("%i", &interval);
	scanf("%i", &l);
	scanf("%i", &r);
	ans =length/interval;
	ans -= (r)/interval;
	ans += (l-1)/interval;
	return ans;
}

int main(){
	int i;
	int tests;
	scanf("%i", &tests);
	for (i = 0; i < tests; ++i)
	{
		printf("%i\n", solve());
	}
	return 1;
}