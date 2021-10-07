# https://beta.atcoder.jp/contests/agc025/tasks/agc025_
n = int(input())

sum = 0
while(n>0):
    sum+=n%10
    n//=10
if sum == 1:
    print(10)
else:
    print(sum)