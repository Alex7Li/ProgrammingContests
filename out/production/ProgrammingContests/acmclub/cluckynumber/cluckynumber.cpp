#include <bits/stdc++.h>

//choose which of a,b,c are closest to goal.
int best(int goal, int a, int b, int c){
	if(abs(goal-a)>=abs(goal-b)){
		if(abs(goal-b)>abs(goal-c)){
			return c;
		}
		return b;
	}
	return a;
}

int best(int goal1, int goal2, int a, int b, int c){
	int v1 = best(goal1,a,b,c)
	int v2 = best(goal2,a,b,c)
	if(abs(v1-a)>=abs(v2-b)){
		return v1;
	}
	return v2;
}

int optimalpartition.datastructures.disjointsetunion.math.implementation.main() {
	int n, val;
	scanf("%i", &n);
	scanf("%i", &val);
	int nums[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%i", &nums[i]);
	}
	int min = -200;
	int max = 400;
	int dp[n+1][max-min];
	for (int i = 0; i < max-min; ++i)
	{
		dp[n][i]=i+min;
	}
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = 1; j < max-min-1; ++j)
		{
			dp[i][j] = best(nums[i], dp[i+1][j-1], 
				dp[i+1][j], dp[i+1][j+1]);
		}
	}
	printf("The number is: %d", dp[0][val-min]);
}
