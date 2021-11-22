package misc.constructive;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

//https://codejam.withgoogle.com/2018/challenges/0000000000007883/dashboard
public class WaffleChoppers {
public static void main(String[] args) throws NumberFormatException, IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int cases = Integer.parseInt(br.readLine());
    for (int i = 1; i <= cases; i++) {
        int[] params = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
        boolean[][] array = new boolean[params[0]][params[1]];
        for (int j = 0; j < array.length; j++) {
            char[] line = br.readLine().toCharArray();
            for (int j2 = 0; j2 < line.length; j2++) {
                array[j][j2] = line[j2] == '@';
            }
        }
        boolean possible = solve(params[0], params[1], params[2], params[3], array);
        System.out.print("Case #" + i + ": ");
        if (possible) {
            System.out.println("POSSIBLE");
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }
}

private static boolean solve(int r, int c, int h, int v, boolean[][] array) {
    int count = 0;
    int[] countRow = new int[r];
    int[] countCol = new int[c];
    for (int i = 0; i < array.length; i++) {
        for (int j = 0; j < array[0].length; j++) {
            if (array[i][j]) {
                count++;
                countRow[i]++;
                countCol[j]++;
            }
        }
    }
    if (count % ((h + 1) * (v + 1)) != 0) {
        return false;
    }
    //get horizontal
    int wanted = count / (h + 1);
    ArrayList<Integer> hBounds = new ArrayList<Integer>();
    int curChips = 0;
    for (int i = 0; i < r; i++) {
        curChips += countRow[i];
        if (curChips > wanted) {
            return false;
        } else if (curChips == wanted) {
            curChips = 0;
            hBounds.add(i + 1);
            if (hBounds.size() == h) {
                break;
            }
        }
    }
    wanted = count / (v + 1);
    hBounds.add(r);
    ArrayList<Integer> vBounds = new ArrayList<Integer>();
    curChips = 0;
    for (int i = 0; i < c; i++) {
        curChips += countCol[i];
        if (curChips > wanted) {
            return false;
        } else if (curChips == wanted) {
            curChips = 0;
            vBounds.add(i + 1);
            if (vBounds.size() == v) {
                break;
            }
        }
    }
    
    vBounds.add(c);
    int top = 0;
    int left = 0;
    for (int hb : hBounds) {
        for (int vb : vBounds) {
            int counter = 0;
            int goal = count / ((h + 1) * (v + 1));
            for (int i = top; i < hb; i++) {
                for (int j = left; j < vb; j++) {
                    if (array[i][j]) {
                        counter++;
                    }
                }
            }
            if (counter != goal) {
                return false;
            }
            left = vb;
        }
        top = hb;
        left = 0;
    }
    return true;
}
}
