package math.equations;

import java.io.*;
import java.util.Arrays;

//https://www.spoj.com/problems/POLYMUL/
//TLE but it seems to work with the right time complexity so w/e
public class PolynomialMultiplication {

public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    int tests = Integer.parseInt(br.readLine());
    for (int t = 0; t < tests; t++) {
        int n = Integer.parseInt(br.readLine());
        // a.length==b.length==n+1
        long[] a = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
        long[] b = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
        for (int k = 0; k < a.length / 2; k++) {
            long tempA = a[k];
            long tempB = b[k];
            a[k] = a[a.length - (1 + k)];
            a[a.length - (1 + k)] = tempA;
            b[k] = b[b.length - (1 + k)];
            b[b.length - (1 + k)] = tempB;
        }
        long[] ans = multiply(0, a.length, a, b);
        for (int i = ans.length - 1; i > 0; i--) {
            bw.write(ans[i] + " ");
        }
        bw.write(ans[0] + "");
        bw.newLine();
        bw.flush();
    }
}

private static long[] multiply(int l, int r, long[] a, long[] b) {
    if (r - l <= 0) {
        return new long[0];
    }
    if (r - l == 1) {
        return new long[]{a[l] * b[l]};
    }
    int m = (l + r) / 2;
    
    long[] start = multiply(l, m, a, b);
    long[] end = multiply(m, r, a, b);
    int len = Math.max(r - m, m - l);
    long[] a1 = new long[len];
    long[] b1 = new long[len];
    for (int i = l; i < m; i++) {
        a1[i - l] += a[i];
        b1[i - l] += b[i];
    }
    for (int i = m; i < r; i++) {
        a1[i - m] += a[i];
        b1[i - m] += b[i];
    }
    long[] mid = multiply(0, a1.length, a1, b1);
    long[] ans = Arrays.copyOf(start, 2 * r - 2 * l - 1);
    int ind = 2 * m - 2 * l;
    for (int i = ind; i < ind + end.length; i++) {
        ans[i] += end[i - ind];
    }
    ind = m - l;
    for (int i = ind; i < ind + mid.length; i++) {
        int x = i - ind;
        ans[i] += mid[x];
        if (x < start.length) {
            ans[i] -= start[x];
        }
        if (x < end.length) {
            ans[i] -= end[x];
        }
    }
    return ans;
}
}
