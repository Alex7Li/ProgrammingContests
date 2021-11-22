package misc.gametheory;

import java.util.*;

// TLE but it only gives .5 seconds so I'm not going to even try to optimize it
class BowlingGame {
    private static int[] grundy;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            sc.nextLine();
            int n = sc.nextInt();
            int K = sc.nextInt();
            sc.nextLine();
            char[] pins = sc.nextLine().toCharArray();
            int xorSum = 0;
            List<Integer> intervalStarts = new ArrayList<Integer>();
            List<Integer> intervalLens = new ArrayList<Integer>();
            int nIntervals = 0;
            int longestInterval = 0;
            for (int j = 0; j < n; j++) {
                if (pins[j] == '1') {
                    if (j == 0 || pins[j - 1] == '0') {
                        intervalStarts.add(j);
                        intervalLens.add(0);
                        nIntervals++;
                    }
                    int newLen = intervalLens.get(nIntervals - 1) + 1;
                    intervalLens.set(nIntervals - 1, newLen);
                    longestInterval = Math.max(longestInterval, newLen);
                }
            }
            computeGrundy(longestInterval, K);
            for (int len : intervalLens) {
                xorSum ^= grundy[len];
            }
            if (xorSum == 0) {
                System.out.println("Johnny wins");
            } else {
                System.out.println("Mary wins");
                findValid:
                for (int size = K; size > 0; size--) {
                    for (int j = 0; j < intervalLens.size(); j++) {
                        int intervalLen = intervalLens.get(j);
                        for (int st = 0; st <= intervalLen - size; st++) {
                            if ((xorSum ^ grundy[intervalLen]) ==
                                    (grundy[st] ^ grundy[intervalLen - size - st])) {
                                //found a valid point
                                for (int k = st + intervalStarts.get(j); k < st + intervalStarts.get(j) + size; k++) {
                                    assert pins[k] == '1';
                                    pins[k] = '0';
                                }
                                StringBuilder sb = new StringBuilder();
                                for (int k = 0; k < n; k++) {
                                    sb.append(pins[k]);
                                }
                                System.out.println(sb);
                                break findValid;
                            }
                        }
                    }
                }
            }
            System.out.println();
        }
    }

    private static int[] computeGrundy(int n, int K) {
        grundy = new int[n + 1];
        grundy[0] = 0;
        for (int i = 1; i <= n; i++) {
            Set<Integer> reachableGrundy = new HashSet<>();
            for (int numHit = 1; numHit <= K; numHit++) {
                for (int stPos = 0; stPos < n; stPos++) {
                    int endPos = n - 1 + numHit - stPos;
                    reachableGrundy.add(grundy[stPos] ^ grundy[Math.min(0, endPos)]);
                }
            }
            int st = 0;
            while (reachableGrundy.contains(st)) {
                st++;
            }
            grundy[i] = st;
        }
        return grundy;
    }
}

