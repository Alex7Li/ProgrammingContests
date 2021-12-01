package codeforces;

import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
//http://codeforces.com/problemset/problem/1009/G
public class AllowedLetters {
    final static int ALPH_SIZE = 6;
    static int[] letterNodes;
    static int[] maskNodes;
    static int[][] paths;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] str = br.readLine().toCharArray();
        int s = Integer.parseInt(br.readLine());
        //set up graph for Ford-Fulkerson
        letterNodes = new int[ALPH_SIZE];
        for (char i : str) {
            letterNodes[i - 'a']++;
        }
        int[] masks = new int[str.length];
        Arrays.fill(masks, (1 << ALPH_SIZE) - 1);

        maskNodes = new int[(1 << ALPH_SIZE)];
        maskNodes[(1 << ALPH_SIZE) - 1] = str.length - s;
        for (int i = 0; i < s; i++) {
            String[] inputs = br.readLine().split(" ");
            int index = Integer.parseInt(inputs[0]) - 1;
            masks[index] = 0;
            for (char j : inputs[1].toCharArray()) {
                masks[index] |= 1 << (j - 'a');
            }
            maskNodes[masks[index]]++;
        }

        //find paths
        paths = new int[ALPH_SIZE][1 << ALPH_SIZE];
        boolean pathFound;
        int count = -1;
        do {
            pathFound = findPath(new HashSet<>(),-100);
            count++;
        } while (pathFound);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        if (count != str.length) {
            bw.write("Impossible");
        } else {
            for (int i = 0; i < masks.length; i++) {
                int mask = masks[i];
                for (int j = 0; j < ALPH_SIZE; j++) {
                    if (((1 << j) & mask) != 0) {
                        if (paths[j][mask] == 0) {
                            Set seen = new HashSet();
                            if (unFindPath(seen, j, mask)) {
                                paths[j][mask]++;
                            }
                        }
                        if (paths[j][mask] > 0) {
                            paths[j][mask]--;
                            bw.write((char) (j + 'a'));
                            break;
                        }
                    }
                }
            }
        }
        bw.newLine();
        bw.close();
    }

    // try to gcdSteps until you get to the goal letter
    private static boolean unFindPath(Set<Integer> seen, int goalLetter, int start) {
        seen.add(start);
        if (start < 0) { //go from letterNodes to maskNodes
            start += ALPH_SIZE;
            for (int i = 1; i < (1 << ALPH_SIZE); i++) {
                if (((1 << start) & i) != 0 //there is a path to remove
                        && !seen.contains(i)) { //not seen before
                    boolean found = unFindPath(seen, goalLetter, i);
                    if (found) {
                        paths[start][i]++;
                        return true;
                    }
                }
            }
        } else { //go from maskNodes ...
            if (paths[goalLetter][start] > 0) { // ... to the exit letter
                paths[goalLetter][start]--;
                return true;
            } else { // ... back to letterNodes
                for (int i = -ALPH_SIZE; i < 0; i++) {
                    if ( //there is an edge
                            paths[i+6][start] > 0 && !seen.contains(i)) { //not seen before
                        boolean found = unFindPath(seen, goalLetter,i);
                        if (found) {
                            paths[i + ALPH_SIZE][start]--;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }


    private static boolean findPath(Set<Integer> seen, int start) {
        seen.add(start);
        if (start==-100) { //go from start to letterNodes
            for (int i = -ALPH_SIZE; i < 0; i++) {
                if (letterNodes[i + ALPH_SIZE] > 0) {
                    if (findPath(seen,i)) {
                        letterNodes[i + ALPH_SIZE]--;
                        return true;
                    }
                }
            }
            return false;
        }
        if (start < 0) { //go from letterNodes to maskNodes
            start += ALPH_SIZE;
            int letter = 1 << start;
            for (int i = 1; i < (1 << ALPH_SIZE); i++) {
                if ((i & letter) != 0 //there is an edge
                        && !seen.contains(i)) { //not seen before
                    boolean found = findPath(seen,i);
                    if (found) {
                        paths[start][i]++;
                        return true;
                    }
                }
            }
        } else { //go from maskNodes ...
            if (maskNodes[start] > 0) { // ... to the exit
                maskNodes[start]--;
                return true;
            } else { // ... back to letterNodes
                for (int i = -ALPH_SIZE; i < 0; i++) {
                    if (paths[i + ALPH_SIZE][start] > 0 //can go back
                            && !seen.contains(i)) { //not seen before
                        seen.add(i);
                        boolean found = findPath(seen, start);
                        if (found) {
                            paths[i + ALPH_SIZE][start]--;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
}