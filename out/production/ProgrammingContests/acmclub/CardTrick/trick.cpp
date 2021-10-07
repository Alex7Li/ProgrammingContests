#include <bits/stdc++.h>

//https://open.kattis.com/contests/etuthv/problems/cardtrick2
int optimalpartition.datastructures.disjointsetunion.math.implementation.main() {
	int tricks, cards;
	scanf("%i", &tricks);
	for (int i = 0; i < tricks; ++i)
	{
		scanf("%i", &cards);
		int deck[cards] = {};
		int top = -1;
		for (int i = 1; i <= cards; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				do{
					top = (top+1)%cards;
				}while(deck[top]!=0);
			}
			deck[top] = i;
		}
		for (int i = 0; i < cards; ++i)
		{
			printf("%i", deck[i]);
			if(i!=cards-1){
				printf(" ");
			}
		}
		printf("\n");
	}
}
