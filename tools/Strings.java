package tools;

/* Various methods useful with strings
 * METHOD LIST;
 * int[] zAlgorithm(char[] str)
 * */
public class Strings {

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
    public static int[] zAlgorithm(char[] str) {
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
}
