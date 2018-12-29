package misc.aoc;

import java.util.*;

public class AOC2018Day1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = 0;
        List<Integer> freq = new ArrayList<>();
        String line = sc.nextLine();
        while(!line.equals("")){
            freq.add(Integer.parseInt(line));
            line = sc.nextLine();
        }
        Set<Integer> seen = new HashSet<>();
        int sum = 0;
        for (int i = 0;; i++) {
            if(seen.contains(sum)){
                System.out.println(sum);
                return;
            }
            seen.add(sum);
            sum+=freq.get(i%freq.size());
        }
    }
}
