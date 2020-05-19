package tools;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

/**
 * Preforms the Hungarian algorithm to find a perfect matching. The matching is stored as follows: The vertex x in the
 * X-set (first index of the input array) is matched to xLabels[x]. Similarly for y, so that yLabels[xLabels[x]]=x.
 * (The xMatching and yMatching field variables are probably not important but there were starting to be too many parameters)
 * <p>
 * Adapted from: https://www.topcoder.com/community/competitive-programming/tutorials/assignment-problem-and-hungarian-algorithm/
 * Note (This code is bad, but the code at that website is an Medium.Rudimentary.order of magnitude worse)
 */
public class HungarianAlgorithm {

/**
 * If a vertex x in set X is matched to a vertex y in set Y,
 * xMatching[x] = y. Otherwise, xMatching[x] = -1
 */
private static int[] xMatching;

/**
 * If a vertex x in set X is matched to a vertex y in set Y,
 * yMatching[y] = x. Otherwise, yMatching[y] = -1
 */
private static int[] yMatching;
/**
 * Labels of vertices in the x-component
 */
private static int[] xLabels;

/**
 * Labels of vertices in the y-component
 */
private static int[] yLabels;

/**
 * Given a tough.interesting.getN by tough.interesting.getN matrix:
 * Perform the hungarian algorithm on a matrix, to determine the best way to choose tough.interesting.getN elements,
 * one from each column and row, such that the maximum sum of elements is achieved.
 * Or: Interpret the matrix as a complete bipartite map from the first index to the second with
 * weights on each edge given by the array.
 * To use the results of this method, look in the int[] xMatching (and/or yMatching). The xLabels
 * and yLabels array are used internally in many methods, you should not use them outside the template.
 * Calculate the maximum-weight perfect matching between the first index set (X) to the second(Y)
 */
public static void hungarianAlgorithm(int[][] matrix) {
    int n = matrix.length;
    
    // initialize arrays
    int[] slack = new int[n];
    int[] slackX = new int[n];
    xLabels = new int[n];
    yLabels = new int[n];
    xMatching = new int[n];
    Arrays.fill(xMatching, -1);
    yMatching = new int[n];
    Arrays.fill(yMatching, -1);
    
    // initialize the values of labels to make a feasible vertex labeling:
    // a labelling such that for all edges from lx to ly, lx[i]+ly[j]>=matrix[i][j]
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] > xLabels[i]) {
                    xLabels[i] = matrix[i][j];
                }
            }
        }
    }
    augment(matrix, 0, n, slack, slackX);
}

/**
 * "Improve" the labeling, that is, change the labels such that we
 * find an augmenting path in the equality graph, while retaining feasibility
 *
 * @param slack: The amount of improvement a particular vertex in the ySet could achieve
 * @param xSet:  xSet[v] specifies if vertex v is in the augmenting path
 * @param ySet:  ySet[v] specifies if vertex v is in the augmenting path
 */
private static void improveLabeling(int n, int[] slack, boolean[] xSet, boolean[] ySet) {
    // find the maximum amount that we can reduce the labels in xSet.
    // This is the minimum value in slack for any node in ySet
    int delta = Integer.MAX_VALUE;
    for (int y = 0; y < n; y++) {
        if (!ySet[y] && slack[y] < delta) {
            delta = slack[y];
        }
    }
    
    // Update the labeling by delta
    for (int x = 0; x < n; x++) {
        if (xSet[x]) {
            xLabels[x] -= delta;
        }
    }
    for (int y = 0; y < n; y++) {
        if (ySet[y]) {
            yLabels[y] += delta;
        } else {
            slack[y] -= delta;
        }
    }
}

/**
 * Add another vertex (curVert) to the alternating path, after lastVert. Then update slack
 */
private static void addToTree(int n, int[][] costMatrix, int[] slack, int[] slackX, int curX, int lastX, boolean[] xSet, int[] prev) {
    xSet[curX] = true;
    prev[curX] = lastX;
    for (int y = 0; y < n; y++) {
        if (xLabels[curX] + yLabels[y] - costMatrix[curX][y] < slack[y]) {
            slack[y] = xLabels[curX] + yLabels[y] - costMatrix[curX][y];
            slackX[y] = curX;
        }
    }
}

/**
 * For hungarianAlgorithm:
 * Check if we have a perfect matching.
 * If not, augment the graph until we create one
 *
 * @param costMatrix  The matrix of costs for the bipartite graph
 * @param maxMatching The size of the maximum matching found so far
 * @param n           The size of the matrix
 * @param slack       For all x in S, slack[y] = min(xLabels[x] + yLabels[y] - costMatrix[x][y]
 * @param slackX      slackx[y] such a vertex, that l(slackx[y]) + l(y) - w(slackx[y],y) = slack[y]
 */
private static void augment(int[][] costMatrix, int maxMatching, int n, int[] slack, int[] slackX) {
    //check if we have a perfect matching
    if (maxMatching == n) {
        return;
    }
    // if not, find an unmatched node in the X set
    int root = -1;
    Queue<Integer> queue = new ArrayDeque<>(n);
    boolean[] xSet = new boolean[n];
    boolean[] ySet = new boolean[n];
    int[] prev = new int[n];
    Arrays.fill(prev, -1);
    // look for an unmatched node in the equality graph to
    // serve as the root of the alternating tree
    for (int x = 0; x < n; x++) {
        if (xMatching[x] == -1) {
            root = x;
            prev[x] = -2; // There is no parent to this node in the alternating tree
            queue.add(root);
            xSet[x] = true;
            break;
        }
    }
    
    // We will need to find the smallest difference between edge cost
    // and label cost, the slack array will help us find that in linear time.
    // slackX will remember where the label changes have taken place
    for (int y = 0; y < n; y++) {
        slack[y] = xLabels[root] + yLabels[y] - costMatrix[root][y];
        slackX[y] = root;
    }
    
    // the elements fo X and Y at the end of the augmenting path
    int endX;
    int endY;
    // Build the alternating path tree.
    // use BFS till we find an augmenting path to an unmatched node
    // that is in Y and in the equality graph
    pathFound:
    while (true) {
        while (!queue.isEmpty()) { // build tree
            int x = queue.remove(); // current vertex from X part
            for (int y = 0; y < n; y++) {
                // if this edge is in the equality graph
                if (costMatrix[x][y] == xLabels[x] + yLabels[y] && !ySet[y]) {
                    // if y is unmatched, we have found an augmenting path
                    if (yMatching[y] == -1) {
                        endX = x;
                        endY = y;
                        break pathFound;
                    }
                    // all y to the set of edges on this tree
                    ySet[y] = true;
                    queue.add(yMatching[y]);
                    addToTree(n, costMatrix, slack, slackX, yMatching[y], x, xSet, prev);
                }
            }
        }
        
        // we have not found an augmenting path, update labels
        improveLabeling(n, slack, xSet, ySet);
        queue.clear();
        for (int y = 0; y < n; y++) {
            //in this cycle we add edges that were added to the equality graph as a
            //result of improving the labeling, we add edge (slackX[y], y) to the tree if
            //and only if !T[y] && slack[y] == 0, also with this edge we add another one
            //(y, yx[y]) or augment the matching, if y was exposed
            if (!ySet[y] && slack[y] == 0) {
                if (yMatching[y] == -1) {
                    //max matching found
                    endX = slackX[y];
                    endY = y;
                    break pathFound;
                } else {
                    ySet[y] = true; //else just add y to T,
                    if (!xSet[yMatching[y]]) {
                        // add vertex matched to y to queue
                        queue.add(yMatching[y]);
                        // add edges (x,y) and (y,y Mactching[y]) to the tree
                        addToTree(n, costMatrix, slack, slackX, yMatching[y], slackX[y], xSet, prev);
                    }
                }
            }
        }
    }
    //in this cycle we inverse edges along augmenting path
    for (int cx = endX, cy = endY, ty; cx != -2; cx = prev[cx], cy = ty) {
        ty = xMatching[cx];
        yMatching[cy] = cx;
        xMatching[cx] = cy;
    }
    // augment the rest of the path
    augment(costMatrix, maxMatching + 1, n, slack, slackX);
}

}
