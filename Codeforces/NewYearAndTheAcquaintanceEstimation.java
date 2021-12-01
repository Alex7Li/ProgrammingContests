package codeforces;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

//https://codeforces.com/contest/1091/problem/E
public class NewYearAndTheAcquaintanceEstimation {
    private static List<Integer> a = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int n = Integer.parseInt(br.readLine());
        String[] aIn = br.readLine().split(" ");
        int parity = 0;
        for (int i = 0; i < n; i++) {
            a.add(Integer.parseInt(aIn[i]));
            parity += a.get(i) % 2;
        }
        parity = parity % 2;
        Collections.sort(a, Collections.reverseOrder());
        //bounds[0] = minimum degree possible
        //bounds[1] = maximum degree possible - 1
        int[] bounds = new int[2];
        for (int bound = 0; bound < 2; bound++) {
            int max = n + bound;
            int min = 0;
            while (min < max) {
                int mid = (max + min) / 2;
                int res = check(mid);
                if (res < bound) {//too low
                    min = mid + 1;
                } else {//too high
                    max = mid;
                }
            }
            bounds[bound] = min;
        }
        int min = bounds[0] % 2 == parity ? 0 : 1;
        min += bounds[0];
        if (min < bounds[1]) {
            pw.print(min);
            for (int i = min + 2; i < bounds[1]; i += 2) {
                pw.print(" " + i);
            }
            pw.println();
        } else {
            pw.println(-1);
        }
        pw.flush();
        br.close();
        pw.close();
    }

    // return 1 if val is too high for graph to work, -1 if too low, 0 if works.
    private static int check(int val) {
        int insertInd = a.size();
        if (a.get(0) <= val) {
            insertInd = 0;
        } else {
            for (int i = 0; i < a.size() - 1; i++) {
                if (a.get(i) >= val && a.get(i + 1) <= val) {
                    insertInd = i + 1;
                }
            }
        }
        a.add(insertInd, val);
        // use Erdos-Gallai theorem to check if it's possible
        long degSum = 0;
        long rightSum = 0;
        int rightInd = a.size();//first index that we sum more than i
        for (int i = 0; i < a.size(); i++) {
            degSum += a.get(i);
            if (rightInd == i) {
                rightSum -= a.get(rightInd);
                rightInd++;
            } else {
                while (rightInd > i + 1 && a.get(rightInd - 1) <= i) {
                    rightInd--;
                    rightSum += a.get(rightInd);
                }
            }
            if (degSum > (long) (i) * (i + 1) + rightSum + (long) (rightInd - i - 1) * (i + 1)) {
                if (a.get(i) > val) {
                    a.remove(insertInd);
                    return -1;
                } else {
                    a.remove(insertInd);
                    return 1;
                }
            }
        }
        a.remove(insertInd);
        return 0;
    }
}
