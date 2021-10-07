package core.string.implementation;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

// https://codeforces.com/gym/100299
public class WhatDoesTheFoxSay {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        for (int test = 0; test < t; test++) {
            String[] sounds = sc.nextLine().split(" ");
            Set<String> soundSet = new HashSet<>();
            String[] nl = sc.nextLine().split(" ");
            while(!nl[1].equals("does")){
                soundSet.add(nl[2]);
                nl = sc.nextLine().split(" ");
            }
            StringBuilder says = new StringBuilder();
            boolean first = true;
            for (int i = 0; i < sounds.length; i++) {
                if(!soundSet.contains(sounds[i])){
                    if(!first){
                        says.append(" ");
                    }
                    says.append(sounds[i]);
                    first = false;
                }
            }
            System.out.println(says);
        }
        sc.close();
    }
}
