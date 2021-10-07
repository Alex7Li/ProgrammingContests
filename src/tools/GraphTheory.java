package tools;

import java.util.*;

/*
 * A collection of algorithms relating to graph theory. There is no standard throughout this for
 * the underlying storage used for the graph. You may have to adapt the algorithm to your situation - or, more
 * likely, adapt your situation to the algorithm. A big part of the reason for having no standard is that using a
 * specific data storage lends itself much more nicely to a problem.
 *
 * METHOD LIST:
 * Queue<Integer> getEuclideanPath(Map<Integer, Set<Integer>> edges, int start)
 * Collection<Collection<Node>> getStronglyConnectedComponents(Collection<Node> nodes)
 * FlowNetwork (Class for Dinic's Algorithm)
 */
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

//---------------------------------TARJAN'S ALGORITHM FOR STRONGLY CONNECTED COMPONENTS-----------------------------
/*
 * Returns a collection of collections (list of lists in implementation) where each subcollection contains all
 * nodes of a strongly connected component. Of course, each component and each node appear exactly once in
 * the returned collection.
 * Time complexity: O(V+E) (takes one dfs)
 */
private static Collection<Collection<Node>> getStronglyConnectedComponents(Collection<Node> nodes) {
    scc = new ArrayList<>();
    for (Node node : nodes) {
        if (node.seenTime == 0) {
            node.findStronglyConnectedComponents();
        }
    }
    return scc;
}

// the strongly connected components
private static Collection<Collection<Node>> scc;

private static class Node {
    Collection<Node> edges = new HashSet<>();
    
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

//---------------------------------FIND ALL BRIDGES-----------------------------
/*
 * Find all bridges in a connected component of a graph. To use this method, choose any node n in the graph and call
 * n.findBridges(null). Each bridge edge will be in the bridges set for each node connected it.
 * Procedure: For each node, mark when it's seen. Then, for each edge, search every unexplored part of that
 * edge and return the lowest timeSeen. The edge is a bridge exactly when that time is leq to the time that
 * we started searching that edge,
 */
private static class Node2 {
    Node2[] edges;
    int timeSeen = 0;
    Set<Node2> bridges = new HashSet<>();
    static int totalSeen = 0;
    
    private int findBridges(Node2 parent) {
        totalSeen++;
        timeSeen = totalSeen;
        int minSeen = timeSeen;
        for (Node2 e : edges) {
            int minSeenThisEdge = e.timeSeen;
            if (e.timeSeen == 0) {
                int curSeen = totalSeen;
                minSeenThisEdge = e.findBridges(this);
                if (minSeenThisEdge > curSeen) {
                    bridges.add(e);
                    e.bridges.add(this);
                }
            }
            if (e != parent) {
                minSeen = Math.min(minSeen, minSeenThisEdge);
            }
        }
        return minSeen;
    }
}

//---------------------------------------DINIC'S ALGORITHM--------------------------------------------
// Dinic's algorithm is an algorithm to find the maximum flow in a flow network in O(V^2*E) time. For
// a bipartite graph, it only takes O(V^.5*E) time, and for a graph with unit edges, O(min(V^{2/3},E^.5)*E) time.
// To use this algorithm, create a new FlowNetwork class. Nodes are represented by integers, and to add edges between
// them, you must call the addEdge method. Finally, call findFlow() to get the maximum flow. You can modify it
// to get the mincut, too... I believe that the nodes on the source side of the cut will be exactly the nodes with
// level[i] = 0 after calling findFlow().
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
    
    
    private class Edge {
        int to;
        int cap;
        int flow;
        
        Edge(int toNodeInd, int capacity) {
            to = toNodeInd;
            cap = capacity;
        }
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
