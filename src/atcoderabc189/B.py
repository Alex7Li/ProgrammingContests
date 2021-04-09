def solve():
    n, x = map(int, input().split(" "))
    x *= 100
    for i in range(1, n + 1):
        v, p = map(int, input().split(" "))
        x -= v * p
        if x < 0:
            return i
    return -1


print(solve())
