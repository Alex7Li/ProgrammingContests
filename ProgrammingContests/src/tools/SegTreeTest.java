package tools;

public class SegTreeTest {
    public static void main(String[] args) {
        int n = 249;
        int[] a = new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i] = randInt(-500, 500);
        }
        SegmentTree st = new SegmentTree(a);
        System.out.println(testRandInterval(st, n, a));
        System.out.println(testRandInterval(st, n, a));
        System.out.println(testRandInterval(st, n, a));
        System.out.println(testRandInterval(st, n, a));
        System.out.println(testRandInterval(st, n, a));
        int ind = randInt(0,n);
        a[ind] = randInt(-500, 500);
        st.update(ind, a[ind]);
        st.update(0,n-1);
        ind = randInt(0,n);
        a[ind] = randInt(-500, 500);
        st.update(ind, a[ind]);
        System.out.println(testRandInterval(st, n, a));
        System.out.println(testRandInterval(st, n, a));
        System.out.println(testRandInterval(st, n, a));
        System.out.println(testRandInterval(st, n, a));
        System.out.println(testRandInterval(st, n, a));
    }

    private static int randInt(int min, int max) {
        return (int) (Math.random() * (max - min)) + min;
    }

    private static boolean testRandInterval(SegmentTree st, int n, int[] a) {
        int l = randInt(0, n);
        int r = randInt(0, n);
        long sum = 0;
        for (int i = l; i < r; i++) {
            sum += a[i];
        }
        return sum == st.get(l, r);
    }
}
