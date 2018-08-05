package codeforces;

import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;

//http://codeforces.com/problemset/problem/988/F

public class RainAndUmbrella {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] params = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
        int[] segments = new int[params[1] * 2 + 1];
        segments[0] = 0;
        int[][] umbrellas = new int[params[2] + 1][2];
        umbrellas[params[2]][0] = Integer.MAX_VALUE;
        for (int i = 0; i < segments.length / 2; i++) {
            String[] segArgs = br.readLine().split(" ");
            segments[i * 2 + 1] = Integer.parseInt(segArgs[0]);//start
            segments[i * 2 + 2] = Integer.parseInt(segArgs[1]);//end
        }
        for (int i = 0; i < umbrellas.length - 1; i++) {
            String[] umbArgs = br.readLine().split(" ");
            umbrellas[i][0] = Integer.parseInt(umbArgs[0]);//location
            umbrellas[i][1] = Integer.parseInt(umbArgs[1]);//weight
        }
        Arrays.sort(segments);
        Arrays.sort(umbrellas, Comparator.comparingInt(x -> x[0]));

        if (umbrellas[0][0] > segments[1]) {
            System.out.println(-1);
            return;
        }

        // Key: the weight of some given umbrella. Value: the cost of some given umbrella
        TreeSet<Pair<Integer, Integer>> costs = new TreeSet<>(Comparator.comparingInt(x -> x.getKey()));
        int curUmbInd = 0;
        for (int i = 0; i < segments.length - 1; i++) {
            TreeSet<Pair<Integer, Integer>> newCosts = new TreeSet<>(Comparator.comparingInt(x -> x.getKey()));
            if (i % 2 == 0) { //dry segment
                int bestCost = Integer.MAX_VALUE;//after leaving segment
                int minCost = i == 0 ? 0 : Integer.MAX_VALUE;//before entering segment
                //keep current umbrella
                for (Pair<Integer, Integer> p : costs) {
                    minCost = Math.min(p.getValue(), minCost);
                    int cost = p.getValue() + p.getKey() * (segments[i + 1] - segments[i]);
                    if (cost < bestCost) {
                        bestCost = cost;
                        newCosts.add(new Pair<>(p.getKey(), cost));
                    }
                }
                //pick up new umbrella
                while (umbrellas[curUmbInd][0] <= segments[i + 1]) {
                    int cost = (segments[i + 1] - umbrellas[curUmbInd][0]) * umbrellas[curUmbInd][1] + minCost;
                    Pair<Integer, Integer> eState = new Pair<>(umbrellas[curUmbInd][1], cost);
                    //check if there is an umbrella with weight==eState's weight. TreeSet
                    //does not handle this case very well.
                    if (newCosts.contains(eState)) {
                        int oldCost = newCosts.ceiling(eState).getValue();
                        if (oldCost > cost) {
                            newCosts.remove(eState);//remove the old value with weight==eState's weight (not eState)
                            newCosts.add(eState);//add the new value
                        }
                    } else {
                        newCosts.add(eState);
                    }
                    curUmbInd++;
                }
            } else {//wet segment
                //keep current umbrella, picking up better umbrella if possible
                int stUmbInd = curUmbInd;
                while (umbrellas[curUmbInd][0] <= segments[i + 1]) {
                    curUmbInd++;
                }
                for (Pair<Integer, Integer> p : costs) {
                    int curUmbW = p.getKey();
                    int curCost = p.getValue();
                    for (int j = stUmbInd; j <= curUmbInd; j++) {
                        curCost += (Math.min(segments[i + 1], umbrellas[j][0])
                                - Math.max(umbrellas[j - 1][0], segments[i])) * curUmbW;
                        if (segments[i + 1] >= umbrellas[j][0]) {
                            curUmbW = Math.min(curUmbW, umbrellas[j][1]);
                        }
                    }
                    Pair<Integer, Integer> eState = new Pair<>(curUmbW, curCost);
                    if (newCosts.contains(eState)) {
                        int oldCost = newCosts.ceiling(eState).getValue();
                        if (oldCost > curCost) {
                            newCosts.remove(eState);//remove the old value with weight==eState's weight (not eState)
                            newCosts.add(eState);//add the new value
                        }
                    } else {
                        newCosts.add(eState);
                    }
                }
            }
            costs = newCosts;
        }
        int bestAns = Integer.MAX_VALUE;
        for (Pair<Integer, Integer> p : costs) {
            bestAns = Math.min(bestAns, p.getValue());
        }
        System.out.println(bestAns);
    }
}
