package codeforces;

import java.util.Arrays;
import java.util.Scanner;

//https://codeforces.com/contest/1086/problem/A
public class ConnectThree {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder("");
        Plot[] plots = new Plot[3];
        int[] y = new int[3];
        for (int i = 0; i < 3; i++) {
            int x = sc.nextInt();
            y[i] = sc.nextInt();
            plots[i] = new Plot(x, y[i]);
        }
        Arrays.sort(plots);
        Arrays.sort(y);
        int count = 0;
        for (int i = plots[0].x; i <= plots[2].x; i++) {
            count++;
            sb.append(i + " " + y[1] + System.lineSeparator());
        }
        for (int i = 0; i < 3; i++) {
            if (plots[i].y < y[1]) {
                for (int j = plots[i].y; j < y[1]; j++) {
                    count++;
                    sb.append(plots[i].x + " " + j + System.lineSeparator());
                }
            } else if (plots[i].y > y[1]) {
                for (int j = y[1] + 1; j <= plots[i].y; j++) {
                    count++;
                    sb.append(plots[i].x + " " + j + System.lineSeparator());
                }
            }
        }
        System.out.println(count);
        System.out.println(sb);
        sc.close();
    }

    public static class Plot implements Comparable<Plot> {
        int x;
        int y;

        public Plot(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Plot o) {
            return this.x - o.x;
        }
    }
}
