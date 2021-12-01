package codeforces;

public class PetrPermutationTest {
    private static int n = 100000;
    private static int sum = 0;

    public static void main(String[] args) {
        int correct = 0;
        for (int t = 0; t < 100; t++) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = i + 1;
            }
            int f = 3;
            if(Math.random()>.5) {
                f = 7;
            }
            for (int i = 0; i < n * f; i++) {
                int ind1 = (int) (Math.random() * n);
                int ind2 = (int) (Math.random() * n);
                int temp = a[ind1];
                a[ind1] = a[ind2];
                a[ind2] = temp;
            }
            if(f==guess(a)) {
                correct++;
            }
        }
        System.out.println(correct);
        System.out.println(sum);
    }

    private static int guess(int[] a) {
        int swaps = 0;
        for (int i = 1; i <= n; i++) {
            if (i==a[i-1]) {
                swaps++;
            }
        }
        sum+=swaps;
        if (n <= 499*swaps) {
            return 3;
        } else {
            return 7;
        }
    }

}
