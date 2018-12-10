package kattis;

import java.util.Scanner;
//https://naq18.kattis.com/
public class RunLengthEncodingRun {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] encode = sc.next().toCharArray();
        char[] msg = sc.nextLine().toCharArray();
        if(encode[0] == 'E'){
            int len = 1;
            for(int i = 1; i<msg.length; i++){
                if(i<msg.length-1 && msg[i] == msg[i+1]){
                    len++;
                }else{
                    System.out.print(msg[i]+""+len);
                    len = 1;
                }
            }
        }else{
            for(int i = 1; i<msg.length; i+=2){
                for(int j = 1; j<=msg[i+1]-'0'; j++){
                    System.out.print(msg[i]);
                }
            }
        }
    }
}
