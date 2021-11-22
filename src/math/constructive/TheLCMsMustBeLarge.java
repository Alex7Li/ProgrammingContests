package math.constructive;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//https://codeforces.com/contest/1166/problem/E
public class TheLCMsMustBeLarge {
public static void main(String[] xx) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int[] params = Arrays.stream(br.readLine().split(" "))
            .mapToInt(x -> Integer.parseInt(x)).toArray();
    int days = params[0];
    int stores = params[1];
    boolean[][] wentTo = new boolean[days][stores];
    for (int i = 0; i < days; i++) {
        int[] s = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        for (int j = 1; j < s.length; j++) {
            wentTo[i][s[j]-1] = true;
        }
    }
    boolean allOverlap = true;
    out:
    for (int i = 0; i < days; i++) {
        for (int j = i+1; j < days; j++) {
            boolean overlap = false;
            for (int k = 0; k < stores; k++) {
                if (wentTo[i][k] && wentTo[j][k]) {
                    overlap = true;
                    break;
                }
            }
            if (!overlap) {
                allOverlap = false;
                break out;
            }
        }
    }
    if (allOverlap) {
        System.out.println("possible");
    } else {
        System.out.println("impossible");
    }
    
    br.close();
    
}
}
