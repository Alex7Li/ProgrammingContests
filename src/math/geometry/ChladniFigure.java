package math.geometry;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//http://codeforces.com/contest/1161/problem/B
public class ChladniFigure {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] params = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int n = params[0];
        int m = params[1];
        List<Integer>[] points = new List[n];
        for (int i = 0; i < n; i++) {
            points[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            params = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(x -> Integer.parseInt(x)).toArray();
            int s = params[0];
            int e = params[1];
            points[s % n].add((n + e - s) % n);
            points[e % n].add((n + s - e) % n);
        }
        for (int i = 0; i < n; i++) {
            Collections.sort(points[i]);
        }
        Set<Integer> factors = new HashSet<>();
        int nCopy = n;
        for (int i = 2; i * i <= nCopy; i++) {
            if (nCopy % i == 0) {
                factors.add(i);
                while (nCopy % i == 0) {
                    nCopy /= i;
                }
            }
        }
        if (nCopy != 1) {
            factors.add(nCopy);
        }
        for (int i : factors) {
            int dist = n / i;
            boolean possible = true;
            for (int j = 0; j < n; j++) {
                if (!points[j].equals(points[(j + dist) % n])) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}
