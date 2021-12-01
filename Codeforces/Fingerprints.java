package codeforces;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
//http://codeforces.com/problemset/problem/994/A
public class Fingerprints {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        int m =sc.nextInt();
        ArrayList<Integer> seq = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            seq.add(sc.nextInt());
        }
        Set<Integer> keys = new HashSet<>();
        for (int i = 0; i < m; i++) {
            keys.add(sc.nextInt());
        }
        sc.close();
        for (int i:seq) {
            if(keys.contains(i)){
                System.out.print(i+ " ");
            }
        }
        System.out.println();
    }
}
