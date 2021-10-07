package codeforces;

import javafx.util.Pair;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

//http://codeforces.com/problemset/problem/994/D
public class OpenCommunication {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<Pair<Integer, Integer>> pair1 = new ArrayList<>();
        ArrayList<Pair<Integer, Integer>> pair2 = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            pair1.add(new Pair<>(Math.min(n1, n2), Math.max(n1, n2)));
        }
        for (int i = 0; i < m; i++) {
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            pair2.add(new Pair<>(Math.min(n1, n2), Math.max(n1, n2)));
        }
        ArrayList<Pair<Pair<Integer, Integer>, Pair<Integer, Integer>>> posPairs = new ArrayList<>();
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j++) {
                for (int k = 1; k < 10; k++) {
                    for (int l = 1; l < 10; l++) {
                        if (i != j && k != l && j == k && i < l) {
                            posPairs.add(new Pair<>(new Pair<>(Math.min(i, j), Math.max(i, j)), new Pair<>(Math.min(k, l), Math.max(k, l))));
                        }
                    }
                }
            }
        }
        Set<Integer> posShared = new HashSet<>();
        ArrayList<Pair<Integer, Integer>> posPair1 = new ArrayList<>();
        ArrayList<Pair<Integer, Integer>> posPair2 = new ArrayList<>();
        for (Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> p : posPairs) {
            for (Pair<Integer, Integer> p1 : pair1) {
                for (Pair<Integer, Integer> p2 : pair2) {
                    if ((p1.equals(p.getKey()) && p2.equals(p.getValue())) ||
                            (p1.equals(p.getValue()) && p2.equals(p.getKey()))) {
                        posShared.add(shared(p));
                        posPair1.add(p1);
                        posPair2.add(p2);
                    }
                }
            }
        }
        if (posShared.size() == 1) {
            System.out.println(posShared.iterator().next());
        } else {
            //does the first person know what the other person has
            for (Pair<Integer, Integer> p : posPair1) {
                //given that the first person has pair p
                Set<Integer> posShared2 = new HashSet<>();
                for (Pair<Integer, Integer> p1 : pair2) {
                    //check each pair to see what numbers are shared.
                    if (shared(new Pair<>(p, p1)) != -1 && !p.equals(p1)) {
                        posShared2.add(shared(new Pair<>(p, p1)));
                    }
                }
                posShared2.retainAll(posShared);
                if (posShared2.size() >= 2) {
                    System.out.println(-1);
                    return;
                }
            }
            //does the second person know what the first person has
            for (Pair<Integer, Integer> p : posPair2) {
                //given that they have pair p
                Set<Integer> posShared2 = new HashSet<>();
                for (Pair<Integer, Integer> p1 : pair1) {
                    if (shared(new Pair<>(p, p1)) != -1 && !p.equals(p1)) {
                        posShared2.add(shared(new Pair<>(p, p1)));
                    }
                }
                posShared2.retainAll(posShared);
                if (posShared2.size() >= 2) {
                    System.out.println(-1);
                    return;
                }
            }
            System.out.println(0);
        }
    }

    //public static boolean isValidPair(Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> p){
    //   if(shared(p)!=-1 && !p.getValue().equals(p.getKey()))
    //}
    public static int shared(Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> p) {
        if (p.getKey().getValue() == p.getValue().getKey()) {
            return p.getKey().getValue();
        } else if (p.getKey().getKey() == p.getValue().getKey()) {
            return p.getKey().getKey();
        } else if (p.getKey().getValue() == p.getValue().getValue()) {
            return p.getKey().getValue();
        } else if (p.getKey().getKey() == p.getValue().getValue()) {
            return p.getKey().getKey();
        } else {
            return -1;
        }
    }
}
