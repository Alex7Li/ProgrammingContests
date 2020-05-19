package medium.original;

import java.util.Scanner;
// https://naq19.kattis.com/problems/summertrip
public class SummerTrip {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char [] arr = sc.nextLine().toCharArray();
        int n = arr.length;
        int total = 0, distinct = 0;
        char current;
        for (int i = 0; i < 26; i++){
            boolean [] seen = new boolean [26];
            distinct = 0;
            current = (char)('a' + i);
            seen[i] = true;
            //loop until that char is found.
            int j = 0;
            while (j < n && arr[j] != current) {
                j++;
            }
            int right = j + 1;
            while (right < n) {
                char c = arr[right];
                if (!seen[c - 'a']){
                    distinct++;
                    seen[c - 'a'] = true;
                }
                if(arr[right]==current){
                    total += distinct;
                    seen = new boolean[26];
                    seen[i] = true;
                    distinct = 0;
                }
                right++;
            }
            total += distinct;
        }
        System.out.println(total);
    }

}
