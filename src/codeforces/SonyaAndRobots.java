package codeforces;

import java.util.*;

public class SonyaAndRobots {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];

        Set<Integer> nums = new HashSet<>();
        //locations of numbers from the left/right
        ArrayList<Integer> lLoc = new ArrayList<>();
        ArrayList<Integer> rLoc = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if(!nums.contains(a[i])) {
                lLoc.add(i);
                nums.add(a[i]);
            }
        }
        nums.clear();
        for (int i = n-1; i >= 0; i--) {
            if(!nums.contains(a[i])){
                rLoc.add(-i); //for easy sorting
                nums.add(a[i]);
            }
        }

        Collections.sort(lLoc);
        Collections.sort(rLoc);

        long ans = 0;
        for (int r : rLoc) {
            r = -r;
            while (lLoc.size() > 0 && r <= lLoc.get(lLoc.size() - 1)) {
                lLoc.remove(lLoc.size() - 1);
            }
            ans += lLoc.size();
        }
        System.out.println(ans);
    }
}
