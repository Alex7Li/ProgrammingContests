package acmclub;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// I made this problem :D
// (It is the first problem I've made, currently the only one)
// http://codeforces.com/gym/241489/problem/C
public class DividingGameGreedy {
    public String solve(long n) {
        List<Long> primes = primeFactors(n);
        if(primes.size()==1){
            return "Lose";
        }
        int diff = 0;
        boolean yourTurn = true;
        long curNum = 1;
        while (n != 1) {
            // first condition ensures no overflow
            while (curNum <= Integer.MAX_VALUE && curNum * curNum < n) {
                curNum *= primes.remove(primes.size() - 1);
                if (yourTurn) {
                    diff++;
                } else {
                    diff--;
                }
            }
            n /= curNum;
            curNum = 1;
            yourTurn = !yourTurn;
        }
        if (diff > 0) {
            return "Lose";
        } else if (diff == 0) {
            return "Tie";
        } else {
            return "Win";
        }
    }

    /**
     * Given an integer n>1, you and a friend play a game.
     * Each take turn dividing the number by one greater than or equal to
     * the square root of the current number. On the ith number,
     * divide out a_i. The sequence a_i must be non-increasing.
     * You win if you divide by less primes than the opponent or
     * divide by the same amount and make the last move
     * n <= 10^18
     * This solution will give the wrong answers on some large cases.
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        sc.close();
        System.out.println(new DividingGameGreedy().solve(n));
    }

    // returns a list, sorted in ascending order, of
    // all the prime factors of a number
    private static List<Long> primeFactors(long n) {
        List<Long> primes = new ArrayList<>();
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                primes.add(i);
                n /= i;
                i--;
            }
        }
        if (n != 1) {
            primes.add(n);
        }
        return primes;
    }
}

