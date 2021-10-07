package codeforces;

import java.util.*;

//http://codeforces.com/problemset/problem/946/D
public class TimeTable {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int days = sc.nextInt();
        int hours = sc.nextInt();
        int skip = sc.nextInt();
        sc.nextLine();
        //maxSaved[i][j] max hours saved when removing exactly j classes from the ith day.
        int[][] maxSaved = new int[days][skip + 1];
        for (int i = 0; i < days; i++) {
            char[] desc = sc.nextLine().toCharArray();
            List<Integer> oneIndicies = new ArrayList<>();
            for (int j = 0; j < desc.length; j++) {
                if (desc[j] == '1') {
                    oneIndicies.add(j);
                }
            }
            //number of hours saved when only removing from the left
            int[] leftSaved = new int[oneIndicies.size() + 1];
            for (int j = 0; j < oneIndicies.size(); j++) {
                leftSaved[j] = oneIndicies.get(j);
            }
            leftSaved[oneIndicies.size()] = hours;
            //number of hours saved when removing only from the right
            int[] rightSaved = new int[oneIndicies.size() + 1];
            for (int j = 0; j < oneIndicies.size(); j++) {
                rightSaved[j] = hours - oneIndicies.get(oneIndicies.size() - j - 1) - 1;
            }
            rightSaved[oneIndicies.size()] = hours;
            //bestSaved[i]: max hours that can be saved skipping i days
            int[] bestSaved = new int[skip + 1];
            for (int j = 0; j <= Math.min(oneIndicies.size() - 1, skip); j++) {
                for (int k = 0; k <= j; k++) {
                    bestSaved[j] = Math.max(leftSaved[k] + rightSaved[j - k], bestSaved[j]);
                }
            }
            if (oneIndicies.size() < bestSaved.length) {
                for (int j = oneIndicies.size(); j < bestSaved.length; j++) {
                    bestSaved[j] = hours;
                }
            }
            maxSaved[i] = bestSaved;
        }
        int[] lastSaved = new int[skip + 1];
        //totalSaved[i]: the total number of hours saved skipping k classes
        int[] totalSaved = new int[skip + 1];
        for (int i = 0; i < days; i++) {
            //combine with maxSaved[i]
            for (int j = 0; j <= skip; j++) {
                for (int k = 0; k <= j; k++) {
                    totalSaved[j] = Math.max(lastSaved[k] + maxSaved[i][j - k], totalSaved[j]);
                }
            }
            lastSaved = totalSaved;
            totalSaved = new int[skip + 1];
        }
        System.out.println(days * hours - lastSaved[skip]);
    }
}