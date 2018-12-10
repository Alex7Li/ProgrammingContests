package kattis;

import java.util.Scanner;
//https://naq18.kattis.com/
//by vlad not me
public class DasBlinkenlights {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int f = sc.nextInt();
        int n = sc.nextInt();
        int s = sc.nextInt();
        int min;
        if (f <= n) {
            min = f;
        }
        else {
             min = n;
        }
        int max = -1;
        for (int i = 1; i <= min; i++) {
            if ((f % i == 0)&&(n % i == 0)) {
                max = i;
            }
        }
        int result = (f * n) / max;
        if (result <= s) {
            System.out.println("yes");
        }
        else {
            System.out.println("no");
        }
    }
}
