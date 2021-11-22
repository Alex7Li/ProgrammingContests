package misc.gametheory.asymmetric;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

//https://codingcompetitions.withgoogle.com/codejam/round/00000000000516b9/0000000000134c90
public class RobotProgrammingStrategy {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());
        for (int t = 1; t <= cases; t++) {
            int n = Integer.parseInt(br.readLine());
            List<char[]> moves = new ArrayList<char[]>();
            for (int i = 0; i < n; i++) {
                moves.add(br.readLine().toCharArray());
            }
            int curMove = 0;
            int timesSinceLastBeat = 0;
            StringBuilder solution = new StringBuilder();
            while (!moves.isEmpty()) {
                Set<Character> movesSeen = new HashSet<>();
                for (int i = 0; i < moves.size(); i++) {
                    movesSeen.add(moves.get(i)[curMove % moves.get(i).length]);
                }
                if (movesSeen.size() == 3 || timesSinceLastBeat >= 2000) {
                    solution = new StringBuilder("IMPOSSIBLE");
                    break;
                } else if (movesSeen.size() == 2) {
                    char move;
                    char beats;
                    if (!movesSeen.contains('R')) {
                        move = 'S';
                        beats = 'P';
                    } else if (!movesSeen.contains('S')) {
                        move = 'P';
                        beats = 'R';
                    } else {
                        move = 'R';
                        beats = 'S';
                    }
                    solution.append(move);
                    for (int i = 0; i < moves.size(); i++) {
                        if (moves.get(i)[curMove % moves.get(i).length] == beats) {
                            moves.remove(i);
                            i--;
                            timesSinceLastBeat = 0;
                        }
                    }
                    curMove++;
                    timesSinceLastBeat++;
                } else {
                    if (movesSeen.contains('R')) {
                        solution.append('P');
                    } else if (movesSeen.contains('S')) {
                        solution.append('R');
                    } else {//paper
                        solution.append('S');
                    }
                    break;
                }
            }

            System.out.println("Case #" + t + ": " + solution);
        }
    }
}
