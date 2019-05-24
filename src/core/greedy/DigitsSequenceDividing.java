package core.greedy;

import java.util.Scanner;

//https://codeforces.com/contest/1107/problem/A
public class DigitsSequenceDividing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int n = sc.nextInt();
            sc.nextLine();
            String s = sc.nextLine();
            if(n>2 || s.charAt(0) < s.charAt(1)){
                System.out.println("YES");
                System.out.println(2);
                System.out.print(s.charAt(0)+ " ");
                System.out.println(s.substring(1));
            }else{
                System.out.println("NO");
            }
        }
    }
}
