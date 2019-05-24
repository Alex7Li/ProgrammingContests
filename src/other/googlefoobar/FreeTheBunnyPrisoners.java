package other.googlefoobar;

import java.util.*;

public class FreeTheBunnyPrisoners {
    public static void main(String[] args) {
        System.out.println(answer(1,0));

    }

    // if anyone is reading this code... these questions are really f***ing good
    // Plan: initially, each bunny has all keys.
    // Then, each set of k-1 bunnies should be
    // missing exactly 1 key (for minimality).
    // To ensure alphabetic order, just remove the
    // keys for each set, going through the sets
    // in an orderly way.
    public static int[][] answer(int N, int K) {
        //each set of K-1 bunnies must be missing a distinct
        //key, giving a lower bound on the number of keys
        if(K==0){
            return new int[N][0];
        }
        int nKeys = choose(N, K - 1);
        //keys each bunny holds
        int keysPerBunny = (nKeys * (N - K + 1)) / N;

        int numEachKey = (N * keysPerBunny) / nKeys;
        int numToRem = N - numEachKey;

        Set<Integer> keys[] = new HashSet[N];
        for (int i = 0; i < keys.length; i++) {
            keys[i] = new HashSet<>();
            for (int j = 0; j < nKeys; j++) {
                keys[i].add(j);
            }
        }

        int[] comb = new int[numToRem];
        for (int i = 0; i < comb.length; i++) {
            comb[i] = i;
        }

        for (int i = nKeys - 1; i >= 0; i--) {
            for (int j = 0; j < comb.length; j++) {
                keys[comb[j]].remove(i);
            }
            comb = nextComb(comb, N);
        }

        int[][] ans = new int[N][keysPerBunny];
        for (int i = 0; i < ans.length; i++) {
            int j = 0;
            for (Integer x : keys[i]) {
                ans[i][j] = x;
                j++;
            }
        }
        return ans;
    }

    public static int[] nextComb(int[] comb, int N) {
        for (int i = comb.length - 1; i >= 0; i--) {
            if (comb[i] < N - (comb.length-i)) {
                comb[i]++;
                for (int j = i+1; j < comb.length; j++) {
                    comb[j] = comb[i]+(j-i);
                }
                break;
            }
        }
        return comb;
    }

    public static int choose(int n, int k) {
        return fact(n) / (fact(k) * fact(n - k));
    }

    public static int fact(int n) {
        if (n == 0) {
            return 1;
        } else {
            return fact(n - 1) * n;
        }
    }
}
