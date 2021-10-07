package math.implementation;

import java.math.BigInteger;
import java.util.Scanner;

//https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/0000000000088231
class ForegoneSolution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int i = 1; i <= cases; i++) {
            BigInteger num = sc.nextBigInteger();
            BigInteger a = BigInteger.ZERO;
            BigInteger tenPow = BigInteger.ONE;
            while (num.compareTo(tenPow) > 0) {
                if (num.divide(tenPow).mod(BigInteger.TEN).equals(BigInteger.valueOf(4))) {
                    num = num.subtract(tenPow);
                    a = a.add(tenPow);
                }
                tenPow = tenPow.multiply(BigInteger.TEN);
            }
            System.out.println("Case " + i + ": " + num + " " + a);
        }
        sc.close();
    }
}
