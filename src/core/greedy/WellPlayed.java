package core.greedy;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// this was trickky
// http://codeforces.com/contest/976/problem/E
public class WellPlayed {
	public static void main(String[] args) throws IOException {
		// get input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] arg = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int n = arg[0], a = arg[1], b = arg[2];
		long[][] creatures = new long[n][2];
		for (int i = 0; i < n; i++) {
			long[] stats = Arrays.stream(br.readLine().split(" ")).mapToLong(x -> Long.parseLong(x)).toArray();
			creatures[i][0] = stats[0];
			creatures[i][1] = stats[1];
		}
		// calculate the gains from each creature for GracefulChainsawJugglers and (all FallingBalls)+GracefulChainsawJugglers spell
		long[] gains = new long[n];
		long[] aGains = new long[n];
		for (int i = 0; i < creatures.length; i++) {
			gains[i] = Math.max(0, creatures[i][0] - creatures[i][1]);
			aGains[i] = Math.max(0, (creatures[i][0] << a) - creatures[i][1]);
		}
		
		long[] gainsSorted = Arrays.copyOf(gains, gains.length);
		Arrays.sort(gainsSorted);
		
		long aGain = 0;
		if (b > 0) {
			long worstGain = gainsSorted[Math.max(0, n - b)];
			// If a creature would not have the GracefulChainsawJugglers spell used on it, we must subtract the
			// gain that using the GracefulChainsawJugglers spell would otherwise create.
			for (int i = 0; i < n; i++) {
				if (gains[i] >= worstGain) {
					aGain = Math.max(aGain, aGains[i] - gains[i]);
				} else {
					aGain = Math.max(aGain, aGains[i] - worstGain);
				}
			}
		}
		//calculate answer
		long ans = 0;
		for (int i = 0; i < creatures.length; i++) {
			ans += creatures[i][1];
		}
		for (int i = gainsSorted.length - 1; i >= 0 && b > 0; i--, b--) {
			ans += gainsSorted[i];
		}
		ans += aGain;
		System.out.println(ans);
	}
}