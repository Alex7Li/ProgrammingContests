package codeforces;

import java.io.*;
import java.util.Arrays;

//https://codeforces.com/contest/1091/problem/F
public class NewYearAndTheMallardExpedition {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int n = Integer.parseInt(br.readLine());
        //distances array
        long[] d = Arrays.stream(br.readLine().split(" "))
                .mapToLong(x -> Long.parseLong(x)).toArray();
        //terrain array
        char[] t = br.readLine().toCharArray();

        long flyGrass = 0; // doubled: Grass we can fly over
        long flyWater = 0; // doubled: Water we can fly over
        long time = 0;
        long stamina = 0;
        boolean seenWater = false;
        // go through the route as slowly as possible
        for (int i = 0; i < n; i++) {
            switch (t[i]) {
                case 'W': {
                    stamina += d[i];
                    flyWater += d[i] * 2;
                    time += d[i] * 3;
                    seenWater = true;
                    break;
                }
                case 'G': {
                    stamina += d[i];
                    flyGrass = Math.min(flyGrass + d[i] * 2, stamina);
                    time += d[i] * 5;
                    break;
                }
                case 'L': {
                    time += d[i];
                    stamina -= d[i];
                    if (stamina < 0) {//wait patiently
                        if (seenWater) {
                            time -= 3 * stamina;
                        } else {
                            time -= 5 * stamina;
                        }
                        stamina = 0;
                    }
                    {
                        flyGrass = Math.min(flyGrass, stamina);
                        flyWater = stamina - flyGrass;
                    }
                    break;
                }
            }
        }

        flyGrass = Math.min(flyGrass, stamina);
        flyWater = stamina - flyGrass;
        time -= flyGrass * 2;
        time -= flyWater;

        System.out.println(time);

        pw.flush();
        br.close();
        pw.close();
    }
}
