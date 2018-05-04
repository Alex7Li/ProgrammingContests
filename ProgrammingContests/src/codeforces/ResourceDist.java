package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

//http://codeforces.com/contest/967/problem/D
//this was so hard... I implemented 2 different bad (and complex) solutions for this problem.
//moral of the story: plan before you code. plan more than you expect you need to.
public class ResourceDist {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] in = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int s1 = in[1];
		int s2 = in[2];
		int[] ain = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		Element[] a = new Element[ain.length];
		for (int i = 1; i <= a.length; i++) {
			a[i - 1] = new Element(i, ain[i - 1]);
		}
		Arrays.sort(a);
		boolean swap = false;
		for (int xx = 0; xx<2; xx++) {
			int k1 = 0;
			for (int i = 1; i < a.length; i++) {
				int ind = a.length - i;
				// check if possible
				int reqVal = (s1 + i - 1) / i;
				if (a[ind].value >= reqVal) {
					k1 = i;
					break;
				}
			}
			if (k1 != 0) {
				for (int k2 = 1; k2 <= a.length-k1; k2++) {
					int reqVal = (s2 + k2 - 1) / k2;
					int lowestInd = -1 - Arrays.binarySearch(a, new Element(-1, reqVal));
					if (a.length - lowestInd >= k1 + k2) {
						System.out.println("Yes");
						if (swap) {
							System.out.println(k2 + " " + k1);
						} else {
							System.out.println(k1 + " " + k2);
						}
						StringBuilder sbk1 = new StringBuilder("" + a[a.length - k1].index);
						for (int j = a.length - k1 + 1; j < a.length; j++) {
							sbk1.append(" " + a[j].index);
						}

						StringBuilder sbk2 = new StringBuilder("" + a[lowestInd].index);
						for (int j = lowestInd + 1; j < lowestInd + k2; j++) {
							sbk2.append(" " + a[j].index);
						}
						if (swap) {
							System.out.println(sbk2);
							System.out.println(sbk1);
						} else {
							System.out.println(sbk1);
							System.out.println(sbk2);
						}
						return;
					}
				}
			}
			int temp = s1;
			s1 = s2;
			s2 = temp;
			swap = true;
		}
		System.out.println("No");
	}

	// https://stackoverflow.com/questions/42399853/sorting-an-array-and-keeping-original-index
	public static class Element implements Comparable<Element> {
		int index, value;

		Element(int index, int value) {
			this.index = index;
			this.value = value;
		}

		public int compareTo(Element e) {
			if (this.value - e.value == 0) {
				return this.index - e.index;
			} else {
				return this.value - e.value;
			}
		}

		public String toString() {
			return this.value + "";
		}
	}
}