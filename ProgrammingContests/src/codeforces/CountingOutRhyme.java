package codeforces;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class CountingOutRhyme {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] data = br.readLine().split(" ");
		int n = Integer.parseInt(data[0]);
		int kt = Integer.parseInt(data[1]);
		String[] Ks = br.readLine().split(" ");
		int[] k = new int[kt];
		for (int i = 0; i < Ks.length; i++) {
			k[i] = Integer.parseInt(Ks[i]);
		}
		ArrayList<Kid> kids = new ArrayList<Kid>(n);
		for (int i = 0; i < n; i++) {
			kids.add(i, new Kid(i));
		}
		// remove kids
		StringBuilder s = new StringBuilder();
		int cur = 0;
		for (int i = 0; i < kt; i++) {
			int index = (k[i] + cur) % kids.size();
			s.append(kids.get(index).startingPos + 1 + " ");
			kids.remove(index);
			cur = index;
		}
		System.out.println(s.toString());
	}
}

class Kid {
	int startingPos;

	public Kid(int i) {
		startingPos = i;
	}
}
