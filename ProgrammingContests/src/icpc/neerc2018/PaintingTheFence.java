package icpc.neerc2018;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

// https://codeforces.com/gym/101911/problem/E
public class PaintingTheFence {

    // the maximum number a color can take
    private static final int MAX_COLOR = 300_001;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        int[] a = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        int m = Integer.parseInt(br.readLine());
        int[] orders = Arrays.stream(br.readLine().split(" "))
                .mapToInt(x -> Integer.parseInt(x)).toArray();
        Node[] firstOccurrences = new Node[MAX_COLOR];
        Node[] lastOccurrences = new Node[MAX_COLOR];
        Node lastNode = null;
        for (int i = 0; i < n; i++) {
            Node node = new Node(a[i], i);
            node.lastNode = lastNode;
            if (lastNode != null) {
                lastNode.nextNode = node;
            }
            lastNode = node;
            if (firstOccurrences[a[i]] == null) {
                firstOccurrences[a[i]] = node;
                lastOccurrences[a[i]] = node;
            } else {
                lastOccurrences[a[i]].nextSameLabel = node;
                node.lastSameLabel = lastOccurrences[a[i]];
                lastOccurrences[a[i]] = node;
            }
        }
        for (int order : orders) {
            Node st = firstOccurrences[order];
            Node end = lastOccurrences[order];
            if (st != null && st != end) {
                Node cur = st;
                while (cur.nextNode != end) {
                    cur = cur.nextNode;
                    if (cur.lastSameLabel != null) {
                        if (cur.nextSameLabel != null) {
                            cur.lastSameLabel.nextSameLabel = cur.nextSameLabel;
                            cur.nextSameLabel.lastSameLabel = cur.lastSameLabel;
                        } else {
                            cur.lastSameLabel.nextSameLabel = null;
                            lastOccurrences[cur.label] = cur.lastSameLabel;
                        }
                    } else if (cur.nextSameLabel != null) {
                        cur.nextSameLabel.lastSameLabel = null;
                        firstOccurrences[cur.label] = cur.nextSameLabel;
                    } else {
                        firstOccurrences[cur.label] = null;
                        lastOccurrences[cur.label] = null;
                    }
                }
                st.nextNode = end;
                end.lastNode = st;
            }
        }
        int[] endArray = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            if (lastNode == null) {
                System.out.println(1);
                return;
            }
            endArray[i] = lastNode.label;
            if (i == lastNode.index) {
                lastNode = lastNode.lastNode;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            pw.print(endArray[i] + " ");
        }
        pw.println(endArray[n - 1]);
        pw.flush();
        br.close();
        pw.close();
    }

    private static class Node {
        int label;
        int index;
        Node nextNode;
        Node lastNode;
        Node nextSameLabel;
        Node lastSameLabel;

        Node(int label, int index) {
            this.label = label;
            this.index = index;
        }
    }
}
