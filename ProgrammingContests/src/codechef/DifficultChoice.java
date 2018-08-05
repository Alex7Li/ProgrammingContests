package codechef;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
//this contest had my best performance ever! 17/2410!! (Div 2)
//https://www.codechef.com/COOK94B/problems/CHEFTRVL
public class DifficultChoice {
    private static int[] ages;
    private static boolean[] visited;
    private static ArrayList<ArrayList<Integer>> roads;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < t; tc++) {
            int n = Integer.parseInt(br.readLine());
            visited = new boolean[n];
            roads = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                roads.add(new ArrayList<>());
            }
            for (int i = 0; i < n-1; i++) {
                int[] conCity = Arrays.stream(br.readLine().split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
                roads.get(conCity[0]-1).add(conCity[1]-1);
                roads.get(conCity[1]-1).add(conCity[0]-1);
            }
            ages = Arrays.stream(br.readLine().split(" ")).mapToInt(x->Integer.parseInt(x)).toArray();
            for (int i = 0; i < ages.length; i++) {
                ages[i] = Integer.bitCount(ages[i]);
            }
            System.out.println(count(0,0,0).get(0));
        }
    }

    //returns <count, g0, g1>. count = the answer. g0 = number of cities with age+dist%2=0 from city.
    //g1 = number of cities with age+dist%2=1 from city
    public static ArrayList<Long> count(int city, long g0, long g1){
        visited[city] = true;
        long tCount = 0;
        if(ages[city]%2==0){
            tCount+=g1;
            g0++;
        }else{
            tCount+=g0;
            g1++;
        }
        for (int conCity : roads.get(city)){
            if(!visited[conCity]){
                ArrayList<Long> cCount = count(conCity,g1,g0);
                tCount+=cCount.get(0);
                g0=cCount.get(2);
                g1=cCount.get(1);
            }
        }
        ArrayList<Long> ret = new ArrayList<>();
        ret.add(tCount);
        ret.add(g0);
        ret.add(g1);
        return ret;
    }
}
