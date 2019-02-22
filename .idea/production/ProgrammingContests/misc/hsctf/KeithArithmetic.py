import random


# leading coef ans is n * https://oeis.org/search?q=1%2C-1%2C4%2C-48%2C1536&language=english&go=Search
# rest are all zeros
def ones(n):
    w = 0
    while (n):
        w += 1
        n &= n - 1
    return w


def trailingZeros(n):
    if (n == 0):
        return 1;
    ans = 0
    while (n % 2 == 0):
        ans += 1
        n //= 2;
    return ans


def twosInFact(n):
    ans = 0;
    for z in range(1, n + 1):
        ans += trailingZeros(z);
    return ans;


def brute(k, p):
    p.reverse();

    def f(x):
        ans = 0
        for deg, c in enumerate(p):
            ans += c * (x ** deg);
        return ans;

    sumVal = 0;
    for i in range(2 ** k):
        sumVal += ((-1) ** ones(i)) * f(i);
    p.reverse()
    return sumVal;


def test():
    for k in range(20):
        for x in [1, 3987231971, 82365400, -8589934592]:
            p = [x]
            for i in range(k):
                p.append(random.randint(-1000000, 1000000));
            assert len(p) - 1 == k;
            val = brute(k, p);
            assert trailingZeros(val) == trailingZeros(p[0]) + twosInFact(k) + (k * (k - 1) // 2), str(p);


def solve():
    file = open('Keith.txt')
    lines = [line.rstrip('/n') for line in file]
    ans = 0
    # Find 2's in p[0]*2^(n*(n-1)/2)*n! [if p has degree k]
    for i in range(len(lines) // 2):
        k = int(lines[i * 2])
        p = lines[i * 2 + 1].split(" ")
        assert int(p[0]) > 0
        if k == len(p) - 1:
            ans += trailingZeros(int(p[0]))
            ans += (k * (k - 1)) // 2
            ans += twosInFact(k)
        else:
            # sum is 0
            ans += 1
    return ans;


test()
print(solve())
