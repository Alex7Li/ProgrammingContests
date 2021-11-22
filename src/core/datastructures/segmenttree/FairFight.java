package core.datastructures.segmenttree;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051706/0000000000122838
public class FairFight {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());
        for (int t = 1; t <= cases; t++) {
            String[] argsy = br.readLine().split(" ");
            int n = Integer.parseInt(argsy[0]);
            int k = Integer.parseInt(argsy[1]);
            int[] a = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(x -> Integer.parseInt(x)).toArray();

            int[] b = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(x -> Integer.parseInt(x)).toArray();
            int valid = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int maxA = 0;
                    int maxB = 0;
                    for (int l = i; l <= j; l++) {
                        maxA = Math.max(maxA, a[l]);
                        maxB = Math.max(maxB, b[l]);
                    }
                    if (Math.abs(maxA - maxB) <= k) {
                        valid++;
                    }
                }
            }

            System.out.println("Case #" + t + ": " + valid);
        }
    }
}
