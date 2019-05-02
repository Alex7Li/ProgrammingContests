package googlecodejam;

import java.util.Scanner;

//https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881da
class YouCanGoYourOwnWay {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int cases = Integer.parseInt(sc.nextLine());
        for (int i = 1; i <= cases; i++) {
            sc.nextLine();
            char[] a = sc.nextLine().toCharArray();
            StringBuilder out = new StringBuilder();
            for (int j = 0; j < a.length; j++) {
                out.append(a[j]=='S'?'E':'S');
            }
            System.out.println("Case #" + i + ": " + out);
        }
    }
}
