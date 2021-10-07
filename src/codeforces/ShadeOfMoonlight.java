package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//http://codeforces.com/contest/989/problem/D
public class ShadeOfMoonlight {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] params = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int n = params[0];
        int l = params[1];
        int v = params[2];
        TreeSet<Integer> rightClouds = new TreeSet<>();
        Collection<Integer> leftClouds = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            if (Integer.parseInt(line[1]) == 1) {
                rightClouds.add(Integer.parseInt(line[0]));
            } else {
                leftClouds.add(Integer.parseInt(line[0]));
            }
        }

        Map<Integer, Integer> headSetSize = new HashMap<>();
        headSetSize.put(null, 0);
        int before = 1;
        for (int i : rightClouds) {
            headSetSize.put(i, before);
            before++;
        }

        long count = 0;
        for (int c : leftClouds) {
            int upper = lessThanDiv((v - 1L) * (c + l), v + 1);
            int maxDist = Math.min(upper, c - 1); //inclusive
            int minDist = Math.min(-c - l, maxDist + 1); //inclusive
            count += headSetSize.get(rightClouds.floor(maxDist)) -
                    headSetSize.get(rightClouds.lower(minDist));
            maxDist = Math.min(minDist, -c - l) - 1;
            maxDist = Math.min(maxDist, lessThanDiv((c + l) * (v + 1L), (v - 1)));
            count += headSetSize.get(rightClouds.floor(maxDist));
        }
        System.out.println(count);
    }

    public static int lessThanDiv(long num, long denom) {
        if (denom != 0) {
            return (int) Math.floorDiv(num - 1, denom);
        } else {
            if (num > 0) {
                return Integer.MAX_VALUE - 10;
            } else {
                return Integer.MIN_VALUE + 10;
            }
        }
    }
}
