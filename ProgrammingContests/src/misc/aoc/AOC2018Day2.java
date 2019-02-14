package misc.aoc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AOC2018Day2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = 0;
        List<char[]> lines = new ArrayList<>();
        String line = sc.nextLine();
        while (!line.equals("")) {
            lines.add(line.toCharArray());
            line = sc.nextLine();
        }
        int twoCount = 0;
        int threeCount = 0;
        for (int i = 0; i < lines.size(); i++) {
            boolean hasTwo = false;
            boolean hasThree = false;
            for (char j = 'a'; j <= 'z'; j++) {
                int count = 0;
                for (int k = 0; k < lines.get(i).length; k++) {
                    if (lines.get(i)[k] == j) {
                        count++;
                    }
                }
                if (count == 3) {
                    hasThree = true;
                } else if (count == 2) {
                    hasTwo = true;
                }
            }
            if (hasThree) {
                threeCount++;
            }
            if (hasTwo) {
                twoCount++;
            }
        }
        System.out.println(twoCount * threeCount);
    }
}
