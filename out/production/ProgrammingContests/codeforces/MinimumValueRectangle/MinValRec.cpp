#include <bits/stdc++.h>
using namespace std;

//source: http://codeforces.com/problemset/problem/1027/C
string solve(int n, int arr[]){
	map<int,int> counts;
	for (int i = 0; i < n; ++i) {
		map<int,int>::iterator it = counts.find(i);
		counts[arr[i]]= counts[arr[i]]+1;
	}
	int last = -1;
	long long bestNumerator = 1;
	long long bestDenominator = 0;
	int a = -1;
	int b = -1;
	map<int,int>::iterator it; 
	for(it = counts.begin(); it!=counts.end(); it++){
		if(it->second>=4){
			return to_string(it->first) + " " + to_string(it->first) + " " + to_string(it->first) + " " + to_string(it->first);
		}else if(it->second>=2){
			if(last==-1){
				last = it->first;
				b = last;
			}else{
				long long numerator = pow(it->first + last,2);
				long long denominator = it->first * last;
				if(numerator*bestDenominator<bestNumerator*denominator){
					bestNumerator=numerator;
					bestDenominator=denominator; 
					a = last;
					last = it->first;
					b = last;
				}
			}
		}
	}
	return to_string(a) + " " + to_string(a) + " " + to_string(b) +" " + to_string(b);
}

int optimalpartition.datastructures.disjointsetunion.math.implementation.main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}
		cout << solve(n, arr) << endl;
	}
}