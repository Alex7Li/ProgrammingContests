package codeforces;

import java.util.*;

//http://codeforces.com/contest/1020/problem/C
public class Elections {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Queue<Long>> parties = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            parties.add(new PriorityQueue<>());
        }
        for (int i = 0; i < n; i++) {
            int pi = sc.nextInt();
            long ci = sc.nextLong();
            parties.get(pi - 1).add(ci);
        }
        int stVotes = parties.get(0).size();
        parties.remove(0);
        parties.sort((o1, o2) -> o2.size() - o1.size());
        if (m == 1 || stVotes > parties.get(0).size()) {
            System.out.println(0);
            return;
        }
        long bestC = Long.MAX_VALUE;
        for (int goalVotes = parties.get(0).size() + 1; goalVotes > stVotes; goalVotes--) {
            List<Queue<Long>> partiesC = new ArrayList<>();
            for (int i = 0; i < parties.size(); i++) {
                PriorityQueue<Long> queueCopy = new PriorityQueue<>();
                for (Long l : parties.get(i)) {
                    queueCopy.add(l);
                }
                partiesC.add(queueCopy);
            }
            int curVotes = stVotes;
            long curC = 0;
            for (Queue<Long> p : partiesC) {
                while (p.size() >= goalVotes) {
                    curC += p.poll();
                    curVotes++;
                    if (curVotes > goalVotes) {
                        System.out.println(bestC);
                        return;
                    }
                }
            }
            PriorityQueue<Long> leftOver = new PriorityQueue<>();
            for (Queue<Long> p : partiesC) {
                leftOver.addAll(p);
            }
            while (curVotes < goalVotes && !leftOver.isEmpty()) {
                curC += leftOver.poll();
                curVotes++;
            }
            if (curVotes == goalVotes && curC < bestC) {
                bestC = curC;
            }
        }
        System.out.println(bestC);
    }
}
