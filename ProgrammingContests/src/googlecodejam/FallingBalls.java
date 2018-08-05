package googlecodejam;

import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class FallingBalls {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        for (int tc = 1; tc <= t; tc++) {
            int minCol = 1;
            StringBuilder ans = new StringBuilder();
            int C = Integer.parseInt(sc.nextLine());
            int[] nums = Arrays.stream(sc.nextLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
            if (nums[0] == 0 || nums[nums.length - 1] == 0) {
                System.out.println("Case #" + tc + ": IMPOSSIBLE");
                continue;
            }
            nums[0]--;
            nums[nums.length - 1]--;
            char[][] grid = new char[C][C];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    grid[i][j] = '.';
                }
            }
            int holeInd = 0;
            for (int i = 1; i < grid.length-1; i++){
                //update hole ind
                while (nums[holeInd] == 0) {
                    holeInd++;
                }
                nums[holeInd]--;
                //create ramps
                if (holeInd < i) {
                    for (int j = 0; j < i - holeInd; j++) {
                        grid[j][i - j] = '/';
                    }
                    minCol = Math.max(minCol, i - holeInd + 1);
                } else if (holeInd > i) {
                    for (int j = 0; j < holeInd - i; j++) {
                        grid[j][i + j] = '\\';
                    }
                    minCol = Math.max(holeInd - i + 1, minCol);
                }
            }

            System.out.println("Case #" + tc + ": " + minCol);
            for (int i = 0; i < minCol; i++) {
                for (int j = 0; j < grid.length; j++) {
                    ans.append(grid[i][j]);
                }
                ans.append(System.lineSeparator());
            }
            System.out.print(ans);
        }
        sc.close();
    }
}
