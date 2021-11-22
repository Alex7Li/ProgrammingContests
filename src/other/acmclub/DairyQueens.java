package other.acmclub;
/**
 * this class gives the number of ways of placing
 * 
 * @gridSize queens on a @gridSize by @gridSize board
 * under either the "Dairy Queens" rule or the 
 * "Update Chess" rule
 */
public class DairyQueens {
	private static final int gridSize = 8;

	private static int[][] queensCovering = new int[gridSize][gridSize];

	public static void main(String[] args) {
		System.out.println(countQueens(gridSize));
	}

	public static int countQueens(int queenLeft) {
		if (queenLeft == 0) {
			return 1;
		}
		int totalCount = 0;
		int i = gridSize - queenLeft;
		for (int j = 0; j < gridSize; j++) {
			if (queensCovering[i][j] == 0) {
				//to see the result for chess queens, replace the
				//updateDairy method call with a updateChess call.
				updateDairy(i, j, 1);
				totalCount += countQueens(queenLeft - 1);
				updateDairy(i, j, -1);
			}
		}
		return totalCount;
	}

	/**
	 * Updates the grid for the chess queens problem adding: 1 if you are adding a
	 * queen at the spot, -1 if you are removing a queen.
	 */
	@SuppressWarnings("unused")
	private static void updateChess(int x, int y, int adding) {
		for (int i = 0; i < gridSize; i++) {
			queensCovering[i][y] += adding;
		}
		for (int i = 0; i < gridSize; i++) {
			queensCovering[x][i] += adding;
		}
		for (int i = -gridSize; i <= gridSize; i++) {
			int row = x - i;
			int col = y - i;
			if (0 <= row && 0 <= col && row < gridSize & col < gridSize) {
				queensCovering[row][col] += adding;
			}
		}
		for (int i = -gridSize; i <= gridSize; i++) {
			int row = x - i;
			int col = y + i;
			if (0 <= row && 0 <= col && row < gridSize & col < gridSize) {
				queensCovering[row][col] += adding;
			}
		}
		// we will count the space the queen is at once in each method
		// so we must un-count the space 3 times, since we counted it 4 times
		queensCovering[x][y] -= (adding * 3);
	}

	/**
	 * Updates the grid for the dairy queens problem adding: 1 if you are adding a
	 * queen at the spot, -1 if you are removing a queen.
	 */
	private static void updateDairy(int x, int y, int adding) {
		for (int i = 0; i <gridSize; i++) {
			queensCovering[i][y] += adding;
		}
		for (int i = 0; i < gridSize; i++) {
			queensCovering[x][i] += adding;
		}
		// we doublecount the space the queen is at once in each method
		queensCovering[x][y] -= adding;
		// So basically, we will consider the 7 by 7 rectangle around the queen.
		// For any space that is under 4 squares away, we update it, unless it
		// is a space that is covered by the horizontal or vertical movement,
		// as we have already accounted for that.
		for (int i = x - 3; i <= x + 3; i++) {
			//i!=x is because we don't want to double count
			if (i >= 0 && i < gridSize && i != x) {
				for (int j = y - 3; j <= y + 3; j++) {
					if (j >= 0 && j < gridSize && j != y) {
						if (Math.abs(j - y) + Math.abs(i - x) < 4) {
							queensCovering[i][j]+=adding;
						}
					}
				}
			}
		}
	}
}
