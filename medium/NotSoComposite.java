package medium;

import java.util.Scanner;
// came up with this problem.
// check if a number n<10^18 is a prime power.
public class NotSoComposite {
    static boolean isPrime(int a) {
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        // always accurate - doubles can represent integers less than 2^32 exactly since mantissa length
        // is more than 32.
        long sqrt = (long) (Math.sqrt(n));
        boolean monoPrime = false;
        if (sqrt * sqrt == n && isPrime((int)sqrt)) {
            monoPrime = true;
        }else {
            for (int i = 2; i < Math.min(n, 1_000_000); i++) {
                if (n % i == 0) {
                    long x = i;
                    while (x < n) {
                        x *= i;
                    }
                    if (n == x && isPrime(i)) {
                        monoPrime = true;
                    }
                    break;
                }
            }
        }
        if (monoPrime) {
            System.out.println("Primeish");
        } else {
            System.out.println("Composite");
        }
    }
}
