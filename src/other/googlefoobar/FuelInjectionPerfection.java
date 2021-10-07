package other.googlefoobar;

import java.math.BigInteger;

public class FuelInjectionPerfection {
    public static void main(String[] args) {
        System.out.println(answer("11"));
    }

    public static int answer(String n) {
        BigInteger i = new BigInteger(n);
        if (i.equals(BigInteger.ZERO)) {
            return 1;
        }
        int operations = 0;
        while (!i.equals(BigInteger.ONE)) {
            operations++;
            if (i.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO)) {
                i = i.divide(BigInteger.valueOf(2));
            } else {
                if (i.add(BigInteger.ONE).mod(BigInteger.valueOf(4)).equals(BigInteger.ZERO) && !i.equals(BigInteger.valueOf(3))) {
                    i = i.add(BigInteger.ONE);
                } else {
                    i = i.subtract(BigInteger.ONE);
                }
            }
        }
        return operations;
    }
}
