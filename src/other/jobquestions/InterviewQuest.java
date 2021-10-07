package other.jobquestions;

import java.util.Scanner;

//Interview for Symantec 10/25/2018
public class InterviewQuest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter n: ");
        int n = sc.nextInt();
        sc.close();
        boolean[] isComposite = new boolean[n+1];

        for (int i = 2; i*i <= n; i++) {
            if (!isComposite[i]) {
                for (int j = i*i; j <= n; j+=i) {
                    isComposite[j] = true;
                }
            }
        }

        for (int i = 2; i < isComposite.length; i++) {
            if(!isComposite[i]){
                System.out.print(i + " ");
            }
        }
    }
}
