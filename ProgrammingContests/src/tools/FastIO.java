/**
 * 
 */
package tools;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.StringTokenizer;

/**
 * @author 7Alex
 *
 */
public class FastIO extends BufferedReader{
    private StringTokenizer tok = new StringTokenizer("");
	public FastIO() {
		super(new InputStreamReader(System.in));
	}
	public FastIO(Reader in) {
		super(in);
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

    public long readLong() {
        return Long.parseLong(readString());
    }

    public double readDouble() {
        return Double.parseDouble(readString());
    }

    public int[] readIntArray(int size) {
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = readInt();
        }
        return a;
    }
}
