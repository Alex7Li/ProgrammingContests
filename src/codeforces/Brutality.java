package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

//https://codeforces.com/contest/1107/problem/C
public class Brutality {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int[] params = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int n = params[0];
        int k = params[1];
        int[] a = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        char[] buttons = br.readLine().toCharArray();
        List<Integer> powers = new ArrayList<>();
        long dmg = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0 && buttons[i] != buttons[i - 1]) {
                Collections.sort(powers);
                int st = Math.max(0, powers.size() - k);
                for (int j = st; j < powers.size(); j++) {
                    dmg += powers.get(j);
                }
                powers.clear();
            }
            powers.add(a[i]);
        }
        Collections.sort(powers);
        int st = Math.max(0, powers.size() - k);
        for (int j = st; j < powers.size(); j++) {
            dmg += powers.get(j);
        }
        powers.clear();
        System.out.println(dmg);

        pw.flush();
        br.close();
        pw.close();
    }
}
