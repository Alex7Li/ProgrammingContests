package codeforces;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
//http://codeforces.com/problemset/problem/1008/A
public class Romanji {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] word = sc.nextLine().toCharArray();
        char lastLetter = word[word.length - 1];
        Character[] v = {'a', 'e', 'i', 'o', 'u'};
        Set<Character> vowels = new HashSet<>();
        vowels.addAll(Arrays.asList(v));
        if (!vowels.contains(lastLetter) && lastLetter != 'n') {
            System.out.println("NO");
            return;
        }
        for (int i = 0; i < word.length - 1; i++) {
            if (!vowels.contains(word[i]) && word[i] != 'n') {
                if (!vowels.contains(word[i + 1])) {
                    System.out.println("NO");
                    return;
                }
            }
        }
        System.out.println("YES");
    }
}
