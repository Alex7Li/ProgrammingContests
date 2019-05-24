package other.googlecontest;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

//https://ggpuzzles.appspot.com/web/puzzle/listening-to-their-rock-and-roll
public class GoogleRockAndRoll {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new FileReader("src/misc/prob.txt"));
		boolean[][] pos = new boolean[20][20];
		for (int i = 0; i < pos.length; i++) {
			String[] input = sc.nextLine().split("\t");
			for (int j = 0; j < input.length; j++) {
				pos[i][j] = input[j].equals("1");
			}
		}
		String[] movesStr = sc.nextLine().split("\t");
		char[] moves = new char[movesStr.length];
		for (int i = 0; i < moves.length; i++) {
			moves[i] = movesStr[i].charAt(0);
		}
		sc.close();
		for (int i = 0; i < pos.length; i++) {
			for (int j = 0; j < pos[0].length; j++) {
				// decode it
				boolean validStart = true;
				int[] endPos = { i, j };
				for (int k = 0; k < moves.length; k++) {
					if (endPos[0] < 0 || endPos[0] >= pos.length || endPos[1] < 0 || endPos[1] >= pos.length
							|| pos[endPos[0]][endPos[1]]) {
						validStart = false;
						break;
					}
					switch (moves[k]) {
					case 'N':
						endPos[0]--;
						break;
					case 'E':
						endPos[1]++;
						break;
					case 'W':
						endPos[1]--;
						break;
					case 'S':
						endPos[0]++;
						break;
					default:
						System.out.println("ERR");
					}
				}
				if (endPos[0] < 0 || endPos[0] >= pos.length || endPos[1] < 0 || endPos[1] >= pos.length
						|| pos[endPos[0]][endPos[1]]) {
					validStart = false;
				}
				if (validStart) {
					System.out.println(endPos[0] + " " + endPos[1]);
				}
			}
		}
	}
}

/**
 * [Alarm, Alley, Beer, Bowling, Buck, Burglar, Candy, Cane, Cat, Clock,
 * Dancing, Delivery, Eye, Naked, Queen, Radio, Root, Rush, Square, Station,
 * Sugar, Tap, Times, Tough, Truck]
 **/