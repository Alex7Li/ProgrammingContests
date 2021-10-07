package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//https://codeforces.com/contest/1163/problem/B2
public class CatParty {
public static void main(String[] xx) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    int[] a = Arrays.stream(br.readLine().split(" "))
            .mapToInt(x -> Integer.parseInt(x)).toArray();
    int maxStreak = 1;
    int max = 0;
    Map<Integer, Integer> counts = new HashMap<>();
    Set<Integer> correctSize = new HashSet<>();
    Set<Integer> maxes = new HashSet<>();
    for (int i = 0; i < a.length; i++) {
        int value = a[i];
        int num;
        if (maxes.contains(value)) {
            maxes.remove(value);
            num = max + 1;
        } else if (correctSize.contains(value)) {
            correctSize.remove(value);
            num = max;
        } else {
            num = counts.getOrDefault(value, 0) + 1;
            counts.remove(value);
        }
        if (num > max) {
            for (Integer integer : correctSize) {
                counts.put(integer, max - 1);
            }
            correctSize = new HashSet<>(maxes);
            maxes = new HashSet<>();
            maxes.add(value);
            max = num;
        } else if (num == max) {
            maxes.add(value);
        } else if (num == max - 1) {
            correctSize.add(value);
        } else {
            counts.put(value, num);
        }
        if (counts.isEmpty() && maxes.size() == 1) {
            maxStreak = i+1;
        } else if (counts.size() + correctSize.size() == 1) {
            if ((counts.size() > 0 && counts.values().iterator().next() == 1) ||
                    (correctSize.size() > 0 && max == 2)) {
                maxStreak = i+1;
            }
        } else if(max == 1){
            maxStreak = i+1;
        }
    }
    System.out.println(maxStreak);
    br.close();
}
}
