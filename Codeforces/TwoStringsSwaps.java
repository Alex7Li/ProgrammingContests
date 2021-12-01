package codeforces;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
////http://codeforces.com/contest/1006/problem/D
public class TwoStringsSwaps {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        char[] a = sc.nextLine().toCharArray();
        char[] b = sc.nextLine().toCharArray();
        int changes = 0;
        for (int i = 0; i < a.length/2; i++) {
            Set<Character> chars = new HashSet<>();
            chars.add(a[i]);
            chars.add(a[a.length-i-1]);
            chars.add(b[i]);
            chars.add(b[a.length-i-1]);
            if(chars.size()==4){
                changes+=2;
            }else if(chars.size()==3){
                if(a[i]==a[a.length-i-1]){
                    changes+=2;
                }else {
                    changes += 1;
                }
            }else if(chars.size()==2){
                int seenai = 1;
                if(a[a.length-i-1]==a[i]){
                    seenai++;
                }
                if(b[i]==a[i]){
                    seenai++;
                }
                if(b[a.length-i-1]==a[i]){
                    seenai++;
                }
                if(seenai!=2){
                    changes+=1;
                }
            }
        }
        if(a.length%2==1){
            if(a[a.length/2]!=b[a.length/2]){
                changes++;
            }
        }
        System.out.println(changes);
    }
}
