package other;

import java.util.Arrays;
import java.util.Comparator;

public class MergeSort {
    public static void main(String[] args) {
        Integer[] a = {3, -2,-3,3,123,321,3423,21,2,2,3,3,3,423,324,324,23,2,-332,32,-43,2,-4,-2,34,-23,-3,-3};
        recursiveSort(a, (x, y) -> x - y);
        System.out.println(Arrays.toString(a));
    }

    /**
     * Sort a list recursively in ascending order in O(nlogn) time.
     * comp imposes a total ordering on the set
     **/
    static void recursiveSort(Integer[] elements, Comparator<Integer> comp) {
        rSort(elements, comp, 0, elements.length);
    }

    static void rSort(Integer[] elements, Comparator<Integer> comp, int start, int end) {
        if (end - start > 1) {
            int mid = (start + end) / 2;
            Integer[] result = new Integer[end - start];
            rSort(elements, comp, start, mid);
            rSort(elements, comp, mid, end);
            int p1 = start;
            int p2 = mid;
            for (int i = 0; i < end - start; i++) {
                if (p1 == mid) {
                    result[i] = elements[p2];
                    p2++;
                } else if (p2 == end) {
                    result[i] = elements[p1];
                    p1++;
                } else {
                    if (comp.compare(elements[p1], elements[p2]) > 0) {
                        result[i] = elements[p2];
                        p2++;
                    } else {
                        result[i] = elements[p1];
                        p1++;
                    }

                }
            }
            for (int i = 0; i < result.length; i++) {
                elements[i + start] = result[i];
            }
        }
    }

}
