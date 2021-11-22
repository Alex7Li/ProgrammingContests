package math.geometry;
import java.awt.Polygon;
import java.awt.geom.Area;
import java.awt.geom.PathIterator;
import java.util.ArrayList;
import java.util.Scanner;

//https://open.kattis.com/problems/abstractart
public class AbstractArt {
	// must account for shapes that intersect twice
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		Polygon[] polygons = new Polygon[n];
		double totalArea = 0;
		for (int i = 0; i < n; i++) {
			int m = s.nextInt();
			int[] xpoints = new int[m];
			int[] ypoints = new int[m];
			for (int j = 0; j < m; j++) {
				xpoints[j] = s.nextInt();
				ypoints[j] = s.nextInt();
			}
			// https://stackoverflow.com/questions/8144156/using-pathiterator-to-return-all-line-segments-that-constrain-an-area
			double area = 0;
			for (int j = 0; j < m; j++) {
				area += xpoints[j] * ypoints[(j + 1) % m];
				area -= xpoints[(j + 1) % m] * ypoints[j];
			}
			totalArea += Math.abs(area / 2);
			polygons[i] = new Polygon(xpoints, ypoints, m);
		}
		s.close();
		double intersectingArea = 0;
		System.out.println(totalArea);
		for (int i = 0; i < polygons.length; i++) {
			for (int j = i + 1; j < polygons.length; j++) {
				if (polygons[j].intersects(polygons[i].getBounds())) {
					Area a = new Area(polygons[i]);
					a.intersect(new Area(polygons[j]));
					int ind = 0;
					PathIterator path = a.getPathIterator(null);
					ArrayList<double[]> points = new ArrayList<double[]>();
					while (!path.isDone()) {
						points.add(new double[2]);
						int type = path.currentSegment(points.get(ind));
						//System.err.println(Arrays.toString(points.get(ind)) + " " + type);
						ind++;
						path.next();
						if (type == PathIterator.SEG_CLOSE) {
							points.remove(points.size() - 1);
							double area = 0;
							for (int k = 0; k < points.size(); k++) {
								area += points.get(k)[0] * points.get((k + 1) % points.size())[1];
								area -= points.get(k)[1] * points.get((k + 1) % points.size())[0];
							}
							intersectingArea += Math.abs(area / 2);
							points = new ArrayList<double[]>();
							ind = 0;
						}
					}
				//	System.err.println();
				}
			}
		}

		System.out.println(totalArea - intersectingArea);
	}
}
