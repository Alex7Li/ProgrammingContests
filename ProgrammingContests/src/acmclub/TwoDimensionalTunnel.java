package acmclub;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class TwoDimensionalTunnel {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        TreeSet<Point> points = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            points.add(new Point(sc.nextInt(), sc.nextInt()));
        }
        ArrayList<Point> hull = new ArrayList<>();

        // construct top of hull
        Point preLastPoint = points.first();
        Point lastPoint = points.higher(preLastPoint);
        hull.add(preLastPoint);
        // make sure we turn RIGHT O!
        for (Point p : points) {
            if (turnsRight(preLastPoint, lastPoint, p)) {
                preLastPoint = lastPoint;
                lastPoint = p;
                hull.add(lastPoint);
            } else {
                lastPoint = p;
            }
        }
        hull.add(lastPoint);

        //construct bottom of hull
        preLastPoint = points.last();
        lastPoint = points.lower(preLastPoint);
        hull.add(preLastPoint);
        for (Point p : points.descendingSet()) {
            if (turnsRight(preLastPoint, lastPoint, p)) {
                preLastPoint = lastPoint;
                lastPoint = p;
                hull.add(lastPoint);
            } else {
                lastPoint = p;
            }
        }
        hull.add(lastPoint);


    }

    public static boolean turnsRight(Point p1, Point p2, Point p3) {
        int x1 = p2.x - p1.x;
        int y1 = p2.y - p2.y;
        int x2 = p2.x - p3.x;
        int y2 = p2.y - p3.y;
        return x1 * y2 - y1 * x2 > 0;
    }

    static class Point implements Comparable<Point> {
        private int x;
        private int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            if (this.x == o.x) {
                return this.y - o.y;
            }
            return this.x - o.x;
        }
    }
}
