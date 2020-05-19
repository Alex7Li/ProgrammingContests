package easy.interesting;

import java.util.Scanner;
//https://open.kattis.com/problems/neighborhoodwatch
public class NeighborhoodWatch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        long k = sc.nextInt();
        long imposs = 0;
        long last = 0;
        //5 * 6/3 = 20
        for (int i = 0; i < k; i++) {
            int cur = sc.nextInt();
            imposs += ((cur-last-1)*(cur-last))/2;
            last = cur;
        }
        imposs += ((n-last+1)*(n-last))/2;
        System.out.println(((n*(n+1)))/2-imposs);
    }
}

