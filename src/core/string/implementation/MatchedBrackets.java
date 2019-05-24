package core.string.implementation;
import java.util.Scanner;
//https://www.codechef.com/ZCOPRAC/problems/ZCO12001
public class MatchedBrackets {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int curDepth = 0;
		int maxDepth = 0;
		int maxDepthIn = 0;
		int curLen = 0;
		int maxLen = 0;
		int curLenIn = 1;
		int maxLenIn = 1;
		for (int i = 1; i <= n; i++) {
			if (curDepth == 0) {
				if (curLen > maxLen) {
					maxLenIn = curLenIn;
					maxLen = curLen;
				}
				curLen = 0;
				curLenIn = i;
			}
			int btype = s.nextInt();
			if (btype == 1) {
				curDepth++;
				if (curDepth > maxDepth) {
					maxDepth = curDepth;
					maxDepthIn = i;
				}
			} else {
				curDepth--;
			}
			curLen++;

		}
		if (curDepth == 0 && curLen > maxLen) {
			maxLenIn = curLenIn;
			maxLen = curLen;
		}
		System.out.println(maxDepth + " " + maxDepthIn + " " + maxLen + " " + maxLenIn);
		s.close();
	}
}
