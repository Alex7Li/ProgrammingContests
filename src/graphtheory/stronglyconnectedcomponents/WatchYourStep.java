package graphtheory.stronglyconnectedcomponents;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//https://ecna18.kattis.com/problems/watchyourstep
public class WatchYourStep {
    private static boolean[][] g;
    private static boolean[] seen;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        g = new boolean[n][n];

        int count = 0;
        for (int i = 0; i < n; i++) {
            String[] edges = br.readLine().split(" ");
            for (int j = 0; j < edges.length; j++) {
                if (edges[j].equals("1")) {
                    g[i][j] = true;
                    count--;
                }
            }
        }
        count += stronglyConnectedComponents();
        System.out.println(count);
    }

    /**
     * Count the maximum number of total edges that can be connected in the graph g,
     * given that the strongly connected components must not change
     **/
    static int stronglyConnectedComponents() {
        int n = g.length;
        seen = new boolean[n];
        Stack<Integer> postOrder = new Stack<>();

        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                dfs(i, postOrder);
            }
        }

        seen = new boolean[n];
        //  nodes reachable from each component
        List<Set<Integer>> reachableComponents = new ArrayList<>();
        // the component that each node is inside of.
        int[] componentOf = new int[n];
        Arrays.fill(componentOf, -1);
        int count = 0;
        while (!postOrder.isEmpty()) {
            int nodeInd = postOrder.pop();
            if (!seen[nodeInd]) {
                Set<Integer> connected = new TreeSet<>((x, y) -> y - x);
                List<Integer> component = reachable(nodeInd, componentOf, connected);
                Set<Integer> reachable = new HashSet<>();
                // connect this component to it's connected scc's.
                for (int i : connected) {
                    // if any element of the components has already been counted,
                    // we must have already counted everything. Hence, we don't need
                    // to waste time calling addAll.
                    if (!reachable.contains(reachableComponents.get(i).iterator().next())) {
                        reachable.addAll(reachableComponents.get(i));
                    }
                }
                reachableComponents.add(reachable);
                count += reachable.size() * component.size();
                // connect this component to itself
                count += (component.size() * (component.size() - 1));
                for (int i : component) {
                    componentOf[i] = reachableComponents.size() - 1;
                    reachable.add(i);
                }
            }
        }
        return count;
    }

    private static void dfs(int index, Stack<Integer> postOrder) {
        seen[index] = true;
        for (int j = 0; j < g.length; j++) {
            if (!seen[j] && g[index][j]) {
                dfs(j, postOrder);
            }
        }
        postOrder.push(index);
    }

    private static List<Integer> reachable(int nodeInd, int[] componentOf, Set<Integer> connected) {
        List<Integer> canReach = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(nodeInd);
        seen[nodeInd] = true;
        while (!queue.isEmpty()) {
            int nxt = queue.remove();
            for (int i = 0; i < g.length; i++) {
                if (g[i][nxt]) {
                    if (!seen[i]) {
                        seen[i] = true;
                        queue.add(i);
                    }
                    if (componentOf[i] != -1) {
                        connected.add(componentOf[i]);
                    }
                }
            }
            canReach.add(nxt);
        }
        return canReach;
    }

}
