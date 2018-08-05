package atcoder;

import java.util.ArrayList;
import java.util.Scanner;
//https://practice.contest.atcoder.jp/tasks/practice_2
public class InteractiveSorting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Character> sortedList = new ArrayList<>();
        sortedList.add('A');
        for (char i = 'B'; (int)(i) != n+'A'; i++) {
            int bigEnough = i - 'A';
            int smallEnough = 0;
            while (smallEnough != bigEnough) {
                int mid = (smallEnough + bigEnough) / 2;
                System.out.println("? " + i + " " + sortedList.get(mid));
                System.out.flush();
                if (sc.next().equals("<")) {
                    bigEnough = mid;
                } else {
                    smallEnough = mid + 1;
                }
            }
            sortedList.add(smallEnough,i);
        }
        System.out.print("! ");
        for (char i : sortedList) {
            System.out.print(i);
        }
        System.out.println();
    }
}
