package unfinished;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

// https://codeforces.com/gym/101669
public class ChristmasTree {
    private static int[] toSee;
    private static int[] seen;
    private static Color[] colors;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] params = br.readLine().split(" ");
        int n = Integer.parseInt(params[0]);
        int m = Integer.parseInt(params[1]);
        Node[] nodes = new Node[n];
        colors = new Color[m];
        toSee = new int[m];
        seen = new int[m];
        for (int i = 0; i < m; i++) {
            colors[i] = new Color();
            colors[i].color = i;
        }
        int[] colorsArr = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x) - 1).toArray();
        for (int i = 0; i < n; i++) {
            int col = colorsArr[i];
            nodes[i] = new Node(i, col);
            toSee[col]++;
        }
        for (int i = 1; i < n; i++) {
            params = br.readLine().split(" ");
            int from = Integer.parseInt(params[0]) - 1;
            int to = Integer.parseInt(params[1]) - 1;
            nodes[from].edges.add(nodes[to]);
            nodes[to].edges.add(nodes[from]);
        }

        nodes[0].search();
        for (Color c : colors) {
            assert c.edgesFound != 1;
        }
        List<Color> order = topSort(colors);
        assert order.size() == m;
        PrintWriter pw = new PrintWriter(System.out);
        for (Color c : order) {
            pw.println((c.color + 1) + " " + (c.pathSt + 1) + " " + (c.pathEnd + 1));
        }
        pw.flush();
    }

    private static List<Color> topSort(Color[] c) {
        List<Color> order = new ArrayList<>();
        int[] seen = new int[c.length];
        for (int i = 0; i < c.length; i++) {
            if (c[i].edgesFound == 0) {
                c[i].pathSt = 0;
                c[i].pathEnd = 0;
                order.add(c[i]);
                seen[i] = 1;
            }
        }
        for (int i = 0; i < c.length; i++) {
            if (seen[i] != 1) {
                addColor(c[i], order, seen);
            }
        }
        return order;
    }

    private static void addColor(Color c, List<Color> order, int[] seen) {
        seen[c.color] = 2;
        for (Color preReq : c.preReqs) {
            if (seen[preReq.color] == 0) {
                addColor(preReq, order, seen);
            } else if (seen[preReq.color] == 2) {
                throw new RuntimeException();
            }
        }
        seen[c.color] = 1;
        order.add(c);
    }


    private static class Color {
        int color;
        int pathSt = -1;
        int pathEnd = -1;
        int edgesFound = 0;
        Set<Color> preReqs = new HashSet<>();

        private void addNodeToPath(int ind) {
            if (edgesFound == 2) {
                throw new AssertionError();
            } else if (edgesFound == 1) {
                pathEnd = ind;
            } else { // edgesFound == 0
                pathSt = ind;
            }
            edgesFound++;
        }

        @Override
        public String toString() {
            return color + "";
        }
    }

    private static class Node {
        int ind;
        int col;
        boolean searched = false;
        List<Node> edges = new ArrayList<>();

        @Override
        public String toString() {
            return ind + "";
        }

        private Node(int index, int color) {
            ind = index;
            col = color;
        }

        // RETURN the set of colors that are preqs for this node, and will be preqs for the above node -
        // that is, only 1 end is seen in the subtrees of this node.
        Set<Color> search() {
            searched = true;
            int curSeen = seen[col];
            Set<Color> exactlyOneEndInTree = new HashSet<>();

            for (Node n : edges) {
                if (!n.searched) {
                    Color childColor = colors[n.col];
                    int curEdgeFound = childColor.edgesFound;
                    Set<Color> cPreReqs = n.search();

                    // if there is a color on the path below, we should update prerequisites
                    if (childColor.color != col) {
                        // if we find only 1 edge, then we  definitely need to add this color as a prereq.
                        // Hence, we implictly inherit all the prereqs in the tree.
                        assert curEdgeFound != childColor.edgesFound;
                        if (1 + curEdgeFound == childColor.edgesFound) {
                            colors[col].preReqs.add(childColor);
                            if (exactlyOneEndInTree.contains(childColor)) {
                                exactlyOneEndInTree.remove(childColor);
                            } else {
                                exactlyOneEndInTree.add(childColor);
                            }
                        }
                        // if we find both edges, we don't care about this edge - but we should make sure
                        // to inherit all the prerequisites for the color
                        else if (2 + curEdgeFound == childColor.edgesFound) {
                            for (Color c : cPreReqs) {
                                if (c != colors[col]) {
                                    colors[col].preReqs.add(c);
                                }
                            }
                        }
                    }
                }
            }

            toSee[col]--;
            if (toSee[col] == 0) {
                // if this will be the last visited node of this color in the dfs
                while (colors[col].edgesFound < 2) {
                    colors[col].addNodeToPath(ind);
                }
            } else if (seen[col] == curSeen) {
                // there are no nodes of this color further down the tree
                assert colors[col].edgesFound < 2;
                colors[col].addNodeToPath(ind);
            }

            seen[col]++;
            if (toSee[col] > 0 || curSeen > 0) {
                // there is a node of this color in the above tree
                exactlyOneEndInTree.add(colors[col]);
            }
            return exactlyOneEndInTree;
        }
    }
}