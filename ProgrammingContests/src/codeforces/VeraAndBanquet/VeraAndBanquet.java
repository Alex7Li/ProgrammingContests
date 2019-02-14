
import javafx.util.Pair;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class VeraAndBanquet {
    private static final long A = 3;
    private static final long B = 1073096513;

    private static final long A2 = 5231;
    private static final long B2 = 1080194147;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        char[] recipes = sc.nextLine().toCharArray();
        long ans = 0;
        long aPow = 1;
        long a2Pow = 1;
        for (int len = 1; len <= n; len++) {
            Set<Pair<Integer, Integer>> hashes = new HashSet<>();
            long curHash = 0;
            long hash2 = 0;
            for (int i = 0; i < len; i++) {
                curHash *= A;
                curHash = (curHash + recipes[i]) % B;
                hash2 *= A2;
                hash2 = (hash2 + recipes[i]) % B2;
            }
            for (int st = 0; st < n; st++) {
                curHash -= aPow * recipes[st];
                curHash *= A;
                curHash += recipes[(len + st) % n];
                hash2 -= a2Pow * recipes[st];
                hash2 *= A2;
                hash2 = (hash2 + recipes[(len + st) % n]) % B2;
                hashes.add(new Pair(curHash, hash2));
            }
            curHash = 0;
            hash2 = 0;
            for (int i = len - 1; i >= 0; i--) {
                curHash *= A;
                curHash = (curHash + recipes[i]) % B;
                hash2 *= A2;
                hash2 = (hash2 + recipes[i]) % B2;
            }
            for (int st = n - 1; st >= 0; st--) {
                curHash -= aPow * recipes[(st + len) % n];
                curHash *= A;
                curHash += recipes[st % n];
                hash2 -= a2Pow * recipes[(st + len) % n];
                hash2 *= A2;
                hash2 = (hash2 + recipes[st % n]) % B2;
                hashes.add(new Pair(curHash, hash2));
            }
            ans += hashes.size();
            aPow = (aPow * A) % B;
            a2Pow = (a2Pow * A2) % B2;
        }
        System.out.println(ans);
    }
}

