import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//http://codeforces.com/contest/1025/problem/C
public class PlasticineZebra {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] zebraSeq = br.readLine().toCharArray();
        br.close();
        int maxLen = 1;
        int curLen = 0;
        int lastColor = zebraSeq[0];
        for (int i = 1; i < zebraSeq.length * 2; i++) {
            int color = zebraSeq[i % zebraSeq.length];
            if (color != lastColor) {
                curLen++;
            } else {
                maxLen = Math.max(maxLen,curLen);
                curLen = 0;
            }
            lastColor = color;
        }
        System.out.println(maxLen);
    }
}
