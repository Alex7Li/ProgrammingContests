package other.googlefoobar;

import java.util.Arrays;
import java.util.Comparator;

//https://www.google.com/foobar/?eid=hWxkW9CDJIiCjwSRrYSYAQ&usg=AG3vBD1gNtwOhHU9VNBQBxViJalsYdRo4A
public class ElevatorMaintenance {
    public static void main(String[] args) {
        String[] test = {"1.11", "2.0.0", "1.2", "2", "0.1", "1.2.1", "1.1.1", "2.0","2","2"};
        System.out.println(Arrays.toString(answer(test)));
    }

    public static String[] answer(String[] l) {
        Comparator<String> cs = new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                String[] s1 = o1.split("\\.");
                String[] s2 = o2.split("\\.");
                int majorDiff = Integer.parseInt(s1[0]) - Integer.parseInt(s2[0]);
                if (majorDiff != 0) {
                    return majorDiff;
                }
                if (s1.length == 1 || s2.length == 1) {
                    return s1.length - s2.length;
                }
                int minorDiff = Integer.parseInt(s1[1]) - Integer.parseInt(s2[1]);
                if (minorDiff != 0) {
                    return minorDiff;
                }
                if (s1.length == 2 || s2.length == 2) {
                    return s1.length - s2.length;
                }
                return Integer.parseInt(s1[2])-Integer.parseInt(s2[2]);
            }
        };
        Arrays.sort(l,cs);
        return l;
    }
}
