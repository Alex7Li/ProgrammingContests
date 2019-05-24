package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

//https://codeforces.com/problemset/problem/1108/E2
public class ArrayAndSegments {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int[] params = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int n = params[0];
        int m = params[1];
        int[] a = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        TreeSet<Integer> endpoints = new TreeSet<>();
        Segment[] segments = new Segment[m];
        for (int i = 0; i < m; i++) {
            int[] in = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(x -> Integer.parseInt(x)).toArray();
            int st = in[0] - 1;
            int end = in[1];
            segments[i] = new Segment(st, end - 1, i + 1);
            endpoints.add(st);
            endpoints.add(end);
        }
        endpoints.add(0);
        endpoints.remove(n);

        // map from location in the input array to the location in shortened array.
        Map<Integer, Integer> effectiveLocation = new HashMap<>();
        int ind = 0;
        for (int point : endpoints) {
            effectiveLocation.put(point, ind++);
        }

        int[] max = new int[effectiveLocation.size()];
        int[] min = new int[effectiveLocation.size()];
        Arrays.fill(min, Integer.MAX_VALUE);
        Arrays.fill(max, Integer.MIN_VALUE);
        ind = -1;
        for (int i = 0; i < n; i++) {
            if (endpoints.contains(i)) {
                ind++;
            }
            max[ind] = Math.max(max[ind], a[i]);
            min[ind] = Math.min(min[ind], a[i]);
        }

        List<Integer> bestSet = new ArrayList<>();
        List<Integer> curSet = new ArrayList<>();
        int best = 0;
        // for every pair of two points, subtract from low as much as possible to get the solution
        for (int highInd : endpoints) {
            for (int lowInd : endpoints) {
                int count = 0;
                for (Segment seg : segments) {
                    // if (lowInd in segment) and (highInd not in segment)
                    if ((seg.start <= lowInd && seg.end >= lowInd) && (seg.start > highInd || seg.end < highInd)) {
                        count++;
                        curSet.add(seg.index);
                    }
                }
                int diff = max[effectiveLocation.get(highInd)] - min[effectiveLocation.get(lowInd)] + count;
                if (diff > best) {
                    bestSet = curSet;
                    curSet = new ArrayList<>();
                    best = diff;
                }
                curSet.clear();
            }
        }

        pw.println(best);
        pw.println(bestSet.size());
        for (int i = 0; i < bestSet.size() - 1; i++) {
            pw.print(bestSet.get(i) + " ");
        }
        if(!bestSet.isEmpty()) {
            pw.print(bestSet.get(bestSet.size() - 1));
        }
        pw.println();
        pw.flush();
        br.close();
        pw.close();
    }

    private static class Segment {
        int start;
        int end;
        int index;

        public Segment(int st, int end, int ind) {
            start = st;
            this.end = end;
            index = ind;
        }
    }
}
