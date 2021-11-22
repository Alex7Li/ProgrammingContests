package misc.constructive;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

//https://codeforces.com/contest/1158/problem/C
public class PermuationRecovery {
private static List<Integer>[] graph;

public static void main(String[] xx) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);
    
    int t = Integer.parseInt(br.readLine());
    for (int i = 0; i < t; i++) {
        int n = Integer.parseInt(br.readLine());
        int[] successor = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x) - 1).toArray();
        // set up graph for topological sort
        graph = new ArrayList[n + 1];
        // we store each value in the successor array as an array. The first element the index it started from.
        // The second is the index of it's successor.
        PriorityQueue<int[]> Q = new PriorityQueue<>((x, y) -> y[0] - x[0]);
        Q.add(new int[]{-1, n + 1});
        for (int j = 0; j < n; j++) {
            graph[j] = new ArrayList<>();
            // we will add 2 types of edges.
            // First, this node must be less than any node whose successor comes after it. The second
            // condition is equivalent to this node being less than the last node whose successor comes after it.
            while (Q.peek()[1] <= j) {
                Q.poll();
            }
            if (Q.peek()[0] != -1) {
                graph[j].add(Q.peek()[0]);
            }
            // Second, this node must be less than it's successor.
            if (successor[j] != -2) {
                graph[j].add(successor[j]);
                Q.add(new int[]{j, successor[j]});
            }else{
                graph[j].add(n);
            }
        }
        graph[n] = new ArrayList<>();
        if (!topSort(graph)) {
            pw.println(-1);
        } else {
            for (int j = 0; j < n - 1; j++) {
                pw.print(sorting[j] + " ");
            }
            pw.println(sorting[n - 1]);
        }
    }
    pw.flush();
    pw.close();
    br.close();
}

private static int[] sorting;
private static int position;

private static boolean topSort(List<Integer>[] graph) {
    int[] seen = new int[graph.length];
    sorting = new int[graph.length];
    position = graph.length;
    for (int i = 0; i < graph.length; i++) {
        if (seen[i] == 0) {
            if (!dfs(i, seen)) {
                return false;
            }
        }
    }
    return true;
}

private static boolean dfs(int i, int[] seen) {
    seen[i] = 2;
    for (int j : graph[i]) {
        if (seen[j] == 0) {
            if (!dfs(j, seen)) {
                return false;
            }
        } else if (seen[j] == 2) {
            return false;
        }
    }
    seen[i] = 1;
    sorting[i] = position--;
    return true;
}
}
