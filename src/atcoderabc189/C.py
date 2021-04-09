n = int(input())
a = list(map(int, input().split(" ")))

ans = 0
for i in range(n):
    minV = 100001
    for j in range(i, n):
        minV = min(minV, a[j])
        ans = max(ans, (j - i + 1) * minV)
print(ans)

