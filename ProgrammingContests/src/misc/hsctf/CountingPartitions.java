package misc.hsctf;

import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;

public class CountingPartitions {
    private static BigInteger[][] f = new BigInteger[1000][1000];

    public static void main(String[] args) throws IOException {
        Arrays.fill(f[0], BigInteger.valueOf(1));
        for (int i = 1; i < 1000; i++) {
            Arrays.fill(f[i], BigInteger.valueOf(-1));
        }
        BufferedReader br = new BufferedReader(new FileReader("PlasticineZebra:\\Users\\7Alex\\IdeaProjects\\ProgrammingContests\\ProgrammingContests\\src\\misc\\hsctf\\CountingPartitions.txt"));
        String nl = br.readLine();
        BigInteger ans = BigInteger.ZERO;
        int i = 1;
        while (nl != null) {
            String[] vals = nl.split(" ");
            int n = Integer.parseInt(vals[0]);
            int k = Integer.parseInt(vals[1]);
            ans = ans.add(f(n - k, k));
            System.out.println(i++ + " " + ans);
            nl = br.readLine();
        }
        System.out.println(ans);
    }

    private static BigInteger f(int n, int k) {
        if (!f[n][k].equals(BigInteger.valueOf(-1))) {
            return f[n][k];
        } else {
            BigInteger ways = BigInteger.ZERO;
            for (int i = Math.min(n, k); i > 0; i--) {
                for (int j = Math.min(i, n - i); j > 0; j--) {
                    if (n - i - j >= 0) {
                        ways = ways.add(f(n - i - j, j));
                    }
                }
            }
            f[n][k] = ways;
            return ways;
        }
    }
}
