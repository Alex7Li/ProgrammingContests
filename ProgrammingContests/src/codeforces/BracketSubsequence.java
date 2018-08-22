package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//http://codeforces.com/contest/1023/problem/C
public class BracketSubsequence {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] params = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
        int sOpen = params[1] / 2;
        int sClose = (params[0]-params[1]) / 2;
        char[] brackSeq = br.readLine().toCharArray();
        br.close();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < brackSeq.length; i++) {
            if (brackSeq[i] == '(' && sOpen > 0) {
                sb.append("(");
                sOpen--;
            }
            if(brackSeq[i] ==')'){
                if(sClose==0) {
                    sb.append(")");
                }else{
                    sClose--;
                }
            }
        }
        System.out.println(sb);
    }
}
