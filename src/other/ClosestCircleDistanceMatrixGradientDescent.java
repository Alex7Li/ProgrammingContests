package other;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

// Given a nxn matrix, what's the closest nxn matrix (according to the L infinity norm) that
// can be generated from the distance matrix of n points on a unit circle?
public class ClosestCircleDistanceMatrixGradientDescent {

private static int n; // size of matrix
private static float[][] matrix; // matrix to estimate
private static boolean isSymmetricAndZeroDiag = true; // if the matrix is symmetric and has 0s down the diagonal

private static int[] perm() {
    int[] perm = new int[n];
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int swp = (int) (Math.random() * (n - i)) + i;
        int temp = perm[swp];
        perm[swp] = perm[i];
        perm[i] = temp;
    }
    return perm;
}

// Start off by generating a random answer. Place n points on the line [0, 1), and a point at 0.
// we will store our answer as the distances between these points.
private static float[] randStartingPosition() {
    float[] positions = new float[n];
    for (int i = 0; i < n; i++) {
        positions[i] = (float) Math.random();
    }
    Arrays.sort(positions);
    // the last distance is 1 - the sum of the others
    float[] distances = new float[n];
    for (int i = 0; i < n - 1; i++) {
        distances[i] = positions[i + 1] - positions[i];
    }
    distances[n - 1] = 1 - (positions[n - 1] - positions[0]);
    return distances;
}

// return the nxn distance matrix
private static float[][] getMatrix(float[] x) {
    float[][] newMatrix = new float[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            newMatrix[i][j] = newMatrix[i][j - 1] + x[j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            newMatrix[j][i] = newMatrix[i][j] = Math.min(newMatrix[i][j], 1 - newMatrix[i][j]);
        }
    }
    return newMatrix;
}

// get the error of a certain set of points on a matrix
// requires that sum(x)=1, and all x are greater than 0.
private static float getError(float[] x) {
    float[][] newMatrix = getMatrix(x);
    float error = 0;
    for (int i = 0; i < n; i++) {
        if (isSymmetricAndZeroDiag) {
            for (int j = i + 1; j < n; j++) {
                error = Math.max(error, Math.abs(newMatrix[i][j] - matrix[i][j]));
            }
        } else {
            for (int j = 0; j < n; j++) {
                error = Math.max(error, Math.abs(newMatrix[i][j] - matrix[i][j]));
            }
        }
    }
    return error;
}

private static float[] updateVariable(float[] x, float eps, int indexToUpdate) {
    float[] y = Arrays.copyOf(x, n);
    boolean canUpdate = false;
    if (eps > 0) {
        if (y[indexToUpdate] + eps < 1) {
            y[indexToUpdate] += eps;
            for (int j : perm()) {
                if (j != indexToUpdate) {
                    float subtractable = y[j];
                    if (subtractable >= eps) {
                        y[j] -= eps;
                        eps = 0;
                        canUpdate = true;
                    } else {
                        eps -= subtractable;
                        y[j] -= subtractable;
                    }
                }
            }
        }
    } else {
        eps = -eps;
        if (y[indexToUpdate] > eps) {
            y[indexToUpdate] -= eps;
            for (int j : perm()) {
                if (j != indexToUpdate) {
                    double addable = 1 - y[j];
                    if (addable >= eps) {
                        y[j] += eps;
                        eps = 0;
                        canUpdate = true;
                    } else {
                        eps -= addable;
                        y[j] -= addable;
                    }
                }
            }
        }
    }
    if (canUpdate) {
        return y;
    } else {
        return null;
    }
}

private static float[][] generateTest(PrintWriter pw, float error) {
    float[] x = randStartingPosition();
    float[][] m = getMatrix(x);
    System.out.println(n);
    for (int i = 0; i < m.length; i++) {
        for (int j = 0; j < m.length; j++) {
            m[i][j] += (Math.random() * 2 * error) - error;
            m[i][j] = Math.max(0, Math.min(m[i][j], 1 - m[i][j]));
        }
    }
    printMatrix(pw, m);
    pw.flush();
    return m;
}

private static void printMatrix(PrintWriter pw, float[][] m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            pw.print(String.format("%.3f", m[i][j]) + " ");
        }
        pw.print(String.format("%.3f", m[i][n - 1]));
        pw.println();
    }
}

private static float[] findGoodLocalSolution(float[] x) {
    float curError = getError(x);
    float eps = (float) (Math.random()) / n; // pretty arbitrary
    // iteratively, look for an x' close to x and check the error. If there is an improvement, use that
    // value instead.
    while (eps > .001f / n) {
        boolean improved = true;
        while (improved) {
            improved = false;
            for (int j : perm()) {
                float nxtError;
                float[] xPrime = updateVariable(x, eps, j % n);
                if (xPrime != null) {
                    nxtError = getError(xPrime);
                    if (nxtError < curError) {
                        x = xPrime;
                        improved = true;
                        curError = nxtError;
                    }
                }
            }
        }
        eps /= 2;
    }
    return x;
}

private static int[] minDist;
private static int[] maxDist;
private static int[] extraMinDist;
private static int[] extraMaxDist;

// find the best solution that has points in a set of nPoints evenly spaced
// points. Only guaranteed to find solutions that are
// 1) within upperBound of the actual answer.
// 2) arranged such that in any half of the circle, there is at least 1 point.
private static float[] findBestSolution(float upperBound, int nPoints) {
    minDist = new int[n];
    maxDist = new int[n];
    extraMaxDist = new int[n];
    extraMinDist = new int[n];
    for (int i = 0; i < n; i++) {
        // using assumption 1 and 2, we can set bounds on the min and max.
        // using assumption 2, matrix[i][i+1] is the distance between the ith and i+1th point.
        // we round using floor/ceil since anything extra would lead to an answer larger than required by assumption 1.
        extraMaxDist[i] = Math.min(nPoints, (int) Math.floor((matrix[i][(i + 1) % n] + upperBound) * nPoints));
        extraMinDist[i] = Math.max(0, (int) Math.ceil((matrix[i][(i + 1) % n] - upperBound) * nPoints));
        maxDist[i] = maxDist[Math.max(0, i - 1)] + extraMaxDist[i];
        minDist[i] = minDist[Math.max(0, i - 1)] + extraMinDist[i];
    }
    for (int i = 0; i < n; i++) {
        int temp = minDist[i];
        int temp2 = minDist[n - 1];
        // Ensure we can get to 1
        minDist[i] = Math.max(minDist[i], nPoints - (maxDist[n - 1] - maxDist[i]));
        // Ensure we aren't forced past 1.
        maxDist[i] = Math.min(Math.min(nPoints, maxDist[i]), nPoints - (temp2 - temp));
    }
    return bruteForce(0, 0, nPoints, new float[n]).argmin;
}


private static MinPair bruteForce(int curIndex, int curPosition, float nPoints, float[] path) {
    float min = Float.POSITIVE_INFINITY;
    float[] argmin = path;
    if (curIndex == n - 1) {
        path[curIndex] = (nPoints - curPosition) / nPoints;
        min = getError(path);
        argmin = Arrays.copyOf(path, path.length);
    } else {
        // set limits for the next index
        int st = Math.max(minDist[curIndex], curPosition + extraMinDist[curIndex]);
        int end = Math.min(maxDist[curIndex], curPosition + extraMaxDist[curIndex]);
        for (int i = st; i <= end; i++) {
            path[curIndex] = (i - curPosition) / nPoints;
            MinPair best = bruteForce(curIndex + 1, i, nPoints, path);
            if (best.min < min) {
                argmin = best.argmin;
                min = best.min;
            }
        }
        if (curIndex == 1) {
            System.err.print((curPosition) + " ");
        }
    }
    return new MinPair(argmin, min);
}

private static class MinPair {
    float[] argmin;
    float min;
    
    MinPair(float[] argmin, float min) {
        this.argmin = argmin;
        this.min = min;
    }
}

private static void permute_matrix() {
    int a = (int) (Math.random() * n);
    int b = (int) (Math.random() * n);
    while (b == a) {
        b = (int) (Math.random() * n);
    }
    for (int i = 0; i < n; i++) {
        if (!(b == i || a == i)) {
            float temp = matrix[a][i];
            matrix[a][i] = matrix[b][i];
            matrix[b][i] = temp;
            temp = matrix[i][a];
            matrix[i][a] = matrix[i][b];
            matrix[i][b] = temp;
        }
    }
}

public static void main(String[] xx) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);
    // the number of points
    n = Integer.parseInt(br.readLine());
    boolean test = false;
    float minError = Float.POSITIVE_INFINITY;
    // read input
    if (test) {
        float error = .1f;
        matrix = generateTest(pw, error);
    } else {
        matrix = new float[n][n];
        for (int i = 0; i < n; i++) {
            String[] nextLine = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                matrix[i][j] = Float.parseFloat(nextLine[j]);
            }
        }
    }
    float[] ans = new float[n];
    // PHASE 1: find an upper bound on the answer
    for (int i = 0; i < 10000; i++) {
        if (i % 10 == 0) {
            permute_matrix();
        }
        float[] x = randStartingPosition();
        float[] updateX = findGoodLocalSolution(x);
        float curError = getError(updateX);
        if (minError > curError) {
            minError = curError;
            ans = updateX;
        }
    }
    pw.println("Error upper bound: " + minError);
    pw.flush();
    
    // PHASE 2: Use that upper bound to assist brute force
    // int points = 100;
    //long stTime = System.currentTimeMillis();
    //float[] ans = findBestSolution(minError, points);
    //System.err.println();
    
    // Print answer
    //pw.println("Time: " + (System.currentTimeMillis() - stTime) / 1000);
    //pw.println("Error: " + getError(ans));
    float[][] solutionMatrix = getMatrix(ans);
    pw.println(Arrays.toString(ans));
    printMatrix(pw, solutionMatrix);
    pw.print("Generated from: ");
    pw.print(String.format("%.3f", ans[0]) + " ");
    for (int i = 1; i < n; i++) {
        ans[i] += ans[i - 1];
        pw.print(String.format("%.3f", ans[i]) + " ");
    }
    pw.flush();
    pw.close();
    br.close();
}
}