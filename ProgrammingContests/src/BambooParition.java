import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BambooParition {
	public static void main(String[] args) throws IOException {
		FastInOut fio = new FastInOut();
		int n = fio.readInt();
		int k = fio.readInt();
		int[] heights = fio.readIntArray(n);
		fio.close();
		Arrays.sort(heights);
		System.out.println(best2(k,heights));
	}

	private static int best2(int k, int[] heights) {
		int C = k;
		for (int i = 0; i < heights.length; i++) {
			C+= heights[i];
		}
		int max = heights[heights.length-1];
		System.out.println(C + max);
		for (int i = 1; i < 400; i++) {
			System.out.println(getSum(i,heights));
		}
		return 1;
	}
	public static long getSum(int d, int[] heights) {
		long sum = 0;
		for (int i = 0; i < heights.length; i++) {
				sum += Math.ceil((float)heights[i]/d);
		}
		return sum;
	}
	public static boolean tooMuchWaste(int d, int k, int[] heights) {
		long waste = 0;
		for (int i = 0; i < heights.length; i++) {
			if(heights[i] % d != 0) {
				waste += d - (heights[i] % d);
				if (waste > k) {
					return true;
				}
			}
		}
		return false;
	}
}

class FastInOut extends BufferedReader{
    private StringTokenizer tok = new StringTokenizer("");
	public FastInOut() {
		super(new InputStreamReader(System.in));
	}
    String readString() {
        while (!tok.hasMoreTokens()) {
            try {
                tok = new StringTokenizer(readLine());
            } catch (Exception e) {
                return null;
            }
        }
        return tok.nextToken();
    }

    public int readInt() {
        return Integer.parseInt(readString());
    }
    int[] readIntArray(int size) {
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = readInt();
        }
        return a;
    }
}
