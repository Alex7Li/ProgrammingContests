package tools;

import java.util.ArrayDeque;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class GraphTheory {
    /*
     * @return a euclidean path from start, or null if none exist
     * The map goes from integer node labels to a set of node labels
     */
    private static Queue<Integer> getEuclideanPath(Map<Integer, Set<Integer>> edges, int start) {
        ArrayDeque<Integer> curPath = new ArrayDeque<>(); // a stack
        Queue<Integer> finalPath = new ArrayDeque<>(); // a queue!

        // count total edges.
        int nEdges = 0;
        for (Map.Entry<Integer, Set<Integer>> node : edges.entrySet()) {
            nEdges += node.getValue().size();
        }

        int last = start;
        loop:
        while (nEdges != 0) {
            while (edges.get(last).size() > 0) {
                curPath.push(last);
                int next = edges.get(last).iterator().next();
                edges.get(last).remove(next);
                edges.get(next).remove(last);
                nEdges -= 2;
                last = next;
            }
            while (edges.get(last).size() == 0) {
                if (curPath.size() == 0) {
                    break loop;
                }
                finalPath.add(last);
                last = curPath.pop();
            }
        }
        finalPath.add(last);
        if (nEdges == 0) {
            return finalPath;
        } else {
            return null;
        }
    }
}
