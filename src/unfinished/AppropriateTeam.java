package unfinished;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class AppropriateTeam {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[] params = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
        long X = params[1];
        long Y = params[2];
        if (Y % X != 0) {
            System.out.println(0);
            return;
        }
        ArrayList<Long> yFact = new ArrayList<>();
        ArrayList<Long> primes = new ArrayList<>();
        for (long i = 2; i * i <= Y; i++) {
            if (Y % i == 0) {
                long fact = i;
                while (Y % (fact * i) == 0) {
                    fact *= i;
                }
                yFact.add(fact);
                primes.add(i);
            }
        }
        if (primes.size() == 0) {
            primes.add(Y);
            yFact.add(Y);
        }
        ArrayList<Long> xFact = new ArrayList<>();
        for (long i : primes) {
            long fact = 1L;
            while (X % (fact * i) == 0) {
                fact *= i;
            }
            xFact.add(fact);
        }
        long[] a = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
        long[] gcdMask = new long[1 << primes.size()];
        for (int i = 0; i < a.length; i++) {
            if (a[i] % X != 0) {
                continue;
            }
            int mask = 0;
            for (int j = 0; j < primes.size(); j++) {
                if (a[i] % (xFact.get(j)*primes.get(j)) != 0) {
                    mask += (1 << j);
                }
            }
            gcdMask[mask]++;
        }
        long[] lcmMask = new long[1 << primes.size()];
        for (int i = 0; i < a.length; i++) {
            if (Y % a[i] != 0) {
                continue;
            }
            int mask = 0;
            for (int j = 0; j < primes.size(); j++) {
                if (a[i] % (yFact.get(j)) == 0) {
                    mask += (1 << j);
                }
            }
            lcmMask[mask]++;
        }
        long ways = 0;
        for (int i = 0; i < gcdMask.length; i++) {
            int j = i;
            while (j != 0) {
                ways += gcdMask[i] * lcmMask[j];
                j = (j - 1) & i;
            }
            ways += gcdMask[0] * lcmMask[j];
        }
        System.out.println(ways);
    }
}
