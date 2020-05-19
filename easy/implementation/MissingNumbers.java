package easy.implementation;

import java.util.Scanner;
import java.util.TreeSet;
//
public class MissingNumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            max = Math.max(a[i], i);
        }
        TreeSet<Integer> numbers = new TreeSet<>();
        for (int i = 1; i <= max; i++) {
            numbers.add(i);
        }
        for (int value : a) {
            numbers.remove(value);
        }
        if(numbers.isEmpty()){
            System.out.println("good job");
        }else{
            for (int x:
                 numbers) {
                System.out.println(x);
            }
        }
    }
}
