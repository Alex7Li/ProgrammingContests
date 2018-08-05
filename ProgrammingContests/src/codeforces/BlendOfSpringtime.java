package codeforces;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

//http://codeforces.com/contest/989/problem/A
public class BlendOfSpringtime {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] flowers = sc.nextLine().toCharArray();
        sc.close();
        Set<Character> ans = new HashSet<>();
        ans.add('A');
        ans.add('B');
        ans.add('C');
        for (int i = 0; i < flowers.length - 2; i++) {
            Set<Character> s = new HashSet<>();
            for (int j = i; j < i + 3; j++) {
                s.add(flowers[j]);
            }
            if (s.equals(ans)) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}
