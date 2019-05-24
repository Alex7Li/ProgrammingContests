package core.string.implementation;

import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

//https://naq15.kattis.com/problems/quickbrownfox
public class QuickBrownFox {
public static void main(String[] xx) throws IOException {
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.nextLine());
    for (int t = 1; t <= n; t++) {
        Set<Character> set = new HashSet<>();
        for (char i = 'a'; i <= 'z'; i++) {
            set.add(i);
        }
        char[] s = sc.nextLine().toCharArray();
        for (int i = 0; i < s.length; i++) {
            set.remove(Character.toLowerCase(s[i]));
        }
        if (set.isEmpty()) {
            System.out.println("pangram");
        } else {
            System.out.print("missing ");
            for (char i : set) {
                System.out.print(i);
            }
            System.out.println();
        }
    }
    
}
}
