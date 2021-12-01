package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//https://codeforces.com/problemset/problem/1111/C
public class CreativeSnap {
    private static int n;
    private static int k;
    private static long A;
    private static long B;
    private static int[] positions;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] params = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        n = params[0];
        k = params[1];
        A = params[2];
        B = params[3];
        positions = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x) - 1).toArray();
        Arrays.sort(positions);
        System.out.println(cost(0, 1 << n, 0));
        br.close();
    }

    private static long cost(int st, int end, int avengerInd) {
        int stInd = avengerInd;
        int mid = (st + end) / 2;

        while (avengerInd < k && positions[avengerInd] < mid) {
            avengerInd++;
        }

        int midInd = avengerInd;
        while (avengerInd < k && positions[avengerInd] < end) {
            avengerInd++;
        }

        if (avengerInd - stInd == 0) {
            return A;
        }
        long destroyCost = (B * (avengerInd - stInd)) * (end - st);
        long splitCost = Integer.MAX_VALUE;
        if (end - st != 1) {
            splitCost = cost(st, mid, stInd) + cost(mid, end, midInd);
        }
        return Math.min(splitCost, destroyCost);
    }
}
