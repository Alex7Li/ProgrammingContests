package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//https://codeforces.com/gym/102032
public class Squarow {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        int[] a = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
        List<Integer> aSeq = new ArrayList<>();
        //color->index
        Map<Integer, Integer> colors = new HashMap<>();
        aSeq.add(a[0]);
        colors.put(a[0], 0);

        for (int i = 1; i < a.length; i++) {
            if (a[i] != a[i - 1]) {
                aSeq.add(a[i]);
                if (!colors.containsKey(a[i])) {
                    colors.put(a[i], colors.size());
                }
            }
        }

        int[] blksRemoved = new int[colors.size()];
        blksRemoved[colors.get(aSeq.get(0))]++;
        if (aSeq.size() > 1) {
            blksRemoved[colors.get(aSeq.get(aSeq.size() - 1))]++;
        }

        for (int i = 1; i < aSeq.size() - 1; i++) {
            blksRemoved[colors.get(aSeq.get(i))]++;
            if (aSeq.get(i + 1).equals(aSeq.get(i - 1))) {
                blksRemoved[colors.get(aSeq.get(i))]++;
            }
        }
        int min = Integer.MAX_VALUE;
        int argMin = -1;
        for (Map.Entry<Integer, Integer> e : colors.entrySet()) {
            if (blksRemoved[e.getValue()] < min) {
                argMin = e.getKey();
                min = blksRemoved[e.getValue()];
            }
        }
        System.out.println((aSeq.size() - min) + " " + argMin);
    }
}
