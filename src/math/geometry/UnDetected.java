package math.geometry;

import java.io.IOException;
import java.util.*;

//https://naq15.kattis.com/problems/undetected
public class UnDetected {
public static void main(String[] xx) throws IOException {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    Collection<Node> sensors = new HashSet<Node>();
    for (int i = 0; i < n; i++) {
        Node newSensor = new Node(sc.nextInt(), sc.nextInt(), sc.nextInt(), i);
        for (Node sensor : sensors) {
            newSensor.combine(sensor);
        }
        sensors.add(newSensor);
        boolean[] seen = new boolean[sensors.size()];
        Queue<Node> q = new LinkedList<Node>();
        seen[sensors.size() - 1] = true;
        q.add(newSensor);
        boolean right = false;
        boolean left = false;
        while (!q.isEmpty()) {
            Node cur = q.poll();
            if (cur.rightConnected) {
                right = true;
            }
            if (cur.leftConnected) {
                left = true;
            }
            for (Node nxt : cur.edges) {
                if (!seen[nxt.index]) {
                    seen[nxt.index] = true;
                    q.add(nxt);
                }
            }
        }
        if (right && left) {
            System.out.println(i);
            return;
        }
    }
}

private static class Node {
    Collection<Node> edges = new HashSet<>();
    private int x;
    private int y;
    private int r;
    int index;
    boolean leftConnected;
    boolean rightConnected;
    
    private Node(int x, int y, int r, int index) {
        this.x = x;
        this.y = y;
        this.r = r;
        this.index = index;
        if (x + r > 200) {
            rightConnected = true;
        }
        if (x - r < 0) {
            leftConnected = true;
        }
    }
    
    private void combine(Node o) {
        if ((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y) < (r + o.r) * (r + o.r)) {
            o.edges.add(this);
            this.edges.add(o);
        }
    }
}
}
