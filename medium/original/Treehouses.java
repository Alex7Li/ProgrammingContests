package medium.original;

import java.util.*;

//https://open.kattis.com/contests/wed9ew/problems/treehouses
public class Treehouses {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int e = sc.nextInt();
        int p = sc.nextInt();
        Node[] points = new Node[n];
        for (int i = 0; i < n; i++) {
            points[i] = new Node(sc.nextDouble(),sc.nextDouble(),i);
        }
        List<DistNodePair> distances = new ArrayList<>();
        for (int i = 0; i < e - 1; i++) {
            points[i].merge(points[i+1]);
        }
        for (int i = 0; i < p; i++) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            points[x].merge(points[y]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                distances.add(new DistNodePair(points[i], points[j]));
            }
        }
        distances.sort(Comparator.comparingDouble(o -> o.d));
        double extra = 0;
        for (int i = 0; i < distances.size(); i++) {
            DistNodePair nxt = distances.get(i);
            if(nxt.a.merge(nxt.b)){
                extra += nxt.d;
            }
        }
        System.out.println(extra);
    }

    private static class DistNodePair{
        Node a;
        Node b;
        double d;
        DistNodePair(Node a, Node b){
            this.a = a;
            this.b = b;
            d = a.distTo(b);
        }
    }

    private static class Node {
        double x;
        double y;
        Node groupRep;
        int groupSize;
        Node(double x, double y, int ind) {
            this.x = x;
            this.y = y;
            groupRep = this;
            groupSize = 1;
        }

        private static Node findRep(Node o){
            while(o.groupRep != o){
                o.groupRep = o.groupRep.groupRep;
                o = o.groupRep;
            }
            return o;
        }

        // return if there was a merge
        private boolean merge(Node o){
            Node thisGroup = findRep(this);
            Node otherGroup = findRep(o);
            if(thisGroup==otherGroup){
                return false;
            }
            if(thisGroup.groupSize < otherGroup.groupSize){
                Node temp = thisGroup;
                thisGroup = otherGroup;
                otherGroup = temp;
            }

            otherGroup.groupRep = thisGroup;
            thisGroup.groupSize = thisGroup.groupSize + otherGroup.groupSize;
            return true;
        }

        private double distTo(Node b){
            return Math.sqrt((this.x-b.x)*(this.x-b.x)+(this.y-b.y)*(this.y-b.y));
        }

    }
}
