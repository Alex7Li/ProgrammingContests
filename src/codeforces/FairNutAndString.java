package codeforces;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

//https://codeforces.com/contest/1084/problem/C
public class FairNutAndString {
    private static long MOD = (long) (Math.pow(10, 9)) + 7L;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.nextLine().toCharArray();
        List<Integer> aCounts = new ArrayList<>();
        aCounts.add(0);
        for (int i = 0; i < s.length; i++) {
            if (s[i] == 'a') {
                aCounts.set(aCounts.size() - 1, aCounts.get(aCounts.size() - 1) + 1);
            } else if (aCounts.get(aCounts.size()-1) != 0 && s[i] == 'b') {
                aCounts.add(0);
            }
        }
        long sum = aCounts.get(0);
        for (int i = 1; i < aCounts.size(); i++) {
            sum = (aCounts.get(i) + sum + sum*aCounts.get(i))%MOD;
        }
        System.out.println(sum);
        sc.close();
    }
}
