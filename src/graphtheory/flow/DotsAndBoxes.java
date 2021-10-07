package graphtheory.flow;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// https://naq16.kattis.com/problems/dotsboxes
public class DotsAndBoxes {

public static void main(String[] xx) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine()) - 1;
    int source = n * n;
    int sink = n * n + 1;
    FlowNetwork fn = new FlowNetwork(n * n + 2, source, sink);
    int edgeCount = 2 * n * (n + 1);
    char[] nl = br.readLine().toCharArray();
    for (char c : nl) {
        if (c == '.') {
            edgeCount--;
        }
    }
    for (int i = 0; i < n; i++) {
        nl = br.readLine().toCharArray();
        if (nl[0] == '.') {
            edgeCount--;
        }
        if (nl[2 * n] == '.') {
            edgeCount--;
        }
        for (int j = 1; j < n; j++) {
            if (nl[2 * j] == '.') {
                if ((i + j) % 2 == 1) {
                    fn.addEdge(i + n * j, i + n * (j - 1), 1);
                } else {
                    fn.addEdge(i + n * (j - 1), i + n * j, 1);
                }
                edgeCount--;
            }
        }
        nl = br.readLine().toCharArray();
        for (int j = 0; j < n; j++) {
            if (nl[2 * j + 1] == '.') {
                if (n != i + 1) {
                    if ((i + j) % 2 == 1) {
                        fn.addEdge(i + n * j, i + 1 + n * j, 1);
                    } else {
                        fn.addEdge(i + 1 + n * j, i + n * j, 1);
                    }
                }
                edgeCount--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 1) {
                fn.addEdge(source, i + n * j, 1);
            } else {
                fn.addEdge(i + n * j, sink, 1);
            }
        }
    }
    int matchingSize = fn.findFlow();
    int unmatched = n * n - 2 * matchingSize;
    int empty = unmatched + matchingSize;
    System.out.println(2 * n * (n + 1) - edgeCount - empty + 1);
    br.close();
}

private static class FlowNetwork {
    
    private int n; // number of nodes
    private int source; // index of source
    private int sink; // index of sink
    // next[i] indicates the next unused edge index in the adjacency list for node i. This is part
    // of the Shimon Even and Alon Itai optimization of pruning deads ends as part of the DFS phase.
    private int[] next;
    // For a certain vertex at this stage of dinics, we compute it's level to be 1+the distance
    // from the source to this vertex.
    private int[] level;
    
    private List<Edge> edges; // all the edges
    private List<Integer>[] adjList; // adjList[i] has all of the edges from the ith node.
    
    /**
     * Construct a new FlowNetwork to find maximum flow in a graph. After calling, this,
     * you must add Edges by calling addEdge() until the graph is constructed.
     *
     * @param numberOfNodes The total number of nodes in the network
     * @param source        The index of the node to represent the source
     * @param sink          The index of the node to represent the sink
     **/
    FlowNetwork(int numberOfNodes, int source, int sink) {
        n = numberOfNodes;
        next = new int[n];
        this.source = source;
        this.sink = sink;
        adjList = new List[n];
        edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList[i] = new ArrayList<>();
        }
    }
    
    private int findFlow() {
        final int INF = Integer.MAX_VALUE / 2;
        int tFlow = 0;
        while (levelGraph()) {
            Arrays.fill(next, 0);
            // augment the path until there is no more flow to be gained along the shortest paths
            for (int f = augmentPath(source, INF); f != 0; f = augmentPath(source, INF)) {
                tFlow += f;
            }
        }
        return tFlow;
    }
    
    private int augmentPath(int st, int flow) {
        if (st == sink) {
            return flow;
        }
        for (; next[st] < adjList[st].size(); next[st]++) {
            int eInd = adjList[st].get(next[st]);
            Edge e = edges.get(eInd);
            if (level[st] + 1 == level[e.to] && e.cap - e.flow > 0) {
                int pathFlow = augmentPath(e.to, Math.min(flow, e.cap - e.flow));
                if (pathFlow > 0) {
                    e.flow += pathFlow;
                    edges.get(eInd ^ 1).flow -= pathFlow; // by the construction, edges[eInd^1] is the reverse edge
                    return pathFlow;
                }
            }
        }
        return 0;
    }
    
    /*
     * do a bfs through the network to create a level graph of nodes. level[i] stored the distance from the source,
     * using only edges which can have flow added to them.
     * Return true iff there is a path from the source to the sink.
     */
    private boolean levelGraph() {
        level = new int[n];
        Queue<Integer> Q = new ArrayDeque<>();
        Q.add(source);
        level[source] = 1;
        while (!Q.isEmpty() && level[sink] == 0) {
            int cur = Q.poll();
            for (int nxtInd : adjList[cur]) {
                Edge e = edges.get(nxtInd);
                if (level[e.to] == 0 && e.cap > e.flow) {
                    level[e.to] = level[cur] + 1;
                    Q.add(e.to);
                }
            }
        }
        return level[sink] != 0;
    }
    
    private class Edge {
        int to;
        int cap;
        int flow;
        
        Edge(int toNodeInd, int capacity) {
            to = toNodeInd;
            cap = capacity;
        }
    }
    
    void addEdge(int from, int to, int capacity) {
        Edge e1 = new Edge(to, capacity);
        Edge e2 = new Edge(from, 0);
        adjList[from].add(edges.size());
        edges.add(e1);
        adjList[to].add(edges.size());
        edges.add(e2);
    }
}
}
