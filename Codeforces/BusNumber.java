package codeforces;

import java.util.*;

//http://codeforces.com/contest/991/problem/E
public class BusNumber {
    private static long[] fact = new long[20];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        fact[0] = 1;
        for (int i = 1; i < fact.length; i++) {
            fact[i] = i * fact[i - 1];
        }
        char[] num = sc.nextLine().toCharArray();
        Map<Character, Integer> countMap = new HashMap<>();
        for (char c : num) {
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
        }
        int zeroCount = -1;
        if (countMap.containsKey('0')) {
            zeroCount = countMap.get('0');
            countMap.remove('0');
        }
        ArrayList<Integer> counts = new ArrayList<>();
        for (Integer i : countMap.values()) {
            counts.add(i);
        }
        Collections.sort(counts);
        long sum = 0;
        for (int i = 1; i <= zeroCount; i++) {
            //System.out.println(i + " " + counts);
            sum += solve(i, counts, 0);
        }
        if(zeroCount==-1){
            sum = solve(-1,counts,0);
        }
        System.out.println(sum);
    }

    private static long solve(int zeros, ArrayList<Integer> dCounts, int index) {
        long ways = 0;
        if (index == dCounts.size()) {
            //count num digits
            int sum = Math.max(0, zeros);
            for (int i : dCounts) {
                sum += i;
            }

            //calc ways for these permutations
            ways = fact[sum];
            for (int i : dCounts) {
                ways /= fact[i];
            }
            if (zeros != -1) {
                ways *= (sum - zeros);
                ways /= fact[zeros];
                ways /= sum;
            }
        } else { //recurse to find all permutations with same starting dCount
            int max = dCounts.get(index);
            for (int i = 1; i <= max; i++) {
                dCounts.set(index, i);
                ways += solve(zeros, dCounts, index + 1);
            }
        }

        return ways;
    }
}
