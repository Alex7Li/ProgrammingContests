package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//http://codeforces.com/problemset/problem/1005/E1
public class MedianOnPermutationSegments {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        long[] leftBuckets = new long[n * 2 + 1];
        long[] rightBuckets = new long[n * 2 + 2];
        int[] permutation = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int mindex = -1;
        for (int i = 0; i < permutation.length; i++) {
            if(permutation[i]==m){
                mindex=i;
            }
        }
        int netGreaterElSeen = 0;
        for (int i = mindex; i >= 0; i--) {
            if (m < permutation[i]) {
                netGreaterElSeen++;
            } else if (m > permutation[i]) {
                netGreaterElSeen--;
            }
            leftBuckets[netGreaterElSeen + n]++;
        }

        netGreaterElSeen = 0;
        for (int i = mindex; i < permutation.length; i++) {
            if (m < permutation[i]) {
                netGreaterElSeen++;
            } else if (m > permutation[i]) {
                netGreaterElSeen--;
            }
            rightBuckets[netGreaterElSeen + n]++;
        }

        long count = 0;
        for (int i = 0; i < leftBuckets.length; i++) {
            count += leftBuckets[i] * rightBuckets[2 * n - i];
            count += leftBuckets[i] * rightBuckets[2 * n - i + 1];
        }
        System.out.println(count);
    }
}
