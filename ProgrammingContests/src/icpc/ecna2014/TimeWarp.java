package icpc.ecna2014;

import java.util.Scanner;

// https://codeforces.com/gym/100641
public class TimeWarp {
    private static final int MOD = 360 * 120;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int t = 1; t <= n; t++) {
            // each second is a 11/120 degree change
            // each minute is a 11/2 degree change
            // each hour is 330 degrees. Multiply everything by 120 to work with ints
            int degrees = sc.nextInt() * 120;
            boolean afterQuery = sc.next().startsWith("a");
            int hour = sc.nextInt();
            int stDegrees = (330 * 120 * hour) % MOD;
            long secondsAfterMidnight;
            if (afterQuery) {
                int dist = (degrees - stDegrees + MOD) % MOD;
                if (dist == 0) {
                    dist = MOD;
                }
                long secondsToWait = Math.round(dist / 11.0);
                secondsAfterMidnight = secondsToWait + hour * 3600;
            } else {
                int dist = (degrees - stDegrees - MOD) % MOD;
                if (dist == 0) {
                    dist = -MOD;
                }
                long secondsToWait = Math.round(dist / 11.0);
                secondsAfterMidnight = secondsToWait + (12 + hour) * 3600;
            }
            StringBuilder ans = new StringBuilder();
            long ansHour = (secondsAfterMidnight / 3600) % 12;
            if (ansHour == 0) {
                ansHour = 12;
            }
            secondsAfterMidnight %= 3600;
            ans.append("Case " + t + ": " + ansHour);
            ans.append(":" + String.format("%02d", secondsAfterMidnight / 60));
            ans.append(":" + String.format("%02d", secondsAfterMidnight % 60));
            System.out.println(ans);
        }
    }
}
