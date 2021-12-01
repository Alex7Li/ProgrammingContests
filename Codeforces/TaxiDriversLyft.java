package codeforces;

import java.util.Scanner;

//http://codeforces.com/contest/1075/problem/B
public class TaxiDriversLyft {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] loc = new int[n + m];
        for (int i = 0; i < loc.length; i++) {
            loc[i] = sc.nextInt();
        }
        int[] taxiLoc = new int[m + 1];
        int[] taxiCount = new int[m + 1];
        int lastTaxi = 0;
        for (int i = 0; i < loc.length; i++) {
            if (sc.nextInt() == 1) {
                taxiLoc[lastTaxi] = loc[i];
                lastTaxi++;
            }
        }

        taxiLoc[m] = Integer.MAX_VALUE;
        lastTaxi = -1;
        for (int i = 0; i < loc.length; i++) {
            if (loc[i] == taxiLoc[lastTaxi + 1]) {
                lastTaxi++;
            } else {
                if (lastTaxi == -1) {
                    taxiCount[0]++;
                } else {
                    if (Math.abs(taxiLoc[lastTaxi + 1] - loc[i]) < Math.abs(loc[i] - taxiLoc[lastTaxi])) {
                        taxiCount[lastTaxi + 1]++;
                    } else {
                        taxiCount[lastTaxi]++;
                    }
                }
            }
        }
        for (int i = 0; i < taxiCount.length - 2; i++) {
            System.out.print(taxiCount[i] + " ");
        }
        System.out.println(taxiCount[m] + taxiCount[m - 1]);
        System.out.println();
    }
}
