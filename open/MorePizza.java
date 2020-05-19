package open;

import java.io.*;
import java.util.*;
import java.lang.*;
// Google Hash Code practice problem 2020
// This actually solves it perfectly on the given test cases :P
class MorePizza {
    static int n;
    static int M;

    public static class IndAndVal {
        int ind;
        int val;

        public IndAndVal(int index, int value) {
            ind = index;
            val = value;
        }
    }

    public static PizzaSolution twoPointers(int[] a) {
        ArrayList<IndAndVal> list = new ArrayList<IndAndVal>();
        for (int i = 0; i < n; i++) {
            list.add(new IndAndVal(i, a[i]));
        }
        Collections.shuffle(list);

        int head = 1; // exclusive upper bound
        int tail = 0;
        int sum = list.get(0).val;
        int bestHead = 1;
        int bestTail = 0;
        int bestSum = sum;

        while (head < list.size()) {
            sum += list.get(head).val;
            head++;
            while (sum > M) {
                sum -= list.get(tail).val;
                tail++;
            }
            if (sum > bestSum) {
                bestSum = sum;
                bestHead = head;
                bestTail = tail;
            }
        }
        Set<Integer> pizzaInds = new HashSet<Integer>();
        for (int i = bestTail; i < bestHead; i++) {
            pizzaInds.add(list.get(i).ind);
        }
        return new PizzaSolution(pizzaInds, bestSum);
    }

    public static class PizzaSolution {
        Collection<Integer> pizzaIndicies;
        int slices;

        public PizzaSolution(Collection<Integer> pizInds, int NSlices) {
            pizzaIndicies = pizInds;
            slices = NSlices;
        }

        public String toString() {
            StringBuilder ans = new StringBuilder(pizzaIndicies.size() + "\n");
            for (int pi : pizzaIndicies) {
                ans.append(pi).append(" ");
            }
            return ans.toString();
        }
    }

    public static PizzaSolution bestSolution(PizzaSolution a, PizzaSolution b) {
        assert (a.slices <= M && b.slices <= M);
        return a.slices > b.slices ? a : b;
    }

    public static String solve(BufferedReader br) throws IOException {
        String[] line = br.readLine().split(" ");
        M = Integer.parseInt(line[0]);
        n = Integer.parseInt(line[1]);
        int[] a = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        PizzaSolution best = twoPointers(a);
        for (int i = 0; i < 100; i++) {
            best = bestSolution(best, twoPointers(a));
        }
        return best.toString();
    }
    public static void runOne(File infile, File outfile) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(infile));
        PrintWriter out = new PrintWriter(outfile);
        out.println(solve(in));
        out.flush();
        out.close();
        in.close();
    }

    public static void Main(String[] args) throws IOException {
        runOne(new File("in/a.in"), new File("out/a.out"));
        runOne(new File("in/b.in"), new File("out/b.out"));
        runOne(new File("in/c.in"), new File("out/c.out"));
        runOne(new File("in/d.in"), new File("out/d.out"));
        runOne(new File("in/e.in"), new File("out/e.out"));
    }
}
