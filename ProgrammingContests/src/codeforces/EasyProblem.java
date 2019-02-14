package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Map;
//https://codeforces.com/problemset/problem/1096/D
public class EasyProblem {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        char[] s = br.readLine().toCharArray();
        int[] w = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        Map<Character, Integer> ind = Map.of('h',1,'a',2,'r',3,'d',4);
        // noSubTo[i] is the lowest cost for the len-i substring of 'hard' to not exist
        long[] noSubTo = new long[5];
        noSubTo[0] = Long.MAX_VALUE;
        for (int i = 0; i < s.length; i++) {
            Integer val = ind.get(s[i]);
            if (val != null) {
                noSubTo[val] = Math.min(noSubTo[val] + w[i], noSubTo[val - 1]);
            }
        }
        System.out.println(noSubTo[4]);
        br.close();
    }
}
