package graphtheory.stronglyconnectedcomponents;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// https://naq15.kattis.com/problems/cantinaofbabel
public class CantinaOfBabel {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Node> languages = new HashMap<>(n);
        String[][] input = new String[n][];
        for (int i = 0; i < n; i++) {
            input[i] = br.readLine().split(" ");
            if (!languages.containsKey(input[i][1])) {
                languages.put(input[i][1], new Node());
                languages.get(input[i][1]).language = input[i][1];
            }
            languages.get(input[i][1]).speakers++;
        }
        br.close();
        for (int i = 0; i < n; i++) {
            for (int j = 2; j < input[i].length; j++) {
                if (languages.containsKey(input[i][j])) {
                    languages.get(input[i][1]).edges.add(languages.get(input[i][j]));
                }
            }
        }
        getStronglyConnectedComponents(languages.values());
        int max = 0;
        for (Collection<Node> comp : scc) {
            int weight = 0;
            for (Node language : comp) {
                weight += language.speakers;
            }
            max = Math.max(max, weight);
        }
        System.out.println(n - max);
    }


    // the strongly connected components
    private static Collection<Collection<Node>> scc;

    private static void getStronglyConnectedComponents(Collection<Node> nodes) {
        scc = new ArrayList<>();
        for (Node node : nodes) {
            if (node.seenTime == 0) {
                node.findStronglyConnectedComponents();
            }
        }
    }


    private static class Node {
        Collection<Node> edges = new HashSet<>();
        int speakers = 0;
        String language;
        // the time this node was seen during the dfs for Tarjan. 0 means unseen.
        private int seenTime;
        // the smallest seen time reachable from this node.
        private int minSeen;
        // if this node is current on the connected components stack
        private boolean onStack = false;
        // the current index, used to update seenTime as we find new components
        private static int curIndex = 0;
        // stack containing nodes for Tarjan's algorithm.
        private static ArrayDeque<Node> stack = new ArrayDeque<Node>();

        // use Tarjan's algorithm to find all strongly connected components,
        private void findStronglyConnectedComponents() {
            curIndex++;
            seenTime = curIndex;
            minSeen = curIndex;
            stack.push(this);
            onStack = true;
            for (Node nxt : edges) {
                if (nxt.seenTime == 0) {
                    // search through nxt. When this method returns, the nodes added to the stack will be exactly
                    // those reachable through nxt that lead back to a node earlier on in the stack.
                    nxt.findStronglyConnectedComponents();
                    minSeen = Math.min(minSeen, nxt.minSeen);
                } else if (nxt.onStack) {
                    // this node has been seen and is in a loop that comes back to this node
                    // This line is supposed to use nxt.seenTime and not nxt.component.
                    minSeen = Math.min(minSeen, nxt.seenTime);
                }
            }
            if (seenTime == minSeen) {
                Collection<Node> component = new ArrayList<>();
                Node nxt;
                do {
                    nxt = stack.pop();
                    nxt.onStack = false;
                    component.add(nxt);
                } while (nxt != this);
                scc.add(component);
            }
        }
    }
}
