package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
//https://codeforces.com/problemset/problem/1106/B
public class LunarNewYearAndFoodOrdering {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int[] params = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int n = params[0];
        int m = params[1];
        int[] dishCounts = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int[] costs = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        PriorityQueue<Cost> cheapest = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            cheapest.add(new Cost(i, costs[i]));
        }
        for (int i = 0; i < m; i++) {
            String[] order = br.readLine().split(" ");
            int type = Integer.parseInt(order[0])-1;
            long number = Integer.parseInt(order[1]);
            long cost = 0;
            if(dishCounts[type]!=0) {
                long bought = Math.min(dishCounts[type], number);
                cost += bought * costs[type];
                dishCounts[type] -= bought;
                number -= bought;
            }
            while(number!=0 && !cheapest.isEmpty()){
                Cost next = cheapest.poll();
                if(dishCounts[next.index]!=0){
                    long bought = Math.min(dishCounts[next.index], number);
                    cost += bought * next.cost;
                    dishCounts[next.index] -= bought;
                    number -= bought;
                    if(dishCounts[next.index]!=0){
                        cheapest.add(next);
                    }
                }
            }
            if(number>0){
                pw.println(0);
            }else {
                pw.println(cost);
            }
        }

        pw.flush();
        br.close();
        pw.close();
    }

    public static class Cost implements Comparable<Cost>{
        int index;
        int cost;

        public Cost(int ind, int c) {
            index = ind;
            cost = c;
        }

        @Override
        public int compareTo(Cost o) {

            if(cost != o.cost){
                return Integer.compare(cost, o.cost);
            }else{
                return Integer.compare(index, o.index);
            }
        }
    }
}
