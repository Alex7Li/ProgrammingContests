package other.acmclub;

import java.util.Arrays;
import java.util.Scanner;

public class CanonicalCoinSystems {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = sc.nextInt();
        }
        int size = a[a.length - 1] + a[a.length - 2] + 1;
        int[] greedy = new int[size];
        int[] optimal = new int[size];
        Arrays.fill(optimal,Integer.MAX_VALUE-1);
        for (int i = 0; i < size; i++) {
            for (int coinV : a) {
                int nxtCoin = i + coinV;
                if (nxtCoin < size) {
                    if (greedy[nxtCoin] == 0) {
                        greedy[nxtCoin] = greedy[i] + 1;
                    }
                    optimal[nxtCoin] = Math.min(1 + optimal[i], optimal[nxtCoin]);
                }
            }
        }
        if(Arrays.equals(greedy, optimal)){
            System.out.println("canonical");
        } else {
            System.out.println("non-canonical");
        }
    }
}
