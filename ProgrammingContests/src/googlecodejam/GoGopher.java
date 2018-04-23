package googlecodejam;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;
//https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/0000000000007a30
public class GoGopher {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int testCases = sc.nextInt();
		for (int t = 1; t <= testCases; t++) {
			int area = sc.nextInt();
			int h = Math.max(3, 1 + (int) Math.sqrt(area));
			int w = h;
			assert h * w >= area;
			PriorityQueue<Position> pos = new PriorityQueue<Position>(new Position(0, 0, 0));
			int midH = 1 + h / 2;
			int midW = 1 + w / 2;
			Position[][] garden = new Position[h + 3][w + 3];
			for (int i = 0; i < garden.length; i++) {
				for (int j = 0; j < garden[0].length; j++) {
					int priority = Math.abs(i - midH) + Math.abs(j - midW);
					garden[i][j] = new Position(priority, i, j);
				}
			}
			for (int i = 2; i < w; i++) {
				for (int j = 2; j < h; j++) {
					pos.add(garden[i][j]);
				}
			}
			while (true) {
				Position p = pos.poll();
				System.out.println(p.x + " " + p.y);
				System.out.flush();
				int x = sc.nextInt();
				int y = sc.nextInt();
				if (x == 0 && y == 0) {
					break;
				}
				if (!garden[x][y].dug) {
					garden[x][y].dug = true;
					for (int i = x - 1; i <= x + 1; i++) {
						for (int j = y - 1; j <= y + 1; j++) {
							garden[i][j].neighbors--;
						}
					}
				}
				if (garden[p.x][p.y].neighbors != 0) {
					pos.add(p);
				}
			}
		}
		sc.close();
	}

	public static class Position implements Comparator<Position> {
		boolean dug = false;
		int priority;
		int neighbors;
		int x;
		int y;

		public Position(int priority, int x, int y) {
			this.x = x;
			this.y = y;
			neighbors = 9;
			this.priority = priority;
		}

		@Override
		public int compare(Position o1, Position o2) {
			return (o2.priority + o2.neighbors) - (o1.priority + o1.neighbors);
		}

	}
}