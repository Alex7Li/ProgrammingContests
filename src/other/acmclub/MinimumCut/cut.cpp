#include <bits/stdc++.h>

//https://open.kattis.com/contests/etuthv/problems/mincut
using namespace std;

struct edge {
	int to;
	int capacity;
	int flow;
	edge* reverse;
};
const int maxN = 500;

vector<edge*> adj_list[maxN];
bool seen[maxN];

/*Find a path from s to t, and reroute as
much flow through it as possible (under min_cap, at least min edge).
return amount of flow rerouted, or 0 for failure*/
int reroute_flow(int s, int t, int min_cap, int min_edge){
	seen[s] = true;
	for(edge* e: adj_list[s]){
		if(!seen[e->to]){
			int flow_left = e->capacity - e->flow;
			if(flow_left>=min_edge){
				min_cap = min(min_cap,flow_left);
				if(e->to!=t){
					min_cap = reroute_flow(e->to, t, min_cap, min_edge);
				}
				printf("This node  %i\n", s);
				printf("Next node  %i\n", e->to);
				printf("Cap %i Flow %i\n", e->capacity, e->flow);

				printf("Rerouted units of flow:  %i\n", min_cap);
				e->flow+=min_cap;
				e->reverse->flow-=min_cap;
				return min_cap;
			}
		}
	}
	printf("%i%i\n", s,t);
	return 0;
}

int optimalpartition.datastructures.disjointsetunion.math.implementation.main() {
	int n,m,s,t;
	int u,v,w;
	scanf("%i%i%i%i", &n, &m ,&s, &t);

	//adj_list[i] is a vector containing all the edges from node i
	for (int i = 0; i < m; ++i)
	{
		printf("%i%i%i\n", u,v,w);
		edge e1 = edge{v,w,0};
		edge e2 = edge{u,w,0,&e1};
		e1.reverse = &e2;
		adj_list[u].push_back(&e1);
		adj_list[v].push_back(&e2);
	}
	for (int i = 0; i < 4; ++i)
	{
		printf("%s%i\n", "Edge ", i);
		for(edge* e:adj_list[i]){
			printf("Cap %i Flow %i\n", e->capacity, e->flow);
			printf("To %i Back %i\n", e->to, e->reverse->to);
		}
	}
	printf("%s\n", "Input Scanned");
	for (int c = pow(10,8); c > 0; c/=2)
	{
		// Find paths s->t where all edges have weight at least c.
		do{
			for(bool b:seen){
				b = false;
			}
			printf("%s%i\n", "Looking for flow at least ", c);
		}while(reroute_flow(s,t, 200000000, c)!=0);
	}

	for(bool b:seen){
		b = false;
	}
	
	//set to be returned, obviously it's not a set
	vector<int> set;
	set.push_back(s);
	seen[s] = true;
	printf("%s %i\n", "Creating set, size ", set.size());
	for(int i = 0; i < set.size(); i++){
		printf("%i",set[i]);
		for(edge* e: adj_list[set[i]]){
			if(!seen[e->to]){
				seen[e->to] = true;
				printf("%i\n", e->to);
				printf("%i\n", e->flow);
				printf("%i\n", e->capacity);
				if(e->flow!=e->capacity){
					printf("%s\n", " adding edge ");
					set.push_back(e->to);
				}
			}
		}			
		printf("%s %i\n", "Creating set, size ", set.size());
	}
	printf("%i\n", set.size());
	for (int i = 0; i < set.size(); ++i)
	{
		printf("%i\n", set[i]);
	}
}
