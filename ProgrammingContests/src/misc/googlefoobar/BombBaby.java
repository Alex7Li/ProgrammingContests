package misc.googlefoobar;

import java.math.BigInteger;

public class BombBaby {
    public static void main(String[] args) {
        System.out.println(answer("1", "1"));//0
        System.out.println(answer("2", "1"));//1
        System.out.println(answer("4", "7"));//4
        System.out.println(answer("2", "4"));//impossible
        System.out.println(answer("100000000000000000000000", "100000000000000000000000"));//impossible
    }

    // It is possible iff a and b are relatively prime.
    // The number of steps required is the number of steps
    // needed by the euclidean algorithm (easily seen, as
    // there is only 1 way to 'undo' a move)
    public static String answer(String a, String b) {
        BigInteger aI = new BigInteger(a);
        BigInteger bI = new BigInteger(b);
        if (aI.compareTo(BigInteger.ONE) < 0 || bI.compareTo(BigInteger.ONE) < 0) {
            return "impossible";
        }
        BigInteger ans = gcdSteps(aI, bI);
        if (ans.compareTo(BigInteger.ZERO) < 0) {
            return "impossible";
        } else {
            return ans + "";
        }
    }

    public static BigInteger gcdSteps(BigInteger aI, BigInteger bI) {
        if (bI.equals(BigInteger.ZERO)) {
            if (aI.equals(BigInteger.ONE)) {
                //1 1 is starting state, we are looking at 1 0, so -1 moves from start
                return BigInteger.valueOf(-1);
            } else {
                //less than -10^50 so output is always negative
                return new BigInteger("-1000000000000000000000000000000000000000000000000000000000000000000000000");
            }
        }
        if (aI.compareTo(bI) < 0) {
            return gcdSteps(bI, aI);
        } else {
            return aI.divide(bI).add(gcdSteps(bI, aI.mod(bI)));
        }
    }
}
