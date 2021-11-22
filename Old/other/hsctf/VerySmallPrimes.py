def factor(n):
    for i in range(2, 10000000):
        if n % i == 0:
            n //= i;
            break;
    return n, i

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

def solve():
    n = int(
        "0x10722aa034ca559f3e30fdd3a5fbdbb6f2eede584f4aedc764f0bf8a72bc7853ccc874e975563fa80348cbd3355e36903e5cbbc4ce7ba91ca29989b8a09fe3212931e4421a3460501c91aa2b47729eb114c22f15d87d11deddd102f576704dd8ae8aca12afad9e0fbf909f7be534ff73fc17d2ef11ac76b2eaa9a62b7ffc0bd",
        0);
    c = int(
        "0x502c9f367b231c49a36ed5353f9afdcc4ed7c262f593995085ab44e017c3ebb912fa94b7b06213bb9cb9ea052bdb70af922b54617a035c82be819e7f4209e5718901688be800669247a449ea8bd6f8328090396117ae6b3a292eb4f1de1806f81442d7641d35c68bd32d44f21fe36a1128bbc84258904619f749e2692b8bca",
        0)
    a, b = factor(n);
    e = 65537;
    t = (a - 1) * (b - 1);
    d = modinv(e,t)
    print((d*e)%t)
    #print(d)
    ans = str(pow(c, d, n))
    print(ans)
    #[102 108 97 103 123 67 114 97 105 103 45 83 109 101 108 108 115 45 66 97 100 125]
    for i in range(len(ans) // 2):
        letter = ans[2 * i:2 * (i + 1)];
        print(chr(int(letter)), end='')

for i in [102, 108, 97, 103, 123, 67, 114, 97, 105 ,103, 45, 83, 109, 101, 108, 108, 115, 45, 66, 97, 100, 125]:
    print(chr(i),end='')
