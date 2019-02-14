package tools;

/**
 * Various methods useful for number theory
 * METHOD LIST;
 * long choose(int n, int k, int mod)
 * int toitent(int n)
 * int gcd(int a, int b)
 * int[] primeSieve(int n)
 */
public class NumberTheory {

    /**
     * return n choose k (mod some number)
     */
    private static long choose(int n, int k, int mod) {
        long ans = 1;
        for (int i = k + 1; i <= n; i++) {
            ans = (ans * i) % mod;
        }
        for (int i = 2; i <= n - k; i++) {
            //ans = (modInv(i) * ans) % mod;
        }
        return ans;
    }
    /**
     * return totient(n), the number of positive integers
     * up to n relatively prime to n
     * O(sqrt(n))
     */
    private static int toitent(int n)
    {
        // Initialize result as n
        int result = n;

        // Consider all prime factors of n and subtract their
        // multiples from result
        for (int p = 2; p * p <= n; ++p)
        {

            // If p is a prime factor, divide out highest
            // power of p and update result.
            if (n % p == 0)
            {
                while (n % p == 0)
                    n /= p;
                result -= result / p;
            }
        }

        // Destroy last factor
        if (n > 1)
            result -= result / n;
        return result;
    }


    /**
     * Return gcd(a,b)
     * O(log(a+b))
     */
    private static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    /**
     * Return an array of primes up to and including n
     * O(n*log(n)*log(log(n)))
     */
    private static int[] primeSieve(int n){
        boolean[] isComposite = new boolean[n + 1];
        for (int i = 2; i * i <= n; i++) {
            if (!isComposite[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isComposite[j] = true;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < isComposite.length; i++) {
            if(!isComposite[i]) {
                count++;
            }
        }
        int[] primes = new int[n+1];
        for (int i = isComposite.length; i >= 2; i--) {
            if(!isComposite[i]){
                primes[--count] = i;
            }
        }
        return primes;
    }

}
