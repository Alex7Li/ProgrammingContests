package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//https://codeforces.com/gym/102032
public class Innoforest {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inParams = br.readLine().split(" ");
        int n = Integer.parseInt(inParams[0]);
        int m = Integer.parseInt(inParams[1]);
        int[][] forest = new int[n][m];
        for (int i = 0; i < n; i++) {
            forest[i] = Arrays.stream(br.readLine().split(" ")).
                    mapToInt(Integer::parseInt).toArray();
        }
        for (int i = 0; i < n; i++) {
            int[] treeLine = Arrays.stream(br.readLine().split(" ")).
                    mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < m; j++) {
                forest[i][j] = treeLine[j] - forest[i][j];
            }
        }
        int min = Integer.MAX_VALUE;
        int minX = -1;
        int minY = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (min > forest[i][j]) {
                    min = forest[i][j];
                    minX = i;
                    minY = j;
                }
            }
        }
        if (min < 0) {
            System.out.println(-1);
            return;
        }
        StringBuilder sb = new StringBuilder();
        int count = 0;
        int[] rowWat = new int[n];
        for (int i = 0; i < n; i++) {
            rowWat[i] = forest[i][minY] - min;
            if (rowWat[i] != 0) {
                count++;
                sb.append("R " + (i + 1) + " " + (forest[i][minY] - min));
                sb.append(System.lineSeparator());
            }
        }
        int[] colWat = new int[m];
        for (int i = 0; i < m; i++) {
            colWat[i] = forest[minX][i];
            if (colWat[i] != 0) {
                count++;
                sb.append("NewYearAndTheSphereTransmission " + (i + 1) + " " + (forest[minX][i]));
                sb.append(System.lineSeparator());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (colWat[j] + rowWat[i] != forest[i][j]) {
                    System.out.println(-1);
                    return;
                }
            }
        }
        System.out.println(count);
        System.out.println(sb.toString());
    }
}
