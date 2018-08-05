package codechef;

import java.util.Scanner;
//https://www.codechef.com/COOK94B/problems/KMXOR
public class BestCakeEver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            long n=sc.nextInt(), k=sc.nextInt();
            if(n==1){
                System.out.println(k);
            }else {
                StringBuilder ans = new StringBuilder();
                if(k==3 && n%2 ==1) {
                    ans.append("3 1 ");
                }else{
                    ans.append(Long.highestOneBit(k) + " ");
                    if (k == 1) {
                        ans.append("1 ");
                    } else if (n % 2 == 0) {
                        ans.append(Long.highestOneBit(k) - 1 + " ");
                    } else {
                        if (k == 2) {
                            ans.append("1 ");
                        } else {
                            ans.append(Long.highestOneBit(k) - 2 + " ");
                        }
                    }
                }
                for (int i = 2; i < n; i++) {
                    ans.append("1 ");
                }
                System.out.println(ans);
            }
        }
        sc.close();
    }
}
