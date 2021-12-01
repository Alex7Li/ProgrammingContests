package codeforces;
import java.util.Scanner;

//http://codeforces.com/contest/902/problem/0
public class VisitingAFriend {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		boolean[] visitable = new boolean[m];
		for (int i = 0; i <n; i++) {
			int loc = s.nextInt();
			int dist = s.nextInt();
			for (int j = loc; j < Math.min(dist,m); j++) {
				visitable[j] = true;
			}
		}
		s.close();
		for (int j = 0; j < m ; j++) {
			if(!visitable[j]) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
		
	}
	public static class Teleport implements Comparable<Teleport>{
		int loc;
		int dist;
		public Teleport(int l,int d) {
			loc = l;
			dist = d;
		}
		@Override
		public int compareTo(Teleport other) {
			return loc-other.loc;
		}
	}
}
