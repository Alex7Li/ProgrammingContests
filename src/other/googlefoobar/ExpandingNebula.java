package other.googlefoobar;

import java.util.Arrays;

public class ExpandingNebula {
    public static void main(String[] args) {
        boolean[][] g0 = {{false, true}};
        System.out.println(answer(g0));
        boolean[][] g1 = {{true}, {false}};
        System.out.println(answer(g1));
        boolean[][] g = {{true, false, true}, {false, true, false}, {true, false, true}};
        System.out.println(answer(g));
    }

    public static int answer(boolean[][] g) {
        //ways to fill the first column, when the truths
        //correspond to the base-2 value of lastWays
        int[] lastWays = new int[1 << (g.length + 1)];
        int[] nextWays = new int[1 << (g.length + 1)];
        Arrays.fill(lastWays, 1);
        for (int col = 0; col < g[0].length; col++) {
            for (int lmask = 0; lmask < 1 << (1 + g.length); lmask++) {
                for (int rmask = 0; rmask < 1 << (1 + g.length); rmask++) {
                    if (works(lmask, rmask, g, col)) {
                        nextWays[rmask] += lastWays[lmask];
                    }
                }
            }
            lastWays = Arrays.copyOf(nextWays, nextWays.length);
            nextWays = new int[1 << (g.length + 1)];
        }
        int tWays = 0;
        for (int i = 0; i < lastWays.length; i++) {
            tWays += lastWays[i];
        }
        return tWays;
    }

    public static boolean works(int lmask, int rmask, boolean[][] g, int col) {
        for (int i = 0; i < g.length; i++) {
            int count = 0;
            if ((lmask & (1 << i)) != 0) {
                count++;
            }
            if ((lmask & (1 << (i + 1))) != 0) {
                count++;
            }
            if ((rmask & (1 << i)) != 0) {
                count++;
            }
            if ((rmask & (1 << (i + 1))) != 0) {
                count++;
            }
            if ((count == 1) != g[i][col]) {
                return false;
            }
        }
        return true;
    }
}
