package math.geometry;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

//https://codeforces.com/contest/1163/problem/C2
public class PowerTransmission {
public static void main(String[] xx) throws IOException {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[][] pairs = new int[n][2];
    for (int i = 0; i < n; i++) {
        pairs[i][0] = sc.nextInt();
        pairs[i][1] = sc.nextInt();
    }
    Line[] lines = new Line[(n * (n - 1)) / 2];
    int cur = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            lines[cur] = new Line(pairs[i][0], pairs[i][1], pairs[j][0], pairs[j][1]);
            cur++;
        }
    }
    Arrays.sort(lines);
    List<Line> distinctLines = new ArrayList<>();
    distinctLines.add(lines[0]);
    for (int i = 0; i < lines.length - 1; i++) {
        if (lines[i].compareTo(lines[i + 1]) != 0) {
            distinctLines.add(lines[i + 1]);
        }
    }
    long ans = 0;
    long linesWithCurSlope = 1;
    for (int i = 0; i < distinctLines.size() - 1; i++) {
        if (distinctLines.get(i).sameSlope(distinctLines.get(i + 1))) {
            linesWithCurSlope++;
        } else {
            ans += linesWithCurSlope * (distinctLines.size() - linesWithCurSlope);
            linesWithCurSlope = 1;
        }
    }
    ans += linesWithCurSlope * (distinctLines.size() - linesWithCurSlope);
    System.out.println(ans / 2);
}

static class Line implements Comparable<Line> {
    Fraction slope;
    Fraction intercept;
    
    private boolean sameSlope(Line o) {
        return slope.equals(o.slope);
    }
    
    Line(int x1, int y1, int x2, int y2) {
        int num = y1 - y2;
        int denom = x1 - x2;
        slope = new Fraction(num, denom);
        if (denom == 0) {
            intercept = new Fraction(x1);
        } else {
            intercept = new Fraction(y1).subtract(slope.multiply(new Fraction(x1)));
        }
    }
    
    
    @Override
    public int compareTo(Line o) {
        if (slope.equals(o.slope)) {
            return intercept.compareTo(o.intercept);
        } else {
            return slope.compareTo(o.slope);
        }
    }
    
}

private static class Fraction implements Comparable<Fraction> {
    long num;
    long denom; //always positive by convention
    
    Fraction(int numerator) {
        num = numerator;
        denom = 1;
    }
    
    Fraction(long numerator, long denominator) {
        int sgn = denominator >= 0 ? 1 : -1;
        denom = denominator * sgn;
        num = numerator * sgn;
        if (denominator == 0) { // if one of denom or num = 0, make the other be 1.
            num = 1;            // this is so equality checks work. (making the other be 0 breaks compareTo)
        } else if (numerator == 0) {
           denom = 1;
        } else {
            long gcd = Math.abs(gcd(denom, num));
            denom /= gcd;
            num /= gcd;
        }
    }
    
    
    private Fraction multiply(Fraction subtrahend) {
        return new Fraction(num * subtrahend.num, denom * subtrahend.denom);
    }
    
    private Fraction subtract(Fraction subtrahend) {
        return new Fraction(num * subtrahend.denom - subtrahend.num * denom, denom * subtrahend.denom);
    }
    
    private static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    
    @Override
    public boolean equals(Object other) {
        if (!(other instanceof Fraction)) {
            return false;
        }
        Fraction o = (Fraction) (other);
        return (num == o.num && denom == o.denom);
    }
    
    @Override
    public int hashCode() {
        return (int) (num + (denom << 16));
    }
    
    @Override
    public String toString() {
        return num + "/" + denom;
    }
    
    @Override
    public int compareTo(Fraction o) {
        // might overflow with big numbers
        return Long.compare(num * o.denom, denom * o.num);
    }
    
}
}
