package unfinished;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.HashMap;
import java.util.SortedSet;
import java.util.TreeSet;

public class StringRestoration {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		SortedSet<String> strings = new TreeSet<>(new StringLengthComp());
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			strings.add(s);
		}
		HashMap<String,Integer> sOverlap = new HashMap<>();
		for(String s:strings) {
			boolean has = false;
			for (String t:sOverlap.keySet()) {
				if(t.contains(s)){
					if(has) {
						System.out.println("NO");
						return;
					}
					has = true;
				}
			}
			if(!has) {
				sOverlap.put(s, 0);
			}
		}
		for (int i = 0; i < sOverlap.size(); i++) {
			//frontOverlap = 0;
		}
		
		StringBuilder string = new StringBuilder("");
		
		System.out.println(string);
	}

	public static class StringLengthComp implements Comparator<String> {
		@Override
		public int compare(String o1, String o2) {
			int dist = o2.length() - o1.length();
			if(dist == 0) {
				dist = o2.compareTo(o1);
			}
			return dist;
		}
	}
}
