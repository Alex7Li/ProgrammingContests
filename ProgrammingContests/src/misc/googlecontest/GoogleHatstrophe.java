package misc.googlecontest;
import java.util.Arrays;
import java.util.Scanner;

//https://ggpuzzles.appspot.com/web/puzzle/hatastrophe
	public class GoogleHatstrophe {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] str = sc.nextLine().split(" ");
		int[] a = Arrays.stream(str).mapToInt(x -> Integer.parseInt(x)).toArray();
		System.out.println(bubbleSort(a));
		sc.close();
	}

	public static int bubbleSort(int[] a) {
		int count = 0;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length - 1; j++) {
				if (a[j] > a[j + 1]) {
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
					count++;
				}
			}
		}
		return count;
	}
}
