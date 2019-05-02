package codeforces;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// http://codeforces.com/contest/1152/problem/B
public class NekoPerformsCatFurrierTransform {
    public void solve() throws IOException {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        List<Integer> xi = new ArrayList<>();
        int n = 20;
        while (Integer.bitCount(x) != 32 - Integer.numberOfLeadingZeros(x)) {
            if ((x & (1 << n)) != 0) {
                x ^= (1 << (n + 1)) - 1;
                xi.add(n + 1);
                if (Integer.bitCount(x) == 32 - Integer.numberOfLeadingZeros(x)) {
                    break;
                }
                x++;
                xi.add(x + 1);
            }
            n--;
        }
        System.out.println(xi.size());
        if (xi.size() == 0) {
            System.out.println();
            return;
        }
        System.out.print(xi.get(0));
        for (int i = 2; i < xi.size(); i += 2) {
            System.out.print(" " + xi.get(i));
        }
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        NekoPerformsCatFurrierTransform solution = new NekoPerformsCatFurrierTransform();
        solution.solve();
    }
}
