package other;

//proof that monty hall is wrong (or at least, not as right as it seems)
public class MontyHall {
    public static void main(String[] args) {
        int stayWin = 0;
        int switchWin = 0;
        int invalid = 0;
        for (int i = 0; i < 100000; i++) {
            int prize = (int) (Math.random() * 3); // the correct door
            int choice = (int) (Math.random() * 3); // the door you choose
            int opened = (int) (Math.random() * 3); // the door the host opens
            if (opened == prize || opened == choice) {
                invalid++;
            } else if (prize == choice) {
                stayWin++;
            } else {
                switchWin++;
            }
        }
        System.out.println(stayWin + " " + switchWin + " " + invalid);
        System.out.println("P(win|switch) = " + (float) (stayWin) / (stayWin + switchWin));
    }
}
