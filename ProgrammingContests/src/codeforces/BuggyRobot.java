package codeforces;

import java.util.Scanner;

public class BuggyRobot {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        s.nextLine();
        char[] commands = s.nextLine().toCharArray();
        s.close();
        int us = 0;
        int ds = 0;
        int rs = 0;
        int ls = 0;
        for (int i = 0; i < commands.length; i++) {
            switch (commands[i]) {
                case 'U':
                    us++;
                    break;
                case 'D':
                    ds++;
                    break;
                case 'R':
                    rs++;
                    break;
                case 'L':
                    ls++;
                    break;
            }
        }
        System.out.println(us + ds + rs + ls - Math.abs(us - ds) - Math.abs(rs - ls));
    }
}
