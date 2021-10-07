package other.acmclub;

// I made this problem :D
// (It is the first problem I've made, currently the only one)
// http://codeforces.com/gym/241489/problem/C
public class DividingGameTest {
    public static void main(String[] args) {
        DividingGameDP dp = new DividingGameDP();
        DividingGameGreedy greed = new DividingGameGreedy();
        System.out.println((long)(Math.random()*1e15));
        //        long min = 400_000_000_000_000L-1000;
//        for (long i = min; i < min+1000; i++) {
//            System.out.println(i);
//            if (!dp.solve(i).equals(greed.solve(i))) {
//                System.out.println(i);
//            }
//        }
    }
}
