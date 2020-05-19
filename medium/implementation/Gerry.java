package medium.implementation;

import java.util.Scanner;
//https://naq19.kattis.com/problems/gerrymandering
public class Gerry {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int precincts = sc.nextInt();
        int districts = sc.nextInt();
        int [][] votes = new int[districts][2];
        int totalVotes = 0;
        int wastedA = 0;
        int wastedB = 0;
        for (int i = 0; i < precincts; i++){
            int d = sc.nextInt();
            votes[d - 1][0] += sc.nextInt();
            votes[d - 1][1] += sc.nextInt();

        }

        for (int i = 0; i < districts; i++) {
            int total = votes[i][0] + votes[i][1];
            int half = total /2 + 1;
            int wA, wB;
            if (votes[i][0] > votes[i][1]) {
                wA = votes[i][0] - half;
                wB = votes[i][1];
                System.out.println("A " + wA + " " + wB);
                wastedA += wA;
                wastedB += wB;
            } else {
                wA = votes[i][0];
                wB = votes[i][1] - half;
                wastedA += wA;
                wastedB += wB;
                System.out.println("B " + wA + " " + wB);
            }

            totalVotes += total;
        }
        double eff = (double)(Math.abs(wastedA - wastedB))/totalVotes;
        System.out.println(eff);
    }
}
