package misc.verymisc;

import java.util.Arrays;

// I can't believe the solution for this homework problem so I'm checking it.
// Update: it was wrong
public class PitmanProbability2Review18b {
    public static void main(String[] args) {
        int count = 0;
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++) {
                for (int k = 1; k <= 6; k++) {
                    for (int l = 1; l <= 6; l++) {
                        for (int m = 1; m <= 6; m++) {
                            for (int n = 1; n <= 6; n++) {
                                for (int o = 1; o <= 6; o++) {
                                    int[] a = {i, j, k, l, m, n, o};
                                    Arrays.sort(a);
                                    if (a[0] == a[2] && a[3] == a[6] && a[2] != a[3]) {
                                        count++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        System.out.println(count);
    }
}

