package unfinished;

import java.util.*;


// https://open.kattis.com/problems/listgame2
public class ListGame {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long l = sc.nextLong();
        sc.close();
        List<Pair> factorCounts = new ArrayList<>();
        int ind = 0;
        for (long i = 2; i * i <= l; i++) {
            int count = 0;
            while (i % l == 0) {
                count++;
                l /= i;
            }
            if (count > 0) {
                factorCounts.add(new Pair(count, ind++));
            }
        }
        if (l != 1) {
            factorCounts.add(new Pair(1, ind++));
        }
        System.out.println(solve(factorCounts));
    }

    private static int solve(List<Pair> sig) {
        int freePrimeFactors = 0;
        for (int i = 0; i < sig.size(); i++) {
            freePrimeFactors += sig.get(i).val;
        }

        Collections.sort(sig);
        int size = 1;
        boolean found = false;
        Map<Integer, Integer> toRemove = new HashMap<>();
        while (!found) {
            if (size > freePrimeFactors) {
                return 0;
            }
            // greedily pick the best one
            if (genPerm(sig, toRemove, size)) {
                found = true;
                for (Pair p : sig) {
                    p.val -= toRemove.getOrDefault(p.index, 0);
                    assert p.val >= 0;
                }
            } else {
                assert toRemove.size() == 0;
                size++;
            }
        }
        System.out.println(sig);
        return solve(sig) + 1;
    }


    private static void addToBag(int element, Map<Integer, Integer> bag) {
        bag.put(element, bag.getOrDefault(element, 0) + 1);
    }


    private static void removeFromBag(int element, Map<Integer, Integer> bag) {
        bag.put(element, bag.get(element) - 1);
    }


    // try to generate a permutation that works and store it in indexes.
    // Returns true on success.
    private static boolean genPerm(List<Pair> sig, Map<Integer, Integer> indexes, int size) {
        Collections.sort(sig);
        if (size == 0) {
            addToBag(0, indexes);
            int last = 0;
            out1:
            for (int i = 0; i < sig.size() - 1; i = last) {
                if (isPossible(sig, indexes)) {
                    return true;
                }
                for (int j = i + 1; j <= sig.size(); j++) {
                    if (j == sig.size()) {
                        break out1;
                    } else if (sig.get(j).val - indexes.getOrDefault(sig.get(j).index, 0) > 0) {
                        addToBag(sig.get(i).index, indexes);
                        removeFromBag(sig.get(j).index, indexes);
                        last = j;
                        break;
                    }
                }
            }
            if (isPossible(sig, indexes)) {
                return true;
            }
            removeFromBag(sig.get(last).index, indexes);
        } else {
            addToBag(0, indexes);
            int last = 0;
            out2:
            for (int i = 0; i < sig.size() - 1; i = last) {
                if (genPerm(sig, indexes, size - 1)) {
                    return true;
                }
                for (int j = i + 1; j <= sig.size(); j++) {
                    if (j == sig.size()) {
                        break out2;
                    } else if (sig.get(j).val - indexes.getOrDefault(sig.get(j).index, 0) > 0) {
                        addToBag(sig.get(i).index, indexes);
                        removeFromBag(sig.get(j).index, indexes);
                        last = j;
                        break;
                    }
                }
            }
            if (genPerm(sig, indexes, size - 1)) {
                return true;
            }
            removeFromBag(sig.get(last).index, indexes);
        }
        // found nothing
        return false;
    }

    private static boolean isPossible(List<Pair> sig, Map<Integer, Integer> indexes) {
        for (Pair p : sig) {
            if (indexes.getOrDefault(p.index, 0) > p.val) {
                return false;
            }
        }
        return true;
    }

    private static class Pair implements Comparable<Pair> {
        int index;
        int val;

        public Pair(int index, int value) {
            this.index = index;
            this.val = value;
        }

        @Override
        public int compareTo(Pair o) {
            return o.val - val;
        }
    }
}
