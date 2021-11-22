package other.acmclub;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//https://github.com/OSUACM/Weekly_Events/blob/master/180217.md
public class CanUEscapeShort {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new FileReader("src/acmclub/escapeInput.txt"));
		ArrayList<String> inputLines = new ArrayList<String>();
		int totalLines = 0;
		// find total number of lines
		while (sc.hasNextLine()) {
			totalLines++;
			inputLines.add(sc.nextLine());
		}
		sc.close();
		// store input in char[]
		char[][] maze = new char[totalLines][inputLines.get(0).length()];
		for (int i = 0; i < maze.length; i++) {
			maze[i] = inputLines.get(i).toCharArray();
		}
		// find the U
		Position uPos = new Position(0, 0);
		for (int i = 0; i < maze.length; i++) {
			for (int j = 0; j < maze[0].length; j++) {
				if (maze[i][j] == 'U') {
					uPos = new Position(i, j);
				}
			}
		}
		// Stores if we found a way out
		boolean foundWayOut = false;
		// list of positions that can be reached. It will start at U
		// and slowly spread out.
		Queue<Position> posToCheck = new LinkedList<Position>();
		// list of distances from start, or -1
		int[][] dist = new int[maze.length][maze[0].length];
		for (int i = 0; i < dist.length; i++) {
			for (int j = 0; j < dist[0].length; j++) {
				dist[i][j] = -1;
			}
		}
		posToCheck.add(uPos);
		dist[uPos.row][uPos.col] = 0;
		int minDist = Integer.MAX_VALUE;
		while (!posToCheck.isEmpty()) {
			Position next = posToCheck.poll();
			if (next.row == 0 || next.col == 0 || next.row == maze.length - 1 || next.col == maze[0].length - 1) {
				// this is at the edge, so it is possible!
				foundWayOut = true;
				minDist = dist[next.row][next.col];
			} else {
				int[][] directions = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
				// for each direction, add a position to the list of positions to check only if
				// it is a valid spot in the maze and we have not already added it to the list.
				for (int i = 0; i < directions.length; i++) {
					int row = next.row - directions[i][0];
					int col = next.col - directions[i][1];
					if (maze[row][col] == '.' && dist[row][col] == -1) {
						Position nextSpot = new Position(row, col);
						dist[row][col] = dist[next.row][next.col] + 1;
						posToCheck.add(nextSpot);
					}
				}
			}
		}
		if (foundWayOut) {
			System.out.println("yes");
			System.out.println(minDist);
		} else {
			System.out.println("no");
		}
	}

	public static class Position {
		int row;
		int col;

		public Position(int r, int c) {
			row = r;
			col = c;
		}
	}
}
