package codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//http://codeforces.com/contest/981/problem/E
public class AdditionOnSegments {
    // it would be safer to use a long, but that results in TLE >:(
    private static int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        TreeSet<Integer> posV = new TreeSet<>();
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for (int i = 0; i < n + 2; i++) {
            arr.add(new ArrayList<>());
        }
        for (int i = 0; i < q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int x = sc.nextInt();
            arr.get(l).add(x);
            arr.get(r + 1).add(-x);
        }
        int[] ways = new int[n+1];
        ways[0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int x : arr.get(i)) {
                if (x > 0) {
                    //add x with knapsack
                    for (int j = n; j >= x; j--) {
                        ways[j] += ways[j-x];
                        if(ways[j] != 0 && ways[j]==ways[j-x]){
                            posV.add(j);
                        }
                        ways[j]%=MOD;
                    }
                } else {
                    x*=-1;
                    //remove x with reverse knapsack
                    for (int j = x; j <= n; j++) {
                        ways[j] -= ways[j-x];
                        ways[j]%=MOD;
                    }
                }
            }
        }
        System.out.println(posV.size());
        for (int x : posV) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
}
