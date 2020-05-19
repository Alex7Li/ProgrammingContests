package easy.original;

import java.util.Scanner;
import java.util.Stack;
//https://naq19.kattis.com/problems/circuitmath
public class CircuitMath {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        boolean[] inputs = new boolean[n];
        for (int i = 0; i < n; i++) {
            inputs[i] = sc.next().charAt(0) == 'T';
        }
        sc.nextLine();
        String[] line = sc.nextLine().split(" ");
        char[] expr = new char[line.length];
        for(int i=0; i< line.length; i++){
            expr[i] = line[i].charAt(0);
        }

        Stack<Character> st = new Stack<>();
        boolean a, b;
        for (char c : expr) {
            switch (c){
                case '+':
                    a = val(st.pop(), inputs);
                    b = val(st.pop(), inputs);
                    st.push(a || b ? 'T': 'F');
                    break;
                case '-':
                    a = val(st.pop(), inputs);
                    st.push(!a ? 'T': 'F');
                    break;
                case '*':
                    a = val(st.pop(), inputs);
                    b = val(st.pop(), inputs);
                    st.push(a && b ? 'T': 'F');
                    break;
                default:
                    st.push(val(c, inputs)? 'T' : 'F');
            }
        }
        System.out.println(st.pop());
    }

    static boolean val(Character c, boolean[] givens){
        if ( c== 'F'){
            return false;
        } else if (c == 'T'){
            return true;
        } else {
            return givens[c - 'A'];
        }
    }
}
