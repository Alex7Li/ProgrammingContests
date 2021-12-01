package codeforces;

import java.io.*;
import java.util.*;

//https://codeforces.com/gym/100299
public class Digraphs {
    private static boolean[][] graph = new boolean[26][26];
    private static List<Integer> longestPath;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int tests = Integer.parseInt(br.readLine());
        for (int t = 0; t < tests; t++) {
            longestPath = new ArrayList<>();
            int n = Integer.parseInt(br.readLine());
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    graph[i][j] = true;
                }
            }
            for (int i = 0; i < n; i++) {
                char[] noEdge = br.readLine().toCharArray();
                graph[noEdge[0] - 'a'][noEdge[1] - 'a'] = false;
            }
            boolean foundCycle = false;
            for (int i = 0; i < 26 && !foundCycle; i++) {
                foundCycle = bfs(i);
            }
            if (foundCycle) {
                printGraph(20, pw);
            } else {
                List<Integer> order = topSort();
                List<Integer>[] longestPathFrom = new ArrayList[26];
                for (int i = 0; i < 26; i++) {
                    longestPathFrom[i] = new ArrayList<>();
                    longestPathFrom[i].add(i);
                }
                for (int i : order) {
                    for (int j : order) {
                        if (graph[j][i]) {
                            if (longestPathFrom[i].size() >= longestPathFrom[j].size()) {
                                while (longestPathFrom[j].size() < longestPathFrom[i].size()) {
                                    longestPathFrom[j].add(0);
                                }
                                Collections.copy(longestPathFrom[j], longestPathFrom[i]);
                                longestPathFrom[j].add(j);
                            }
                        }
                    }
                }
                for (int i = 0; i < 26; i++) {
                    if (longestPathFrom[i].size() > longestPath.size()) {
                        longestPath = longestPathFrom[i];
                    }
                }
                Collections.reverse(longestPath);
                if (longestPath.size() == 0) {
                    pw.println('a');
                } else {
                    printGraph((longestPath.size() + 1) / 2, pw);
                }
            }
        }
        pw.flush();
        br.close();
        pw.close();
    }

    private static void printGraph(int size, PrintWriter pw) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                pw.print((char) ('a' + longestPath.get((i + j) % longestPath.size())));
            }
            pw.println();
        }
    }

    private static boolean[] seenTopSort;
    private static List<Integer> sorted;

    private static List<Integer> topSort() {
        sorted = new ArrayList<>();
        seenTopSort = new boolean[26];
        for (int i = 0; i < 26; i++) {
            if (!seenTopSort[i]) {
                visit(i);
            }
        }
        return sorted;
    }

    private static void visit(int i) {
        if (seenTopSort[i]) {
            return;
        }
        seenTopSort[i] = true;
        for (int j = 0; j < 26; j++) {
            if (graph[i][j]) {
                visit(j);
            }
        }
        sorted.add(i);

    }


    //bfs through graph and set longestPath
    //return true if a cycle was found
    //YES IT'S HORRIBLE
    public static boolean bfs(int st) {
        Queue<List<Integer>> Q = new LinkedList<>();
        List<Integer> first = new ArrayList<>();
        first.add(st);
        Set<Integer> seen = new HashSet<>();
        seen.add(st);
        Q.add(first);
        while (!Q.isEmpty()) {
            List<Integer> path = Q.poll();
            Integer from = path.get(path.size() - 1);
            for (int i = 0; i < 26; i++) {
                if (graph[from][i]) {
                    if (path.contains(i)) {
                        longestPath = new ArrayList<>();
                        for (int j = path.indexOf(i); j < path.size(); j++) {
                            longestPath.add(path.get(j));
                        }
                        return true;
                    } else if (!seen.contains(i)) {
                        seen.add(i);
                        List<Integer> nxtPath = new ArrayList<>();
                        for (int j = 0; j < path.size(); j++) {
                            nxtPath.add(path.get(j));
                        }
                        nxtPath.add(i);
                        Q.add(nxtPath);
                    }
                }
            }
        }
        return false;
    }
}

