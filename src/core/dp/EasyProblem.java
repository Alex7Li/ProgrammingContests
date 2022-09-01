package core.dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class EasyProblem {
public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    Integer.parseInt(br.readLine());
    char[] s = br.readLine().toCharArray();
    int[] w = Arrays.stream(br.readLine().split(" "))
            .mapToInt(x -> Integer.parseInt(x)).toArray();
    // noSubTo[2] for example is the lowest cost for a substring 'har'
    // (with len 2+1) to not exist
    long[] noSubTo = {0, 0, 0, 0};
    
    for (int i = 0; i < s.length; i++) {
        switch (s[i]) {
            case 'h':
                noSubTo[0] += w[i];
                break;
            case 'a':
                noSubTo[1] = Math.min(noSubTo[1] + w[i], noSubTo[0]);
                break;
            case 'r':
                noSubTo[2] = Math.min(noSubTo[2] + w[i], noSubTo[1]);
                break;
            case 'd':
                noSubTo[3] = Math.min(noSubTo[3] + w[i], noSubTo[2]);
                break;
            default:
                break;
        }
    }
    System.out.println(noSubTo[3]);
    br.close();
}
}