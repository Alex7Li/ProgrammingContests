package atcoder;

import java.util.Scanner;
//https://abc099.contest.atcoder.jp/tasks/abc099_b
public class StoneMonument {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int diff = sc.nextInt()-a;
        System.out.println((diff*(diff-1))/2-a);
        sc.close();
    }
}
