package easy.original;

import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Scanner;
// https://open.kattis.com/contests/j47tpb/problems/beekeeper
public class Backspace {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        char[] typed = sc.nextLine().toCharArray();
        ArrayDeque<Character> stack = new ArrayDeque<Character>();
        for (int i = 0; i < typed.length; i++) {
            if(typed[i] =='<') {
                stack.removeLast();
            }else {
                stack.addLast(typed[i]);
            }
        }
        PrintWriter pw = new PrintWriter(System.out);
        while(!stack.isEmpty()) {
            pw.print(stack.removeFirst());
        }
        pw.println();
        pw.flush();
    }
}
