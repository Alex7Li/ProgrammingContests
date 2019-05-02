package codechef;

import java.util.Arrays;
import java.util.Scanner;

//https://www.codechef.com/problems/TWONIM
class DualNim {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < n; i++) {
            int p = Integer.parseInt(sc.nextLine());
            int xorsum = 0;
            int[] a = Arrays.stream(sc.nextLine().split(" "))
                    .mapToInt(x -> Integer.parseInt(x)).toArray();
            for (int v : a) {
                xorsum ^= v;
            }
            if (p % 2 == 0 || xorsum == 0) {
                System.out.println("First");
            } else {
                System.out.println("Second");
            }
        }
    }
}
