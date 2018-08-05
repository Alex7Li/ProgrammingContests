package codeforces;

import java.io.*;

public class _Marathon_ColoredPathGenerator {
    public static void main(String[] args) throws IOException {
        int N = 1000000;
        int S = 100000;
        int C = 10;
        int H = 10;
        int U = 10;
        PrintWriter pw = new PrintWriter(new FileWriter("Marathon_ColoredPathInput.txt"));
        pw.write(N + " " + S + " " + C + " " + H + " " + U);
        pw.println();
        for (int i = 0; i < N; i++) {
            pw.write('A' + (int)(Math.random()*C));
        }
        pw.println();
        for (int i = 0; i < S+H; i++) {
            pw.write('A' + (int)(Math.random()*C));
        }
        pw.println();
        pw.flush();
        pw.close();
    }
}
