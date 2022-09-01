package core.bruteforce.MeetInTheMiddle;

import java.util.*;

// http://codeforces.com/contest/1006/problem/F
public class XorPaths {
    private static int MAX_SIZE = 20;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long k = sc.nextLong();
        long[][] grid = new long[MAX_SIZE][MAX_SIZE];
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            grid[i][j] = sc.nextLong();
          }
        }
        sc.close();
        ArrayList<ArrayList<Map<Long, Long>>> maps = new ArrayList<>();
        for (int i = 0; i < MAX_SIZE; i++) {
            maps.add(new ArrayList<>());
            for (int j = 0; j < MAX_SIZE; j++) {
                maps.get(i).add(new HashMap<>());
            }
        }
        for (int flip = 0; flip < 2; flip++) {
            maps.get(0).get(0).put(grid[0][0], 1L);
            for (int dist = 1; dist < MAX_SIZE - flip; dist++) {
                for (int i = 0; i <= dist; i++) {
                    int j = dist - i;
                    Map<Long, Long> hm = maps.get(i).get(j);
                    if (i != 0) {
                        for (Map.Entry<Long, Long> val : maps.get(i - 1).get(j).entrySet()) {
                            hm.put(val.getKey() ^ grid[i][j], val.getValue());
                        }
                    }
                    if (j != 0) {
                        for (Map.Entry<Long, Long> val : maps.get(i).get(j - 1).entrySet()) {
                            long key = val.getKey() ^ grid[i][j];
                            hm.put(key, val.getValue() + hm.getOrDefault(key, 0L));
                        }
                    }
                }
            }
            //switch (i,j) with (MAX_SIZE-i-1,MAX_SIZE-j-1) for all (i,j)
            for (int i = 0; i < MAX_SIZE; i++) {
                for (int j = 0; j < MAX_SIZE - i; j++) {
                    Map<Long, Long> temp = maps.get(i).get(j);
                    maps.get(i).set(j, maps.get(MAX_SIZE - i - 1).get(MAX_SIZE - j - 1));
                    maps.get(MAX_SIZE - i - 1).set(MAX_SIZE - j - 1, temp);
                    long temp2 = grid[i][j];
                    grid[i][j] = grid[MAX_SIZE - i - 1][MAX_SIZE - j - 1];
                    grid[MAX_SIZE - i - 1][MAX_SIZE - j - 1] = temp2;
                }
            }
        }
        if (n - 1 + m - 1 < MAX_SIZE) {
            System.out.println(maps.get(n - 1).get(m - 1).getOrDefault(k, 0L));
            return;
        }
        long ways = 0;
        for (int i = MAX_SIZE - m; i < n; i++) {
            int j = MAX_SIZE - i - 1;
            Map<Long, Long> thismap = maps.get(i).get(j);
            if (i < n - 1) {
                Map<Long, Long> nMap = maps.get(i + 1).get(j);
                for (Map.Entry<Long, Long> e : thismap.entrySet()) {
                    ways += e.getValue() * nMap.getOrDefault(e.getKey() ^ k, 0L);
                }
            }
            if (j < m - 1) {
                Map<Long, Long> mMap = maps.get(i).get(j + 1);
                for (Map.Entry<Long, Long> e : thismap.entrySet()) {
                    ways += e.getValue() * mMap.getOrDefault(e.getKey() ^ k, 0L);
                }
            }
        }
        System.out.println(ways);
    }
}
