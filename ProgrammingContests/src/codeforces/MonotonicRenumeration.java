package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
//https://codeforces.com/problemset/problem/1102/E
public class MonotonicRenumeration {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        int[] a = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        Element[] elements = new Element[n];
        for (int i = 0; i < n; i++) {
            elements[i] = new Element(a[i], i);
        }
        Arrays.sort(elements);
        int[] segmentsStarting = new int[n];
        segmentsStarting[elements[0].pos]++;
        for (int i = 0; i < n - 1; i++) {
            int val = elements[i].val;
            if (val != elements[i + 1].val) {
                segmentsStarting[elements[i].pos]--;
                segmentsStarting[elements[i + 1].pos]++;
            }
        }
        segmentsStarting[elements[n - 1].pos]--;
        int ways = 1;
        int curSegs = segmentsStarting[0];
        for (int i = 1; i < n; i++) {
            if(curSegs==0){
                ways = (ways*2)%998244353;
            }
            curSegs += segmentsStarting[i];
        }
        pw.println(ways);
        pw.flush();
        br.close();
        pw.close();
    }

    public static class Element implements Comparable<Element> {
        int val;
        int pos;

        public Element(int val, int pos) {
            this.val = val;
            this.pos = pos;
        }

        @Override
        public int compareTo(Element o) {
            if (this.val == o.val) {
                return this.pos - o.pos;
            } else {
                return this.val - o.val;
            }
        }
    }
}
