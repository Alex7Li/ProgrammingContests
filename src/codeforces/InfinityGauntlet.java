package codeforces;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/987/A
public class InfinityGauntlet {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        Map<String,String> names = new HashMap<>();
        names.put("purple","Power");
        names.put("green","Time");
        names.put("blue","Space");
        names.put("orange","Soul");
        names.put("red","Reality");
        names.put("yellow","Mind");
        for (int i = 0; i < n; i++) {
            names.remove(sc.nextLine());
        }
        System.out.println(names.size());
        for(String name:names.values()){
            System.out.println(name);
        }
        sc.close();
    }
}
