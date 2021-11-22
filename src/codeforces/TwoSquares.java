package codeforces;

import java.util.Arrays;
import java.util.Scanner;

//http://codeforces.com/contest/994/problem/C
public class TwoSquares {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //doubled so I can divide by 2 later
        int[] sq1 = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x) * 2).toArray();
        int[] sq2 = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x) * 2).toArray();
        int centerXs1 = (sq1[0] + sq1[2] + sq1[4] + sq1[6]) / 4;
        int centerYs1 = (sq1[1] + sq1[3] + sq1[5] + sq1[7]) / 4;
        int centerXs2 = (sq2[0] + sq2[2] + sq2[4] + sq2[6]) / 4;
        int centerYs2 = (sq2[1] + sq2[3] + sq2[5] + sq2[7]) / 4;
        int s = Math.abs(sq1[0] - centerXs1);
        int d = Math.abs(sq2[0] + sq2[2] - 2 * centerXs2);
        int centDist = Math.abs(centerXs1 - centerXs2) + Math.abs(centerYs1 - centerYs2);

        //check if center is in tilted bounding box
        if (centDist > 2 * s + d) {
            System.out.println("NO");
        } else { //and in normal bounding box
            if (Math.abs(centerYs1 - centerYs2) <= s + d && Math.abs(centerXs1 - centerXs2) <= s + d) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
