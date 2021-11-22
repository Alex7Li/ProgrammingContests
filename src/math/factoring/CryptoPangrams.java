package math.factoring;

import java.math.BigInteger;
import java.util.*;

//https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/000000000008830b
class Cryptopangrams {

public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int cases = Integer.parseInt(sc.nextLine());
    for (int t = 1; t <= cases; t++) {
        // read input
        sc.nextLine();
        String[] codeStr = sc.nextLine().split(" ");
        int n = codeStr.length;
        BigInteger[] code = new BigInteger[n];
        for (int j = 0; j < n; j++) {
            code[j] = new BigInteger(codeStr[j]);
        }
        
        // convert to primes
        BigInteger[] primes = new BigInteger[n + 1];
        int diffPoint = 0;
        for (; ; diffPoint++) {
            if (!code[diffPoint].equals(code[diffPoint + 1])) {
                primes[diffPoint + 1] = gcd(code[diffPoint], code[diffPoint + 1]);
                diffPoint++;
                break;
            }
        }
        for (int i = diffPoint; i > 0; i--) {
            primes[i - 1] = code[i - 1].divide(primes[i]);
            
        }
        for (int i = diffPoint; i < n; i++) {
            primes[i + 1] = code[i].divide(primes[i]);
        }
        
        // get conversion primes -> letters
        TreeSet<BigInteger> orderedPrimes = new TreeSet<>();
        orderedPrimes.addAll(Arrays.asList(primes));
        Map<BigInteger, Character> encoding = new HashMap<>();
        int index = 0;
        for (BigInteger b : orderedPrimes) {
            encoding.put(b, (char) ('A' + index));
            index++;
        }
        
        // output answer
        StringBuilder text = new StringBuilder();
        for (int i = 0; i < n + 1; i++) {
            text.append(encoding.get(primes[i]));
        }
        System.out.println("Case #" + t + ": " + text);
    }
    sc.close();
}

private static BigInteger gcd(BigInteger a, BigInteger b) {
    if (b.equals(BigInteger.ZERO)) {
        return a;
    } else {
        return gcd(b, a.mod(b));
    }
}
}
