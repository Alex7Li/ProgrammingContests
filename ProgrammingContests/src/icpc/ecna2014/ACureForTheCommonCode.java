package icpc.ecna2014;

import java.util.Scanner;

// https://codeforces.com/gym/100641
public class ACureForTheCommonCode {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        char[] str = input.nextLine().toCharArray();
        int caseNo = 1;
        while (str[0] != '0') {
            int n = str.length;

            int[][] minLenDP = new int[n + 1][n + 1];

            for (int len = 1; len <= n; len++) {
                for (int st = 0; st <= n - len; st++) {
                    int end = st + len;
                    minLenDP[st][end] = len;

                    // find shortest length by adding previous strings
                    for (int mid = st + 1; mid < end; mid++) {
                        minLenDP[st][end] = Math.min(minLenDP[st][end],
                                minLenDP[st][mid] + minLenDP[mid][end]);
                    }

                    // see if we can get a shorter length by repeating substrings
                    for (int repeatedLen = 1; repeatedLen < len; repeatedLen++) {
                        if (len % repeatedLen == 0) {
                            boolean canRepeatStr = true;
                            for (int j = st; j < end - repeatedLen; j++) {
                                if (str[j] != str[j + repeatedLen]) {
                                    canRepeatStr = false;
                                }
                            }
                            if (canRepeatStr) {
                                // we can repeat
                                if (repeatedLen == 1) {
                                    minLenDP[st][end] = Math.min(minLenDP[st][end],
                                            minLenDP[st][st + repeatedLen] + ("" + len/repeatedLen).length());
                                } else {
                                    minLenDP[st][end] = Math.min(minLenDP[st][end],
                                            minLenDP[st][st + repeatedLen] + 2 + ("" + len/repeatedLen).length());
                                }
                            }
                        }
                    }
                }
            }
            System.out.println("Case " + caseNo + ": " + minLenDP[0][n]);
            str = input.nextLine().toCharArray();
            caseNo++;
        }
    }
}
