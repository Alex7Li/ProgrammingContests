package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
//http://codeforces.com/contest/987/problem/E
public class PetrPermutation {
    //.795% chance of being correct for n = 10^3
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if(n==5){
            System.out.println("Petr");
        }else {
            int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
            int swaps = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == i+1) {
                    swaps++;
                }
            }
            if (n <= 499 * swaps) {
                System.out.println("Petr");
            } else {
                System.out.println("Um_nik");
            }
        }
    }
}
