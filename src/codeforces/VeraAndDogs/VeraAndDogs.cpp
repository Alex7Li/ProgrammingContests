#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> assignment;
struct comparePair{
	bool operator()(const pair<int, int> &p1, const pair<int, int> &p2){
		return p1.first!=p2.first?p1.first>p2.first:p1.second<p2.second;
	}
};
int optimalpartition.datastructures.disjointsetunion.math.implementation.main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x;
	scanf("%d",&n);
	scanf("%d",&x);
	if((x+1)*(n-1)<x*n){
		printf("%d\n", -1);
	}else{
		for (int i = 0; i < n; ++i)
		{
			vector<int> v;
			for (int j = 0; j < x; ++j)
			{
				v.push_back(x*i+j+1);
			}
			assignment.push_back(v);
		}
		// queue for answer: length, index
		priority_queue<pair<int, int>, vector<pair<int, int>>, comparePair> Q;
		for (int i = 0; i < n; ++i)
		{
			Q.push(pair<int,int>(assignment[i].size(), i));
		}
		for (int i = 0; i < n; ++i)
		{
			vector<pair<int,int>> toAdd;
			for (int j = 0; j < x; ++j){
				pair<int,int> p = Q.top();
				Q.pop();
				if(p.second==i){
					pair<int,int> p2 = Q.top();
					Q.pop();
					Q.push(p);
					p = p2;
				}
				toAdd.push_back(p);
			}
			for(int j = 0; j < x; ++j)
			{
				int ind = toAdd[j].second;
				assignment[ind].push_back(assignment[i][j]);
				Q.push(pair<int,int>(assignment[ind].size(), ind));
			}
		}
		for (int i = 0; i < n; ++i)
		{
			printf("%d", assignment[i][0]);
			for (int j = 1; j < assignment[i].size(); ++j)
			{
				printf(" %d", assignment[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

