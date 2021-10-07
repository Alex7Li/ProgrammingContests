package implementation.simple;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//https://codeforces.com/contest/1158/problem/A
public class PartyAndSweets {
public static void main(String[] xx) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] args = br.readLine().split(" ");
    int n = Integer.parseInt(args[0]);
    int m = Integer.parseInt(args[1]);
    int[] boys = Arrays.stream(br.readLine().split(" "))
            .mapToInt(x -> Integer.parseInt(x)).toArray();
    int[] girls = Arrays.stream(br.readLine().split(" "))
            .mapToInt(x -> Integer.parseInt(x)).toArray();
    Arrays.sort(boys);
    Arrays.sort(girls);
    long candies = 0;
    if (boys[boys.length - 1] > girls[0]) {
        System.out.println(-1);
        return;
    }
    for (int i = 1; i < girls.length; i++) {
        candies += girls[i] - boys[boys.length - 1];
    }
    if(girls[0]!=boys[boys.length-1]){
        candies += girls[0] - boys[boys.length-2];
    }
    for (int i = boys.length - 1; i >= 0; i--) {
        candies += (long) (boys[i]) * girls.length;
    }
    System.out.println(candies);
    br.close();
}
}
