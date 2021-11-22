package codeforces;

import java.io.PrintWriter;
import java.util.Scanner;

//http://codeforces.com/problemset/problem/990/D
public class GraphAndComp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.close();
        if ((a > 1 && b > 1) || ((a + b) == 2 && (n ==2 ||n==3))) {
            System.out.println("NO");
            return;
        }
        int components = Math.max(a,b);
        boolean[][] graph = new boolean[n][n];
        for (int i = 0; i < n-components; i++) {
            graph[i+1][i] = true;
            graph[i][i+1] = true;
        }
        PrintWriter pw = new PrintWriter(System.out);
        pw.println("YES");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = 0;
                if(i!=j && graph[i][j] == (a > b)){
                    val++;
                }
                pw.print(val);
            }
            pw.println();
        }
        pw.flush();
    }
}
