package unfinished;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 
 */

/**
 * @author 7Alex
 *
 */
public class BambooParitionBrute {
	public static void main(String[] args) throws IOException {
		FastIO fio = new FastIO();
		int n = fio.readInt();
		int k = fio.readInt();
		int[] heights = fio.readIntArray(n);
		fio.close();
		Arrays.sort(heights);
		System.out.println(best(k,heights));
	}

	public static int best(int k, int[] heights) {
		int minValid = 1;
		int max = heights[heights.length-1]+k/heights.length;
		for (int d = 2; d < max; d++) {
			if(!tooMuchWaste(d,k,heights)) {
				minValid = d;
			}
		}
		return minValid;
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

class FastIO extends BufferedReader{
    private StringTokenizer tok = new StringTokenizer("");
	public FastIO() {
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
