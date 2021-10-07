package other.googlefoobar;

import java.util.TreeSet;
//https://codingworksample.io/c/feedback/AVDQWG-F4F
public class CloseHouses {
    public int[] solution(int[] stores, int[] houses) {
        TreeSet<Integer> storeLocations = new TreeSet<>();
        //large constants. Halving so there will be no overflow later,
        //still more than 1,000,000 so it's ok
        storeLocations.add(Integer.MAX_VALUE/2);
        storeLocations.add(Integer.MIN_VALUE/2);
        for (int i = 0; i < stores.length; i++) {
            storeLocations.add(stores[i]);
        }

        int[] closest = new int[houses.length];
        for (int i = 0; i < houses.length; i++) {
            // will not ever return an exception because we added the large
            // constants and know max size of the elements.
            int nxtStore = storeLocations.ceiling(houses[i]);
            int lstStore = storeLocations.floor(houses[i]);
            int nxtDist = nxtStore - houses[i];
            int lstDist = houses[i] - lstStore;
            if (nxtDist >= lstDist) {
                closest[i] = lstStore;
            } else {
                closest[i] = nxtStore;
            }
        }
        return closest;
    }

    public static void main(String[] args) {
        CloseHouses s = new CloseHouses();

    }
}

