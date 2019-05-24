package codeforces;

import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
////http://codeforces.com/contest/1006/problem/E
public class MilitaryProblem {
    static ArrayList<Integer> order = new ArrayList<>();
    static ArrayList<ArrayList<Integer>> children = new ArrayList<>();
    static int[] last_val;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        last_val = new int[n];
        for (int i = 0; i < n; i++) {
            children.add(new ArrayList<>());
        }
        for (int i = 1; i < n; i++) {
            int sup = sc.nextInt() - 1;
            children.get(sup).add(i);
        }
        createOrder(0);
        int[] index = new int[n];
        for (int i = 0; i < order.size(); i++) {
            index[order.get(i)-1] = i;
        }
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < q; i++) {
            int off = sc.nextInt()-1;
            int k = sc.nextInt()-1;
            if (index[off] + k >= last_val[off]) {
                pw.print(-1);
            } else {
                pw.print(order.get(index[off] + k));
            }
            pw.println();
        }
        pw.close();

    }

    public static void createOrder(int officer) {
        order.add(officer+1);
        for (int i : children.get(officer)) {
            createOrder(i);
        }
        last_val[officer] = order.size();
    }
}
