package tools;

/**
 * this is it. the fft you've always dreamed of (:
 * METHOD LIST:
 * long bitReverse(int n, int k)
 * long modPow(long a, long p)
 * long modInv(long a)
 * long[] calcRoots(int k, boolean inverse)
 * long[] reorderArray(long[] a, int k)
 * long[] numberTheoreticTransform(long[] coef, int k, boolean inverse)
 */
public class NumberTheoreticTransform {
    // 2^23*7*17+1
    private static final int MOD = 998244353;

    //highest power of 2 that is a factor of MOD-1
    private static final int twoPow = 23;

    // any number such that ROOT^(2^twoPow)=1 & ROOT^(2^(twoPow-1))!=1
    private static final int ROOT = 15311432;

    /**
     * reverse the least significant k bits of a number
      */
    private static int bitReverse(int n, int k) {
        return Integer.reverse(n) >>> (32 - k);
    }

    /**
     * return a^p (mod MOD)
     */
    private static long modPow(long a, long p) {
        if (p == 0) {
            return 1;
        }
        long half = modPow(a, p / 2);
        long ans = (half * half) % MOD;
        if (p % 2 == 1) {
            ans = (ans * a) % MOD;
        }
        return ans;
    }

    /*
     * return x such that x*a = 1 (mod MOD). Requires that MOD is prime
     */
    private static long modInv(long a) {
        return modPow(a, MOD - 2);
    }

    /**
     * calculate roots of unity for ntt
     */
    private static long[] calcRoots(int k, boolean inverse) {
        long root = modPow(ROOT, modPow(2, twoPow - k));
        if (inverse) {
            root = modInv(root);
        }
        long[] roots = new long[k];
        roots[k - 1] = root;
        for (int i = k - 1; i > 0; i--) {
            roots[i - 1] = (roots[i] * roots[i]) % MOD;
        }
        return roots;
    }

    /**
     * Change the indicies of an array, putting them into bit-reverse order.
     * array should have length 2^k
     */
    private static long[] reorderArray(long[] a, int k) {
        long[] ans = new long[a.length];
        for (int i = 0; i < a.length; i++) {
            ans[bitReverse(i, k)] = a[i];
        }
        return ans;
    }

    /**
     * coef.length = 2^k
     * Note: When computing the inverse, this function will return 2^k times the
     * correct answer. Please divide as needed.
     */
    private static long[] numberTheoreticTransform(long[] coef, int k, boolean inverse) {
        coef = reorderArray(coef, k);
        long[] roots = calcRoots(k, inverse);
        for (int s = 0; s < k; s++) {
            int len = 1 << s;
            for (int st = 0; st < coef.length; st += 2 * len) {
                // combine the vectors starting at st and st + len
                long curRoot = 1;
                for (int j = st; j < st + len; j++) {
                    long t = (curRoot * coef[j + len]) % MOD;
                    long u = coef[j];
                    coef[j] = (u + t) % MOD;
                    coef[j + len] = (u - t) % MOD;
                    curRoot = (roots[s] * curRoot) % MOD;
                }
            }
        }
        return coef;
    }
}
