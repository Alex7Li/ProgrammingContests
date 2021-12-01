package codeforces;

import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

//https://codeforces.com/problemset/problem/1111/A
public class SuperHeroTransformation {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        char[] n1 = sc.nextLine().toCharArray();
        char[] n2 = sc.nextLine().toCharArray();
        if (n1.length != n2.length) {
            System.out.println("No");
            return;
        }
        Set<Character> vowels = new HashSet<>();
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');
        for (int i = 0; i < n1.length; i++) {
            if (vowels.contains(n1[i]) != vowels.contains(n2[i])) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
