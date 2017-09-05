import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class NumberList {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int x = Integer.parseInt(br.readLine());
		int y = Integer.parseInt(br.readLine());
		String[] in = br.readLine().split(" ");
		int[] list = new int[n];
		for (int i = 0; i < n; i++) {
			list[i] = Integer.parseInt(in[i]);
		}
		
	}
}
