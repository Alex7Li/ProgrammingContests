package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// https://codeforces.com/problemset/problem/1105/E
public class HelpingHiasat {

    private static long[] edgeMask;
    private static int nFriends;
    private static Map<Long, Integer> memos = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] params = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int nEvents = params[0];
        nFriends = params[1];
        edgeMask = new long[nFriends];
        Map<String, Integer> friendNums = new HashMap<>();
        int friendsSeen = 0;

        // set up edge mask such that if the jth friend can't be happy while
        // the kth is, edgemask[j]&(1<<k)=1<<k.
        Set<Integer> groupings = new HashSet<>();
        for (int i = 0; i < nEvents; i++) {
            String[] event = br.readLine().split(" ");
            if (Integer.parseInt(event[0]) == 1) {
                updateEdges(groupings);
            } else {
                int friendInd;
                if (friendNums.containsKey(event[1])) {
                    friendInd = friendNums.get(event[1]);
                } else {
                    friendInd = friendsSeen;
                    friendNums.put(event[1], friendInd);
                    friendsSeen++;
                }
                groupings.add(friendInd);
            }
        }
        updateEdges(groupings);
        br.close();

        for (int i = 0; i < edgeMask.length; i++) {
            edgeMask[i] = (1L << nFriends) - edgeMask[i] - 1;
        }

        System.out.println(maxCliqueSize((1L << nFriends) - 1, 0));

    }

    // add all edges between a set of nodes
    private static void updateEdges(Set<Integer> groupings) {
        for (int j : groupings) {
            for (int k : groupings) {
                edgeMask[j] |= 1L << k;
            }
        }
        groupings.clear();
    }

    /**
     * find the maximum clique that only uses elements from mask.
     * st = location of the lowest 1 in mask (or lower)
     */
    private static int maxCliqueSize(long mask, int st) {
        Integer best = memos.get(mask);
        if (best == null) {
            best = 0;
        } else {
            return best;
        }
        long maskOrig = mask;
        for (int i = st; i < nFriends; i++) {
            if ((mask & (1L << i)) != 0L) {
                mask -= 1L << i;
                int maxWithi = 1 + maxCliqueSize(mask & edgeMask[i], i + 1);
                if (maxWithi >= best) {
                    best = maxWithi;
                }
            }
        }
        memos.put(maskOrig, best);
        return best;
    }
}
