package codeforces;

import java.io.*;
import java.util.ArrayList;
//codeforces.com/contest/981/problem/PlasticineZebra
public class UsefulDecomposition {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<ArrayList<Integer>> path = new ArrayList<>();
        for (int i = 0; i < n+1; i++) {
            path.add(new ArrayList<>());
        }
        int[] connected = new int[n + 1];
        for (int i = 0; i < n - 1; i++) {
            String[] in = br.readLine().split(" ");
            int a = Integer.parseInt(in[0]);
            int b = Integer.parseInt(in[1]);
            path.get(b).add(a);
            path.get(a).add(b);
            connected[a]++;
            connected[b]++;
        }
        int start = 1;
        possibleCheck:
        for (int i = 1; i < connected.length; i++) {
            if (connected[i] >= 3) {
                start = i;
                for (int j = i + 1; j < connected.length; j++) {
                    if (connected[j] >= 3) {
                        System.out.println("No");
                        return;
                    }
                }
                break possibleCheck;

            }
        }
        System.out.println("Yes");
        boolean[] visited = new boolean[n+1];
        visited[start] = true;
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(path.get(start).size()+System.lineSeparator());
        for (int edge : path.get(start)){
            bw.write(start + " ");
            //dfs from edge
            while(path.get(edge).size()!=1){
                visited[edge] = true;
                for (int e2:path.get(edge)){
                    if(!visited[e2]){
                        edge = e2;
                    }
                }
            }
            bw.write(edge + System.lineSeparator());
        }
        bw.flush();
    }
}
