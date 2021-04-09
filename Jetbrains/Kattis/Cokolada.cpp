#include <bits/stdc++.h>
//https://open.kattis.com/contests/h5oxfe/problems/cokolada/submit
using namespace std;

int main(){
    int a;
    scanf("%d",&a);
    int m = a&-a;
    int bitDist = 0;
    for(; m < a; bitDist++, m=m<<1);
    printf("%d %d", m, bitDist);
    return 0;
}
