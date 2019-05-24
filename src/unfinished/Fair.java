package unfinished;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
//http://codeforces.com/problemset/problem/986/A
public class Fair {
    private static int k;
    private static int s;
    public static void main(String[] a) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] args = Arrays.stream(br.readLine().split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
        int nTowns = args[0];
        int nRoads = args[1];
        k = args[2];
        s = args[3];
        Town[] towns = new Town[nTowns];
        int[] goodTypes =  Arrays.stream(br.readLine().split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
        for (int i = 0; i < nTowns; i++) {
            towns[i] = new Town(goodTypes[i]-1);
        }
        for (int i = 0; i < nRoads; i++) {
            int[] roadDesc = Arrays.stream(br.readLine().split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
            towns[roadDesc[0]-1].addRoad(towns[roadDesc[1]-1]);
            towns[roadDesc[1]-1].addRoad(towns[roadDesc[0]-1]);
        }
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < nTowns; i++) {
            pw.print(towns[i].cost()+" ");
        }
        pw.println();
        pw.flush();
    }
    private static Set<Town> seen  = new HashSet<Town>();
    private static class Town{
        int[] distToGood = new int[k];
        int goodType;
        ArrayList<Town> connected = new ArrayList<>();
        public Town(int goodType){
            this.goodType = goodType;
            Arrays.fill(distToGood,-1);
        }
        public void addRoad(Town c){
            connected.add(c);
        }
        public int cost() {
            for (int i = 0; i < distToGood.length; i++) {
                if(distToGood[i]==-1) {
                    seen.clear();
                    getDistToGood(i);
                }
            }
            Arrays.sort(distToGood);
            System.out.println(Arrays.toString(distToGood));
            int cost = 0;
            for (int i = 0; i < s; i++) {
                cost+= distToGood[i];
            }
            return cost;
        }
        public void getDistToGood(int i){
           seen.add(this);
           if(this.goodType==i){
               this.distToGood[i] = 0;
           } else {
               this.distToGood[i] = Integer.MAX_VALUE - 1;
               for (Town t:connected) {
                   if(!seen.contains(t)){
                       if(t.distToGood[i]==-1){
                           t.getDistToGood(i);
                       }
                       this.distToGood[i] = Math.min(this.distToGood[i], t.distToGood[i]+1);
                   }
               }

           }
        }
    }
}
