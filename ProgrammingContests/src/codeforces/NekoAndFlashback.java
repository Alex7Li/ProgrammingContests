package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

// http://codeforces.com/contest/1152/problem/E
public class NekoAndFlashback {
    public void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine()) - 1;
        int[] b = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int[] c = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        // validity check 1
        for (int i = 0; i < n; i++) {
            if (b[i] > c[i]) {
                System.out.println(-1);
                return;
            }
        }

        // read input
        Map<Integer, MultiSet> edges = new HashMap<>();
        for (int i = 0; i < n; i++) {
            MultiSet bMultiSet = edges.getOrDefault(b[i], new MultiSet());
            bMultiSet.add(c[i]);
            edges.put(b[i], bMultiSet);
            MultiSet cMultiSet = edges.getOrDefault(c[i], new MultiSet());
            cMultiSet.add(b[i]);
            edges.put(c[i], cMultiSet);
        }

        // validity check 2: there exists a euclidean cycle
        int[] edgeNums = {0, 0};
        for (Map.Entry<Integer, MultiSet> p : edges.entrySet()) {
            if (p.getValue().size % 2 == 1) {
                if (edgeNums[0] == 0) {
                    edgeNums[0] = p.getKey();
                } else if (edgeNums[1] == 0) {
                    edgeNums[1] = p.getKey();
                } else {
                    System.out.println(-1);
                    return;
                }
            }
        }

        // Make a euclidean path
        int start = edgeNums[0];
        if (start == 0) {
            start = b[0];
        }
        Queue<Integer> path = getEuclideanPath(edges, start);
        // make sure it's possible (Graph may not be connected)
        if (path == null) {
            System.out.println(-1);
            return;
        }
        pw.print(path.remove());
        for (int i = 0; i < n; i++) {
            pw.print(" " + path.remove());
        }
        pw.flush();
        br.close();
        pw.close();
    }

    /*
     * @return a euclidean path from start, or null if none exist
     */
    private static Queue<Integer> getEuclideanPath(Map<Integer, MultiSet> edges, int start) {
        ArrayDeque<Integer> curPath = new ArrayDeque<>();
        Queue<Integer> finalPath = new ArrayDeque<>();

        int last = start;

        int nEdges = 0;
        for (Map.Entry<Integer, MultiSet> node : edges.entrySet()) {
            nEdges += node.getValue().size;
        }

        loop:
        while (nEdges != 0) {
            while (edges.get(last).size > 0) {
                curPath.push(last);
                int next = edges.get(last).getAny();
                edges.get(last).remove(next);
                edges.get(next).remove(last);
                nEdges -= 2;
                last = next;
            }
            while (edges.get(last).size == 0) {
                if (curPath.size() == 0) {
                    break loop;
                }
                finalPath.add(last);
                last = curPath.pop();
            }
        }
        finalPath.add(last);
        if (nEdges == 0) {
            return finalPath;
        } else {
            return null;
        }
    }

    private class MultiSet {
        Map<Integer, Integer> mSet = new HashMap<>();
        int size = 0;

        void add(int element) {
            mSet.put(element, mSet.getOrDefault(element, 0) + 1);
            size++;
        }

        void remove(int element) {
            int curCount = mSet.get(element);
            if (curCount <= 0) {
                throw new RuntimeException();
            } else if (curCount == 1) {
                mSet.remove(element);
            } else {
                mSet.put(element, curCount - 1);
            }
            size--;
        }

        /**
         * return any int corresponding to a given key
         */
        Integer getAny() {
            return mSet.keySet().iterator().next();
        }

    }


    public static void main(String[] args) throws IOException {
        NekoAndFlashback solution = new NekoAndFlashback();
        solution.solve();
    }
}
