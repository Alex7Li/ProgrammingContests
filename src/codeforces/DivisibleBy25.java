package codeforces;

import java.util.*;

//http://codeforces.com/problemset/problem/988/E
//EDGE CASE HELL
public class DivisibleBy25 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();

        ArrayList<Integer> zeroInd = new ArrayList<>();
        int twoInd = -1;
        int sevInd = -1;
        int fiveInd = -1;

        List<Character> digits = new ArrayList<>();
        for (int i = 0; i < n.length(); i++) {
            int val = Character.getNumericValue(n.charAt(i));
            switch (val) {
                case 0:
                    zeroInd.add(n.length() - i - 1);
                    break;
                case 2:
                    twoInd = n.length() - i - 1;
                    break;
                case 7:
                    sevInd = n.length() - i - 1;
                    break;
                case 5:
                    fiveInd = n.length() - i - 1;
                    break;
            }
        }
        for (int i = n.length() - 1; i >= 0; i--) {
            digits.add(n.charAt(i));
        }

        int zeros = 0;
        if(fiveInd==n.length()-1){
            for(int i = 1;i<n.length(); i++){
                if(i==n.length()-1 && n.length()>3 && n.charAt(i)!=0){
                    System.out.println(-1);
                    return;
                }else{
                    if(Character.getNumericValue(n.charAt(i))==0){
                        zeros++;
                    }else{
                        break;
                    }
                }

            }
        }

        int minSwitch = Integer.MAX_VALUE;
        //try 00
        if (zeroInd.size() >= 2) {
            minSwitch = (zeroInd.get(zeroInd.size() - 1) + zeroInd.get(zeroInd.size() - 2)) - 1;
        }
        //try 25
        if (fiveInd != -1 && twoInd != -1) {
            int cost = fiveInd + twoInd - 1 + zeros;
            if (fiveInd > twoInd) {
                cost++;
            }
            minSwitch = Math.min(minSwitch, cost);
        }
        //50
        if (fiveInd != -1 && zeroInd.size() >= 1) {
            int cost = fiveInd + zeroInd.get(zeroInd.size() - 1) - 1 + Math.max(zeros-1,0);
            if (zeroInd.get(zeroInd.size() - 1) > fiveInd) {
                cost++;
            }
            minSwitch = Math.min(minSwitch, cost);
        }
        //75
        if (fiveInd != -1 && sevInd != -1) {
            int cost = fiveInd + sevInd - 1 + zeros;
            if (fiveInd > sevInd) {
                cost++;
            }
            minSwitch = Math.min(minSwitch, cost);
        }
        System.out.println(minSwitch == Integer.MAX_VALUE ? -1 : minSwitch);
    }
}
