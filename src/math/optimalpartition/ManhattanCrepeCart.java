package math.optimalpartition;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051706/000000000012295c
public class ManhattanCrepeCart {
public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
    int cases = sc.nextInt();
    for (int t = 1; t <= cases; t++) {
        int people = sc.nextInt();
        int size = sc.nextInt();
        TreeMap<Integer, Integer> xInds = new TreeMap<>();
        TreeMap<Integer, Integer> yInds = new TreeMap<>();
        Person[] peps = new Person[people];
        xInds.put(0, 0);
        yInds.put(0, 0);
        for (int j = 0; j < people; j++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            String c = sc.next();
            xInds.put(x, 0);
            yInds.put(y, 0);
            peps[j] = new Person(x, y, c);
            if (c.equals("N") && y <= size) {
                yInds.put(y + 1, 0);
            } else if (c.equals("E") && x <= size) {
                xInds.put(x + 1, 0);
            }
        }
        for (Person p : peps) {
            if (p.d.equals("E")) {
                for (Map.Entry<Integer, Integer> e : xInds.tailMap(xInds.higherKey(p.x)).entrySet()) {
                    xInds.put(e.getKey(), xInds.get(e.getKey()) + 1);
                }
            } else if (p.d.equals("W")) {
                for (Map.Entry<Integer, Integer> e : xInds.headMap(p.x).entrySet()) {
                    xInds.put(e.getKey(), xInds.get(e.getKey()) + 1);
                }
            } else if (p.d.equals("N")) {
                for (Map.Entry<Integer, Integer> e : yInds.tailMap(yInds.higherKey(p.y)).entrySet()) {
                    yInds.put(e.getKey(), yInds.get(e.getKey()) + 1);
                }
            } else if (p.d.equals("S")) {
                for (Map.Entry<Integer, Integer> e : yInds.headMap(p.y).entrySet()) {
                    yInds.put(e.getKey(), yInds.get(e.getKey()) + 1);
                }
            }
        }
        int bestx = -1;
        int besty = -1;
        int most = 0;
        for (Map.Entry<Integer, Integer> ex : xInds.entrySet()) {
            for (Map.Entry<Integer, Integer> ey : yInds.entrySet()) {
                if (ex.getValue() + ey.getValue() > most) {
                    most = ex.getValue() + ey.getValue();
                    bestx = ex.getKey();
                    besty = ey.getKey();
                }
            }
        }
        System.out.println("Case #" + t + ": " + bestx + " " + besty);
    }
}

private static class Person {
    int x;
    int y;
    String d;
    
    Person(int x, int y, String dir) {
        this.x = x;
        this.y = y;
        d = dir;
    }
    
}

/*
 * Bag/Multiset class for integers
 */
private class MultiSet {
    Map<Integer, Integer> mSet = new HashMap<>();
    int size = 0;
    
    /*
     * Adds a single element to the multiset
     */
    void add(int element) {
        mSet.put(element, mSet.getOrDefault(element, 0) + 1);
        size++;
    }
    
    /*
     * Removes a single element from the multiset
     */
    void remove(int element) {
        int curCount = mSet.get(element);
        if (curCount <= 0) {
            throw new RuntimeException();
        } else if (curCount == 1) {
            mSet.remove(element);
        } else {
            mSet.put(element, curCount - 1);
        }
        size--;
    }
    
    /**
     * return any int corresponding to a given key
     */
    Integer getAny() {
        return mSet.keySet().iterator().next();
    }
    
}
}
