package math.equations;

import java.util.Scanner;
//https://www.codechef.com/COOK94B/problems/CHEFRUN
public class SecretRecipe {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            long x1=sc.nextInt(),x2=sc.nextInt(),x3=sc.nextInt(),
                    v1=sc.nextInt(),v2=sc.nextInt();
            if(Math.abs(x3-x1)*v2 == Math.abs(x3-x2)*v1){
                System.out.println("Draw");
            }else if(Math.abs(x3-x1)*v2 < Math.abs(x3-x2)*v1){
                System.out.println("Chef");
            }else{
                System.out.println("Kefa");
            }

        }
        sc.close();
    }
}
