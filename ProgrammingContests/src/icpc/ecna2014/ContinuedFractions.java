package icpc.ecna2014;

import java.io.PrintWriter;
import java.util.Scanner;

//https://codeforces.com/gym/100641
public class ContinuedFractions {

    private static long[] fromPartFraction(long[] arr) {
        long num = arr[arr.length - 1];
        long denom = 1;

        for (int i = arr.length - 2; i >= 0; i--) {
            long temp = num;
            num = denom;
            denom = temp;
            num = arr[i] * denom + num;
        }
        long[] ret = {num, denom};
        return ret;
    }

    private static void convertAndPrint(long[] arr, PrintWriter out) {
        if (arr[0] % arr[1] != 0) {
            long whole = Math.floorDiv(arr[0], arr[1]);
            out.print(whole + " ");
            long temp = arr[1];
            arr[1] = arr[0] - whole * arr[1];
            arr[0] = temp;
            convertAndPrint(arr, out);
        } else {
            out.println(arr[0] / arr[1]);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int a = in.nextInt();
        int b = in.nextInt();
        int caseNum = 1;
        while (a != 0 && b != 0) {
            out.println("Case " + caseNum++ + ":");
            long[] arrA = new long[a];
            long[] arrB = new long[b];

            for (int i = 0; i < a; i++) {
                arrA[i] = in.nextInt();
            }

            for (int i = 0; i < b; i++) {
                arrB[i] = in.nextInt();
            }
            long [] ans = new long [2];

            /*add*/
            long[] ratA = fromPartFraction(arrA);
            long[] ratB = fromPartFraction(arrB);

            ans[0] = ratA[0] * ratB[1] + ratA[1] * ratB[0];
            ans[1] = ratA[1] * ratB[1];
            convertAndPrint(ans, out);


            /* subtract*/
            ans[0] = ratA[0] * ratB[1] - ratA[1] * ratB[0];
            ans[1] = ratA[1] * ratB[1];
            convertAndPrint(ans, out);

            /* multiply */
            ans[0] = ratA[0] * ratB[0];
            ans[1] = ratA[1] * ratB[1];
            convertAndPrint(ans, out);

            /* divide */
            ans[0] = ratA[0] * ratB[1];
            ans[1] = ratA[1] * ratB[0];
            convertAndPrint(ans, out);

            a = in.nextInt();
            b = in.nextInt();
        }
        out.close();
    }
}
