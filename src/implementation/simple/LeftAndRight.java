package implementation.simple;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
//https://naq18.kattis.com/problems/leftandright
public class LeftAndRight {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[] commands = br.readLine().toCharArray();
        ArrayList<Integer> rinds = new ArrayList<>();
        for (int i = 0; i < commands.length; i++) {
            if(commands[i]=='R') {
                rinds.add(i+1);
            }
        }
        Queue<Integer> order = new LinkedList<>();
        int start = 0;
        for (int i:rinds) {
            for (int j = i; j > start; j--) {
                order.add(j);
            }
            start = i;
        }
        for (int i = n; i > start; i--) {
            order.add(i);
        }
        while(!order.isEmpty()){
            System.out.println(order.poll());
        }
    }
}
