package codeforces;

import java.util.*;

//https://codeforces.com/gym/102004
public class CityMerger {
    private static int[][] distMat;
    private static int[][] memo;
    private static int n;
    private static int[] twoPow = new int[15];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.nextLine();
        twoPow[0] = 1;
        for (int i = 1; i < 15; i++) {
            twoPow[i] = twoPow[i - 1] * 2;
        }
        while (n != 0) {
            List<char[]> cities = new ArrayList<>();
            int tLen = 0;
            for (int i = 0; i < n; i++) {
                cities.add(sc.nextLine().toCharArray());
                tLen += cities.get(i).length;
            }
            //remove substrings
            for (int i = 0; i < cities.size(); i++) {
                for (int j = 0; j < cities.size(); j++) {
                    // if cities[i] is a substring of cities[j], remove cities[i]
                    if (i!=j && String.valueOf(cities.get(j)).indexOf(String.valueOf(cities.get(i))) != -1) {
                        tLen -= cities.get(i).length;
                        cities.remove(i);
                        i--;
                        break;
                    }
                }
            }
            n = cities.size();
            distMat = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        distMat[i][j] = sharedLen(cities.get(i), cities.get(j));
                    }
                }
            }
            //mask, 2^i is 1 iff that city has not been used yet
            int set = twoPow[n] - 1;
            memo = new int[twoPow[n]][n];
            for (int i = 0; i < twoPow[n]; i++) {
                for (int j = 0; j < n; j++) {
                    memo[i][j] = -1;
                }
            }
            for (int j = 0; j < n; j++) {
                memo[0][j] = 0;
            }
            int maxDist = 0;
            for (int i = 0; i < n; i++) {
                set -= twoPow[i];
                maxDist = Math.max(longestDist(set, i), maxDist);
                set += twoPow[i];
            }
            System.out.println(tLen - maxDist);
            n = sc.nextInt();
            sc.nextLine();
        }
    }

    // return the shortest distance using all nodes in S,
    // starting at st (not in S)
    public static int longestDist(int S, int st) {
        if (memo[S][st] != -1) {
            return memo[S][st];
        }
        int bestDist = 0;
        for (int i = 0; i < n; i++) {
            if ((S & twoPow[i]) == twoPow[i]) {
                S -= twoPow[i];
                memo[S][i] = longestDist(S, i);
                bestDist = Math.max(memo[S][i] + distMat[st][i], bestDist);
                S += twoPow[i];
            }
        }
        return bestDist;
    }

    // count max letters you can remove concatenating a,b
    public static int sharedLen(char[] a, char[] b) {
        //else stick b on the end of a
        for (int i = Math.max(0, a.length - b.length); i < a.length; i++) {
            boolean canCombine = true;
            for (int j = 0; i + j < a.length; j++) {
                if (a[i + j] != b[j]) {
                    canCombine = false;
                    break;
                }
            }
            if (canCombine) {
                return a.length - i;
            }
        }
        return 0;
    }
}
