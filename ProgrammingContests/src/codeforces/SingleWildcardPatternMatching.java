package codeforces;

import java.util.Scanner;

//http://codeforces.com/contest/1023/problem/A
public class SingleWildcardPatternMatching {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        String s = sc.nextLine();
        String t = sc.nextLine();
        boolean valid = true;
        if (!s.contains("*")) {
            valid = s.equals(t);
        } else {
            int astInd = s.indexOf('*');
            if (astInd == 0) {
                valid = t.endsWith(s.substring(1, s.length()));
            } else if (astInd == s.length() - 1) {
                valid = t.startsWith(s.substring(0, s.length() - 1));
            } else {
                String[] sParts = s.split("\\*");
                if (s.length() <= 1 + t.length() && t.startsWith(sParts[0]) && t.endsWith(sParts[1])) {
                    valid = true;
                } else {
                    valid = false;
                }
            }
        }
        System.out.println(valid ? "YES" : "NO");
        sc.close();
    }
}
