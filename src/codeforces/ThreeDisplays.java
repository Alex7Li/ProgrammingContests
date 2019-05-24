package codeforces;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/987/C
public class ThreeDisplays {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        int[] fonts = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
        int[] costs = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();

        // best2[i] =  cost given that i is selected for the second display
        int[] best2 = new int[n];
        Arrays.fill(best2, Integer.MAX_VALUE);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (fonts[i] < fonts[j]) {
                    best2[j] = Math.min(best2[j], costs[i] + costs[j]);
                }
            }
        }
        // best3[i] =  cost given that i is selected for the third display
        int[] best3 = new int[n];
        Arrays.fill(best3, Integer.MAX_VALUE);
        for (int i = 0; i < n; i++) {
            if(best2[i] != Integer.MAX_VALUE){
                for (int j = i + 1; j < n; j++) {
                    if (fonts[i] < fonts[j]) {
                        best3[j] = Math.min(best3[j], best2[i] + costs[j]);
                    }
                }
            }
        }
        int minC = Integer.MAX_VALUE;
        for (int i = 0; i < best3.length; i++) {
            minC = Math.min(best3[i],minC);
        }
        if(minC==Integer.MAX_VALUE){
            minC = -1;
        }
        System.out.println(minC);
        sc.close();
    }
}
