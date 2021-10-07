package other.googlefoobar;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class DontGetVolunteered {
    public static void main(String[] args) {
        System.out.println(answer(0, 0));
    }

    public static int answer(int src, int dest) {
        if(src==dest){
            return 0;
        }
        Set<Integer> seen = new HashSet<>();
        Queue<Pair> Q = new LinkedList<>();
        Q.add(new Pair(src % 8, src / 8,0));
        while (true) {
            Pair next = Q.remove();
            Queue<Pair> nearbySquares = new LinkedList<>();
            int newdist = next.dist+1;
            if (next.y > 0) {
                if (next.x > 1) {
                    nearbySquares.add(new Pair(next.x - 2, next.y - 1,newdist));
                }
                if (next.x < 6) {
                    nearbySquares.add(new Pair(next.x + 2, next.y - 1,newdist));
                }
                if (next.y > 1) {
                    if (next.x > 0) {
                        nearbySquares.add(new Pair(next.x - 1, next.y - 2,newdist));
                    }
                    if (next.x < 7) {
                        nearbySquares.add(new Pair(next.x + 1, next.y - 2,newdist));
                    }
                }
            }
            if (next.y < 7) {
                if (next.x > 1) {
                    nearbySquares.add(new Pair(next.x - 2, next.y + 1,newdist));
                }
                if (next.x < 6) {
                    nearbySquares.add(new Pair(next.x + 2, next.y + 1,newdist));
                }
                if (next.y < 6) {
                    if (next.x > 0) {
                        nearbySquares.add(new Pair(next.x - 1, next.y + 2,newdist));
                    }
                    if (next.x < 7) {
                        nearbySquares.add(new Pair(next.x + 1, next.y + 2,newdist));
                    }
                }
            }
            for(Pair p:nearbySquares){
                if(p.ind==dest){
                    return p.dist;
                }
                if(!seen.contains(p.ind)){
                    Q.add(p);
                }
            }
        }
    }

    static class Pair {
        int x;
        int y;
        int dist;
        int ind;

        Pair(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.ind = x + y * 8;
        }
    }
}
