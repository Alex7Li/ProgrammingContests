package core.string;

import java.io.IOException;
import java.util.Scanner;

// https://codeforces.com/contest/1166/problem/B
public class AllTheVowelsPlease {
public static void main(String[] xx) throws IOException {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    sc.close();
    int m = 1;
    for (int i = 5; i <= n; i++) {
        if (n % i == 0) {
            if (n / i >= 5) {
                n = n / i;
                m = i;
                break;
            }
        }
    }
    if (n < 5 || m < 5) {
        System.out.println(-1);
    } else {
        StringBuilder ans = new StringBuilder();
        char[] letters = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.append(letters[(i + j) % 5]);
            }
        }
        System.out.println(ans);
    }
}
}
