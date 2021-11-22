package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
//http://codeforces.com/problemset/problem/1025/A
public class DoggoRecoloring {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        char[] colors = br.readLine().toCharArray();
        Map<Character, Integer> m = new HashMap<Character, Integer>();
        for (char c : colors) {
            m.put(c, m.getOrDefault(c, 0) + 1);
        }
        boolean possible = false;
        if (colors.length == 1) {
            possible = true;
        }
        for (int v : m.values()) {
            if (v > 1) {
                possible = true;
            }
        }
        System.out.println(possible ? "Yes" : "No");
    }

}
