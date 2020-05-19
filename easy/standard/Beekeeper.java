package easy.standard;

import java.util.Scanner;

//https://open.kattis.com/contests/j47tpb/problems/beekeeper
public class Beekeeper {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        while(n!=0) {
            String best = "";
            int maxPairs = -1;
            for (int i = 0; i < n; i++) {
                String next = sc.nextLine();
                int pairs = 0;
                char[] letters = next.toCharArray();
                char[] vowels = new char[]{'a','e','i','o','u','y'};
                for (int j = 0; j < letters.length-1; j++) {
                    boolean isVowel = false;
                    for (char vowel : vowels) {
                        if (vowel == letters[j]) {
                            isVowel = true;
                        }
                    }
                    if(isVowel && (letters[j]==letters[j+1])){
                        pairs++;
                    }
                    if(pairs>maxPairs){
                        maxPairs = pairs;
                        best = next;
                    }
                }
            }
            System.out.println(best);
            n =Integer.parseInt(sc.nextLine());
        }
    }
}
