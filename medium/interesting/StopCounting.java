package medium.interesting;

import java.util.Scanner;
//https://naq19.kattis.com/problems/stopcounting
public class StopCounting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] cards = new int[n];
        for (int i = 0; i < n; i++) {
            cards[i] = sc.nextInt();
        }
        double a = best(cards);
        int[] cardsB = new int[n];
        for (int i = 0; i < n; i++) {
            cardsB[i] = cards[n-i-1];
        }
        double b = best(cardsB);
        System.out.println(Math.max(a,b));
    }

    private static double best(int[] cards) {
        double best = 0;
        long sum = 0;
        for (int i = 0; i < cards.length; i++) {
            sum += cards[i];
            best = Math.max(best, sum/(i+1.0));
        }
        return best;
    }
}
