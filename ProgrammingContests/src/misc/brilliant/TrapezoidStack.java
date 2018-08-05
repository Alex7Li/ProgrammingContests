package misc.brilliant;

//https://brilliant.org/weekly-problems/2018-07-09/intermediate/?p=5
public class TrapezoidStack {
    static boolean[] possible = new boolean[20001];

    public static void main(String[] args) {
        int height = 1;
        int balls = 1;
        while (balls < possible.length) {
            height++;
            balls += height;
            for (int i = balls; i < possible.length; i += height) {
                possible[i] = true;
            }
        }
        for (int i = 0; i < possible.length; i++) {
            if(!possible[i]){
                System.out.println(i);
            }
        }
    }
}
