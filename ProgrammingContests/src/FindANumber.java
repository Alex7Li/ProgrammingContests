import java.math.BigInteger;
import java.util.*;

// https://codeforces.com/problemset/problem/1070/A
public class FindANumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int divisor = sc.nextInt();
        int sum = sc.nextInt();
        if (divisor % 9 == 0 && sum % 9 != 0) {
            System.out.println(-1);
            return;

        } else if (divisor % 3 == 0 && sum % 3 != 0) {
            System.out.println(-1);
            return;
        }
        //store da digits
        List<Integer> digits = new ArrayList<>();
        for (int i = 0; i < sum / 9; i++) {
            digits.add(9);
        }
        if (sum % 9 != 0) {
            digits.add(sum % 9);
        }
        while (!digitsToBigInt(digits).mod(BigInteger.valueOf(divisor)).equals(BigInteger.valueOf(0))) {
            //generate next number
            int S = -1;
            for (int i = 0; i < digits.size(); i++) {
                S += digits.get(i);
                if (i + 1 == digits.size()) {
                    minWithSum(S, digits, i);
                    digits.add(1);
                    break;
                }
                if (digits.get(i) != 0 && digits.get(i + 1) != 9) {
                    minWithSum(S, digits, i);
                    digits.set(i + 1, digits.get(i + 1) + 1);
                    break;
                }
            }
        }
        for (int i = digits.size() - 1; i >= 0; i--) {
            System.out.print(digits.get(i));
        }
    }

    //update digit array to have the first upTo digits be the min possible with given digit sum
    private static void minWithSum(int sum, List<Integer> digits, int upTo) {
        for (int i = 0; i < sum / 9; i++) {
            digits.set(i, 9);
        }
        digits.set(sum / 9, sum % 9);
        for (int i = 1 + sum / 9; i <= upTo; i++) {
            digits.set(i, 0);
        }
    }

    private static BigInteger digitsToBigInt(List<Integer> digits) {
        BigInteger ret = BigInteger.ZERO;
        for (int i = digits.size() - 1; i >= 0; i--) {
            ret = ret.multiply(BigInteger.TEN).add(BigInteger.valueOf(digits.get(i)));
        }
        return ret;
    }
}
