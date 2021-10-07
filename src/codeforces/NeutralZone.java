package codeforces;

import java.util.Scanner;
//http://codeforces.com/contest/1017/problem/F
public class NeutralZone {

    private static int a;
    private static int b;
    private static int c;
    private static int d;
    private static int n;
    private static final int INT_SIZE = 32;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();
        sc.close();
        // composite is a boolean[], but compressed for memory
        // composite[i] means that
        // if i is even:
        //   3*(i)+5 is prime
        // if i is odd:
        //   3*(i-1)+7 is prime
        // (As all composite are +-1 mod 6)
        int[] composite = new int[1 + n / (3 * INT_SIZE)];
        //isComposite[i] means that i is  prime
        boolean[] isComposite = new boolean[3 + (int) Math.sqrt(n)];
        for (int i = 2; i < isComposite.length; i++) {
            if (!isComposite[i]) {
                for (int j = i * i; j <= n; j += i) {
                    if (isComposite.length > j) {
                        isComposite[j] = true;
                    }
                    if (j % 6 == 1) {
                        int bitToSet = (j - 4) / 3;
                        composite[bitToSet / INT_SIZE] |= (1 << (bitToSet % INT_SIZE));
                    } else if (j % 6 == 5) {
                        int bitToSet = (j - 5) / 3;
                        composite[bitToSet / INT_SIZE] |= (1 << (bitToSet % INT_SIZE));
                    }
                }
            }
        }
        int ans = 0;
        if (n > 1) {
            ans += count(2);
            if (n > 2) {
                ans += count(3);
            }
        }
        for (int i = 0; i < composite.length * INT_SIZE; i++) {
            if ((composite[i / INT_SIZE] & (1 << (i % INT_SIZE))) == 0) {
                int v;
                if (i % 2 == 0) {
                    v = 3 * i + 5;
                } else {
                    v = 3 * i + 4;
                }
                if (v <= n) {
                    ans += count(v);
                }
            }
        }

        System.out.println(Integer.toUnsignedString(ans));
    }

    private static int count(int prime) {
        int C = 0;
        int i = prime;
        while (i <= n) {
            C += n / i;
            i *= prime;
        }
        int f = a * prime * prime * prime + b * prime * prime + c * prime + d;
        return C * f;
    }
}
