package codeforces;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
//http://codeforces.com/problemset/problem/920/B
public class TeaQueue {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for (int t = 0; t < tests; t++) {
			int n = sc.nextInt();
			Queue<Student> q = new LinkedList<Student>();
			List<Student> students = new ArrayList<Student>();
			for (int i = 0; i < n; i++) {
				students.add(new Student(sc.nextInt(), sc.nextInt()));
			}
			int nxtStudent = 0;
			for (int i = 1; i <= 5000; i++) {
				while (nxtStudent != students.size() && students.get(nxtStudent).entryTime == i) {
					q.add(students.get(nxtStudent));
					nxtStudent++;
				}
				if (!q.isEmpty()) {
					Student first = q.remove();
					while (first.exitTime < i && !q.isEmpty()) {
						first.teaTime = 0;
						first = q.remove();
					}
					if (first.exitTime >= i) {
						first.teaTime = i;
					}else {
						first.teaTime = 0;
					}
				}
			}
			for (Student a : students) {
				System.out.print(a.teaTime + " ");
			}
			System.out.println();
		}
		sc.close();
	}

	public static class Student {
		int entryTime;
		int exitTime;
		int teaTime;

		public Student(int l, int r) {
			entryTime = l;
			exitTime = r;
		}

		public int getEntryTime() {
			return entryTime;
		}
	}
}
