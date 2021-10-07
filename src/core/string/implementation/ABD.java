package core.string.implementation;

import java.util.Scanner;
// https://abc099.contest.atcoder.jp/tasks/abc099_a
public class ABD {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n<1000){
            System.out.println("ABC");
        }else{
            System.out.println("ABD");
        }
        sc.close();
    }
}
