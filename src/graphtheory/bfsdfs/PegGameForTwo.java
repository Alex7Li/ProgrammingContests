package graphtheory.bfsdfs;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

//https://naq18.kattis.com/
public class PegGameForTwo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] initpegs = new int[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j <= i; j++) {
                initpegs[i][j] = sc.nextInt();
            }
        }
        Position initPos = new Position(0, initpegs, 14);
        System.out.println(initPos.findBest());
    }

    public static class Position {
        int diff;
        int[][] pegs;
        int left;
        int leftF;

        public Position(int d, int[][] pegs, int pegsLeft) {
            this.pegs = pegs;
            diff = d;
            left = pegsLeft;
            leftF = 1;
            if (left % 2 == 1) {
                leftF = -1;
            }
        }

        public List<Position> nextPositions() {
            List<Position> nxtPos = new ArrayList<>();
            for (int i = 0; i < pegs.length; i++) {
                for (int j = 0; j <= i; j++) {
                    if (pegs[i][j] > 0) {
                        if(isHole(i+2,j) && isPeg(i+1,j)){
                            nxtPos.add(makePos(i,j,i+1,j,i+2,j));
                        }
                        if(isHole(i,j+2) && isPeg(i,j+1)){
                            nxtPos.add(makePos(i,j,i,j+1,i,j+2));
                        }
                        if(isHole(i-2,j) && isPeg(i-1,j)){
                            nxtPos.add(makePos(i,j,i-1,j,i-2,j));
                        }
                        if(isHole(i,j-2) && isPeg(i,j-1)){
                            nxtPos.add(makePos(i,j,i,j-1,i,j-2));
                        }
                        if(isHole(i-2,j-2) && isPeg(i-1,j-1)){
                            nxtPos.add(makePos(i,j,i-1,j-1,i-2,j-2));
                        }
                        if(isHole(i+2,j+2) && isPeg(i+1,j+1)){
                            nxtPos.add(makePos(i,j,i+1,j+1,i+2,j+2));
                        }
                    }
                }
            }
            return nxtPos;
        }

        Position makePos(int i1, int j1, int i2, int j2, int i3, int j3) {
            int[][] initPegs = new int[5][5];
            int newDiff = diff + leftF*(pegs[i1][j1] * pegs[i2][j2]);
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    initPegs[i][j] = pegs[i][j];
                }
            }
            initPegs[i3][j3] = pegs[i1][j1];
            initPegs[i1][j1] = 0;
            initPegs[i2][j2] = 0;
            return new Position(newDiff, initPegs, left-1);
        }

        boolean isPeg(int i, int j) {
            return i >= 0 && j >= 0 && i < 5 && j <= i && pegs[i][j] > 0;
        }

        boolean isHole(int i, int j) {
            return i >= 0 && j >= 0 && i < 5 && j <= i && pegs[i][j] == 0;
        }

        int findBest() {
            List<Position> nxtPositions = nextPositions();
            if(nxtPositions.isEmpty()){
                return diff;
            }
            int ans = Integer.MIN_VALUE;
            for (Position nxt : nxtPositions) {
                ans = Math.max(ans, nxt.findWorst());
            }
            return ans;
        }

        int findWorst() {
            List<Position> nxtPositions = nextPositions();
            if(nxtPositions.isEmpty()){
                return diff;
            }
            int ans = Integer.MAX_VALUE;
            for (Position nxt : nxtPositions) {
                ans = Math.min(ans, nxt.findBest());
            }
            return ans;
        }
    }
}
