# https://beta.atcoder.jp/contests/agc025/tasks/agc025_b
MOD = 998244353
mod_inv = [0, 1]


def init_mod_inv(n):
    for i in range(2, n + 1):
        ans = MOD - (MOD // i) * mod_inv[MOD % i] % MOD
        mod_inv.append(ans)

def main():
    n, a, b, k = map(int, input().split())

    init_mod_inv(n)
    nCr = [0] * (n + 1)
    nCr[0] = 1
    for i in range(1, n+1):
        nCr[i] = (nCr[i - 1] * (n - i + 1) * mod_inv[i]) % MOD

    ways = 0
    for x in range(0, n + 1):
        yb = k - a * x
        if yb >= 0 and yb % b == 0 and yb // b <= n:
            ways += nCr[x] * nCr[yb // b]
            ways %= MOD
    print(ways)


if __name__ == "__main__":
    main()
