package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//http://codeforces.com/contest/990/problem/E
public class PostLamps {
    private static int[] lastUnblocked;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] params = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int n = params[0];
        int m = params[1];
        int k = params[2];
        String[] blockedPosStr = br.readLine().split(" ");
        int[] blockedPos = new int[m];
        for (int i = 0; i < blockedPos.length; i++) {
            blockedPos[i] = Integer.parseInt(blockedPosStr[i]);
        }
        lastUnblocked = new int[n];
        for (int i = 0; i < blockedPos.length; i++) {
           lastUnblocked[blockedPos[i]] = -1;
        }
        lastUnblocked[0] = 0;
        for (int i = 1; i < n; i++) {
            if(lastUnblocked[i]==-1){
                lastUnblocked[i] = lastUnblocked[i-1];
            }else{
                lastUnblocked[i] = i;
            }
        }
        long[] costs = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
        br.close();
        int[] minLamps = new int[k];
        minLamps[k-1] = calcMinLamps(k,n);
        if ((blockedPos.length!=0 && blockedPos[0] == 0) ||minLamps[k-1] == Integer.MAX_VALUE - 10) {
            System.out.println("-1");
            return;
        }
        for (int i = 0; i < minLamps.length; i++) {
            if (minLamps[i] == 0) {
                minLamps[i] = calcMinLamps(i + 1, n);
            }
        }

        long bestCost = Long.MAX_VALUE;
        for (int i = 0; i < k; i++) {
            bestCost = Math.min(minLamps[i] * costs[i], bestCost);
        }
        System.out.println(bestCost);
    }

    private static int calcMinLamps(int size,  int n) {
        int lastPos = 0;
        int count = 1;
        while (lastPos+size < n) {
            Integer next = lastUnblocked[lastPos + size];
            if (next == lastPos) {
                return Integer.MAX_VALUE - 10;
            }
            lastPos = next;
            count++;
        }
        return count;
    }
}
