package tools;

public class PrimeSieve {
    public static void main(String[] args) {
        int n = 10000;
        boolean[] isComposite = new boolean[n + 1];
        for (int i = 2; i * i <= n; i++) {
            if (!isComposite[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isComposite[j] = true;
                }
            }
        }

        for (int i = 2; i < isComposite.length; i++) {
            if (!isComposite[i]) {
                System.out.print(i + " ");
            }
        }
    }
}
