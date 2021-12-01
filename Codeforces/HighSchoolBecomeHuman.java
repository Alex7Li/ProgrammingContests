package codeforces;

import java.util.Scanner;
//http://codeforces.com/problemset/problem/987/B
public class HighSchoolBecomeHuman {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        sc.close();
        if(x==y || (x+y==6&&(x==2||y==2))){
            System.out.println("=");
        }else{
            if(y>x != ((x==1 || y==1) || ((2==x || 2==y) && (x+y==5)))){
                System.out.println(">");
            }else{
                System.out.println("<");
            }
        }
    }
}
