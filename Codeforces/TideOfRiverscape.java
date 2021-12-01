package codeforces;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

//http://codeforces.com/contest/989/problem/B
public class TideOfRiverscape {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int p = sc.nextInt();
        sc.nextLine();
        char[] tides = sc.nextLine().toCharArray();
        List<List<Character>> buckets = new ArrayList<>();
        for (int i = 0; i < p; i++) {
            buckets.add(new ArrayList<>());
        }
        char[] val = new char[p];
        Arrays.fill(val, '.');

        for (int i = 0; i < tides.length; i++) {
            buckets.get(i % p).add(tides[i]);
        }
        boolean possible = false;
        for (int i = 0; i < buckets.size(); i++) {
            List<Character> b = buckets.get(i);
            if (b.contains('1') && b.contains('0')) {
                possible = true;
            } else if (b.size() > 1 && b.contains('.')) {
                possible = true;
                if (b.contains('1')) {
                    b.set(b.indexOf('.'), '0');
                } else if (b.contains('0')) {
                    b.set(b.indexOf('.'), '1');
                } else {
                    b.set(b.indexOf('.'), '0');
                    b.set(b.lastIndexOf('.'), '1');
                }
            }
        }
        if (possible) {
            for (int i = 0; i < tides.length; i++) {
                char c = buckets.get(i % p).get(i / p);
                System.out.print(c == '.' ? '1' : c);
            }
            System.out.println();
        } else {
            System.out.println("No");
        }
    }
}
