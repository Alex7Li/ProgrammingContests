package math.implementation;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

//https://codeforces.com/contest/1166/problem/A
public class SilentClassroom {
public static void main(String[] xx) throws IOException {
    Scanner sc = new Scanner(System.in);
    Map<Character, Integer> counts = new HashMap<>();
    int n = Integer.parseInt(sc.nextLine());
    for (int i = 0; i < n; i++) {
        Character fl = sc.nextLine().toCharArray()[0];
        counts.put(fl,counts.getOrDefault(fl,0)+1);
    }
    int ans = 0;
    for (int num : counts.values()){
        int lower = (num)/2;
        int higher = (num+1)/2;
        ans+=(lower*(lower-1))/2;
        ans+=(higher*(higher-1))/2;
    }
    System.out.println(ans);
    sc.close();
}
}
