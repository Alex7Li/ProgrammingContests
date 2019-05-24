package misc.marathon;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
// https://codingcompetitions.withgoogle.com/hashcode/archive
// it's not in the archive, but it was the practice problem for the round.
class Pizza {

    // point-to-rectangle mapping
    public static Rectangle[][] rectangleOfPoint;
    public static List<Rectangle> rectangles;
    static int[][] cumulativeGrid;
    static int rows;
    static int cols;
    static int minIngredient;
    static int maxCells;
    static boolean[][] grid;

    private static class Rectangle {
        public int startCol;
        public int endCol;
        public int startRow;
        public int endRow;

        public Rectangle(int sRow, int eRow, int sCol, int eCol) {
            this.startCol = sCol;
            this.endCol = eCol;
            this.startRow = sRow;
            this.endRow = eRow;
        }

        @Override
        public String toString() {
            return this.startRow + " " + this.startCol + " " + this.endRow + " " + this.endCol;
        }

        /**
         * clears <Rectangleofpoint> of squares taken by <this>
         * removes <this> from <rectangles>
         */
        public void removeRectangle() {

            for (int i = this.startRow; i <= this.endRow; i++) {
                for (int j = this.startCol; j <= this.endCol; j++) {
                    rectangleOfPoint[i][j] = null;
                }
            }
            rectangles.remove(this);

        }

        /*
         * return the size of the rectangle
         */
        public int size() {
            int height = endCol - startCol + 1;
            int width = endRow - startRow + 1;
            return height * width;

        }

        /**
         * Count the number of mushrooms in this rectangle
         **/
        public int countShrooms() {
            return cumulativeGrid[endRow + 1][endCol + 1]
                    - cumulativeGrid[endRow + 1][startCol]
                    - cumulativeGrid[startRow][endCol + 1]
                    + cumulativeGrid[startRow][startCol];
        }

        /**
         * Returns true if r has occupies any squares of *this
         */
        public boolean overlap(Rectangle r) {
            return ((this.startRow <= r.startRow && r.startRow <= this.endRow) ||
                    (r.startRow <= this.startRow && this.startRow <= r.endRow) &&
                            (this.startCol <= r.startCol && r.startCol <= this.endCol) ||
                    (r.startCol <= this.startCol && this.startCol <= r.endCol));

        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("C:\\Users\\7Alex\\IdeaProjects\\ProgrammingContests\\ProgrammingContests\\resources\\d_big.in"));
        System.out.println("Hello");
        System.out.println("Running:");
        rectangles = new ArrayList<Rectangle>();
        rows = sc.nextInt();
        cols = sc.nextInt();
        rectangleOfPoint = new Rectangle[rows][cols];
        minIngredient = sc.nextInt();
        maxCells = sc.nextInt();
        sc.nextLine();
        grid = new boolean[rows][cols];
        for (int i = 0; i < rows; i++) {
            char[] nl = sc.nextLine().toCharArray();
            for (int j = 0; j < cols; j++) {
                grid[i][j] = nl[j] == 'M';
            }
        }

        // Initialize a grid of sub-counts of mushrooms
        cumulativeGrid = new int[rows + 1][cols + 1];
        for (int j = 0; j < cols; j++) {
            cumulativeGrid[0][j] = 0;
        }
        for (int i = 1; i <= rows; i++) {
            cumulativeGrid[i][0] = 0;
            int rowTotal = 0;
            for (int j = 1; j <= cols; j++) {
                if (grid[i - 1][j - 1]) {
                    rowTotal++;
                }
                cumulativeGrid[i][j] = cumulativeGrid[i - 1][j] + rowTotal;
            }
        }

        alg2();

        printOutput();
        sc.close();
    }


    /**
     * Place the rectangles using the first part of Rushil's algorithm
     **/
    private static void placeRectangles() {
        for (int i = 0; i < rows; i++) {
            int j = 0;
            while (j < cols) {
                // Numbers of each topping in currently considered block
                int curTomato = 0;
                int curMushroom = 0;
                int curLen = 0;
                while (j < cols) {
                    // give up on the leftmost part of the currently considered slice
                    if (curLen == maxCells) {
                        if (grid[i][j - maxCells]) {
                            curMushroom--;
                        } else {
                            curTomato--;
                        }
                    }
                    if (grid[i][j]) {
                        curMushroom++;
                    } else {
                        curTomato++;
                    }
                    if (curMushroom >= minIngredient && curLen >= minIngredient) {
                        //make the rectangle
                        Rectangle r = new Rectangle(i, i, j - curLen, j);
                        placeRectangle(r);
                        j++;
                        break;
                    }
                    j++;
                    curLen++;
                }
            }
        }
    }

    /**
     * Update the grid to place a rectangle
     */
    private static void placeRectangle(Rectangle rect) {
        for (int i = rect.startRow; i <= rect.endRow; i++) {
            for (int j = rect.startCol; j <= rect.endCol; j++) {
                if (rectangleOfPoint[i][j] != null) {
                    System.out.println("error in build rectangle, rectangle overwrite");
                } else {
                    rectangleOfPoint[i][j] = rect;

                }
            }
        }
        rectangles.add(rect);

    }

    /**
     * for printing output
     *
     * @throws FileNotFoundException
     */
    private static void printOutput() throws FileNotFoundException {
        PrintWriter out = new PrintWriter(new File("output.txt"));
        out.println(rectangles.size());
        for (int i = 0; i < rectangles.size(); i++) {
            out.println(rectangles.get(i).toString());
        }
        out.close();
    }

    // fOr deBUgGInG, cOnNoR
    private static void printArr(boolean[][] b) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }
    }

    private static void alg2() {
        // bestUsed[i] is the highest number of cells that
        // can be used if we only use the first i rows.
        int[] bestUsed = new int[rows + 1];
        List<Rectangle>[] bestRects = new LinkedList[rows + 1];
        for (int i = 0; i < bestRects.length; i++) {
            bestRects[i] = new LinkedList<>();
        }

        for (int startRow = 0; startRow < rows; startRow++) {
            for (int endRow = startRow; endRow < Math.min(startRow + maxCells, rows); endRow++) {
                int cellsUsed = 0;
                List<Rectangle> currentRow = new LinkedList<>();
                int stCol = 0;
                int maxWidth = maxCells / (endRow - startRow + 1);
                while (stCol < cols) {
                    int endCol = Math.min(rows-1,stCol + maxWidth - 1);
                    while (endCol - stCol < maxWidth && endCol < cols) {
                        Rectangle curRect = new Rectangle(startRow, endRow, stCol, endCol);
                        int numShrooms = curRect.countShrooms();

                        if (numShrooms >= minIngredient &&(curRect.size() - numShrooms) >= minIngredient) {
                            currentRow.add(curRect);
                            cellsUsed += curRect.size();
                            stCol = endCol;
                            break;
                        }
                        if (endCol - stCol == maxWidth) {
                            stCol++;
                        } else {
                            endCol++;
                        }
                    }
                    stCol++;
                }

                // update DP table
                if (bestUsed[endRow + 1] < bestUsed[startRow] + cellsUsed) {
                    bestUsed[endRow + 1] = bestUsed[startRow] + cellsUsed;
                    bestRects[endRow + 1] = currentRow;
                    currentRow.addAll(bestRects[startRow]);
                    System.out.println(endRow-startRow+1);
                }
            }
        }
        for (Rectangle rect : bestRects[rows]) {
            placeRectangle(rect);
        }
    }

    public static void printGrid() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Rectangle r = rectangleOfPoint[i][j];
                char topping = grid[i][j] ? 'M' : 'T';
                int hash = 0;
                if (r != null) {
                    hash = r.hashCode() % 256;
                }
                System.out.print(String.format("%c-%02X ", topping, hash));
            }
            System.out.println();
        }
    }


}