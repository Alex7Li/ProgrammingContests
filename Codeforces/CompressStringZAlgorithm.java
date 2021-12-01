package codeforces;

import java.util.Scanner;

// https://codeforces.com/contest/1121/problem/F
public class CompressStringZAlgorithm {

    /**
     * Computes the longest-prefix array of a string
     * corresponding to a itself (the Z-array).
     * The ith index of the output array contains the length of the longest
     * substring starting at index i that has that pattern
     * <p>
     * Example:
     * str =     [a, b, a, a, b, a, a]
     * z-array = [7, 0, 1, 4, 0, 1, 1]
     * <p>
     * One can also easily use this algorithm for finding an arbitrary
     * pattern. For example, if you want to find the pattern 'aba' in
     * 'cabadat', just call this method on the string 'aba!cabadat',
     * where ! is a separator character not in the string. Then the
     * end of the returned array will contain the pattern desired.
     *
     * @return The Z-array of the string str
     */
    private static int[] zAlgorithm(char[] str) {
        int n = str.length;
        int[] zArray = new int[n];
        int x = 0;
        int y = 0;
        for (int i = 1; i < zArray.length; i++) {
            zArray[i] = Math.max(0, Math.min(y - i, zArray[i - x]));
            while (i + zArray[i] < n && str[zArray[i]] == str[i + zArray[i]]) {
                x = i;
                y = i + zArray[i];
                zArray[i]++;
            }
        }
        zArray[0] = n;
        return zArray;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.nextLine();
        char[] str = sc.nextLine().toCharArray();

        // best[i]: min cost for making first i characters
        int[] best = new int[n];
        best[0] = a;
        for (int i = 1; i < n; i++) {
            best[i] = best[i - 1] + a;
            char[] c = new char[i + 1];
            for (int j = 0; j <= i; j++) {
                c[j] = str[i - j];
            }
            int[] z = zAlgorithm(c);
            for (int j = 1; j < z.length; j++) {
                // if we choose to repeat z[j], then we must ensure that we
                // repeat it at a spot after we find it (i-j)
                if (i - j < i - z[j] + 1) {
                    if (best[i] > best[i - z[j]] + b) {
                        best[i] = best[i - z[j]] + b;
                    }
                }
            }
        }
        System.out.println(best[n - 1]);
    }
}