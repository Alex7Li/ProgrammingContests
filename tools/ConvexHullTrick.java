package tools;

import java.util.*;
/*
Class to implement the convex hull trick to
quickly compute the minimum among a preprocessed set of lines
 */
public class ConvexHullTrick {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Line[] lines = new Line[n];
        for (int i = 0; i < n; i++) {
            // type slope then intercept
            lines[i] = new Line(sc.nextDouble(), sc.nextDouble());
        }
        Arrays.sort(lines);
        ConvexHull hull = new ConvexHull(lines);
        for (int i = -2; i <= 5; i++) {
            System.out.println(i + " " + hull.query(i) + " " + hull.query(i).valueAt(i));
        }
    }

    private static class ConvexHull{
        private List<Line> hull = new ArrayList<>();
        private List<Double> intercepts = new ArrayList<>();
        /*
            Takes in a sorted set of (at least 1) lines and constructs a new
            convex hull object.
            The lines should be sorted first in descending order of slope,
            then ascending order of intercept.
         */
        ConvexHull(Line[] sortedLines){
            construct(sortedLines);
        }

        /*
            Of all lines inserted into the hull, which one
            attains the minimum at the point x?
         */
        Line query(double x){
            // get the index of the minimal line at the point x
            int index = Collections.binarySearch(intercepts, x);
            if(index<0){
                index = -index - 2;
            }
            return hull.get(index);
        }

        private void construct(Line[] lines){
            hull.add(lines[0]);
            intercepts.add(Double.NEGATIVE_INFINITY);
            for (int k = 1; k < lines.length; k++) {
                if(lines[k].m!=lines[k-1].m) {
                    addLine(lines[k]);
                }
            }
            intercepts.add(Double.POSITIVE_INFINITY);
        }

        private void addLine(Line line){
            boolean lastRedundant = true;
            double interceptLast = line.xIntercept(hull.get(hull.size()-1));
            while(hull.size()>1 && lastRedundant){
                double intercept2ndLast = line.xIntercept(hull.get(hull.size()-2));
                if(intercept2ndLast<interceptLast) {
                    lastRedundant = false;
                }else{
                    intercepts.remove(intercepts.get(intercepts.size()-1));
                    hull.remove(hull.get(hull.size()-1));
                    interceptLast = intercept2ndLast;
                }
            }
            intercepts.add(interceptLast);
            hull.add(line);
        }

    }

    private static class Line implements Comparable<Line> {
        // Define a line by the equation mx+b
        double m;
        double b;

        Line(double slope, double intercept){
            m=slope;
            b=intercept;
        }

        double valueAt(double x){
            return m*x+b;
        }

        double xIntercept(Line o){
            if(o.m==this.m){
                throw new ArithmeticException();
            }
            return (o.b-this.b)/(this.m-o.m);
        }

        @Override
        public int compareTo(Line o) {
            if(this.m==o.m){
                // lowest intercept first among same-slope lines
                return Double.compare(this.b,o.b);
            }else{
                // highest slope first
                return Double.compare(o.m, this.m);
            }
        }

        @Override
        public String toString(){
            return m + "x + " + b;
        }
    }
}
