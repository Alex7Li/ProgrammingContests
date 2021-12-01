package codeforces;

import java.io.*;
import java.util.*;

//http://codeforces.com/contest/1014
public class _Marathon_ColoredPath {
    BufferedReader br;
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private int patternLength;
    private int nStowedBottles;
    private int nColors;
    private int nHeldBottles;
    private int nChameleon;
    private List<Integer>[] colorInds;
    private Set<Integer> occupiedPositions;
    private List<Chameleon> chameleons;
    private Map<Integer, Integer> heldBottles;
    boolean testing = true;
    private char[] stripePattern;

    public void solve() throws IOException {
        if (testing) {
            br = new BufferedReader(new FileReader("Marathon_ColoredPathInput.txt"));

        } else {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        int[] startingParams = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        patternLength = startingParams[0];
        nStowedBottles = startingParams[1];
        nColors = startingParams[2];
        nHeldBottles = startingParams[3];
        nChameleon = startingParams[4];
        stripePattern = br.readLine().toCharArray();
        char[] bottleChar = br.readLine().toCharArray();
        int[] bottles = new int[nStowedBottles + nHeldBottles];
        for (int i = 0; i < bottleChar.length; i++) {
            bottles[i] = bottleChar[i] - 'A';
        }
        heldBottles = new HashMap<>();
        for (int i = 0; i < nHeldBottles; i++) {
            heldBottles.put(bottles[i], heldBottles.getOrDefault(bottles[i], 0) + 1);
        }
        int nextBottleInd = nHeldBottles;
        colorInds = new ArrayList[nColors];
        for (int i = 0; i < nColors; i++) {
            colorInds[i] = new ArrayList<>();
        }
        for (int i = 0; i < stripePattern.length; i++) {
            int c = stripePattern[i] - 'A';
            colorInds[c].add(i);
        }
        //place chameleons
        occupiedPositions = new HashSet<>();
        chameleons = new ArrayList<>();
        for (int i = 0; i < nChameleon; i++) {
            occupiedPositions.add(i);
            chameleons.add(new Chameleon(i));
        }
        while (nextBottleInd < nStowedBottles + nHeldBottles) {
            Chameleon bestCha = chameleons.get(0);
            double bestColorVal = -100000;
            int bestColor = -1;
            double[] colorPower = new double[nColors];
            for (int i = 0; i < colorPower.length; i++) {
                if (heldBottles.containsKey(i)) {
                    Double[] pow = new Double[nChameleon];
                    for (int j = 0; j < nChameleon; j++) {
                        pow[j] = 0.0 + chameleons.get(j).nextOpenSkipN(i, 0) - chameleons.get(j).curInd;
                        if(heldBottles.get(i)>1) {
                            pow[j] += .5*(chameleons.get(j).nextOpenSkipN(i, 1) - chameleons.get(j).nextOpenSkipN(i, 0));
                        }
                        if(heldBottles.get(i)>2){
                            pow[j] += .4*(chameleons.get(j).nextOpenSkipN(i, 2) - chameleons.get(j).nextOpenSkipN(i, 1));
                        }
                    }
                    Arrays.sort(pow, Collections.reverseOrder());
                    for (int j = 0; j < 10; j++) {
                        colorPower[i] += pow[j];
                    }
                    colorPower[i] /= 10;
                }
            }
            for (int i = 0; i < nChameleon - 1; i++) {
                Chameleon curCha = chameleons.get(i);
                double bestColorValThis = -100000;
                int bestColorThis = -1;
                //reduce weight based on how helpful the chamelion is being currently
                double chaHelp = curCha.helpfulness(curCha.curInd, colorPower[i])/5;
                for (int color : heldBottles.keySet()) {
                    int closestColorJ = curCha.nextOpenSkipN(color, 0);
                    double netGood = closestColorJ - curCha.curInd - colorPower[i]/5;
                    //see how much early chamelons would benefit from sending this one
                    netGood += curCha.helpfulness(closestColorJ, colorPower[i])/5;
                    if (bestColorValThis < netGood - chaHelp) {
                        bestColorValThis = netGood - chaHelp;
                        bestColorThis = color;
                    }
                }
                if (bestColorValThis > bestColorVal) {
                    bestColor = bestColorThis;
                    bestColorVal = bestColorValThis;
                    bestCha = curCha;
                }
                if (bestColorValThis + curCha.curInd < chameleons.get(i + 1).curInd) {
                    i = nChameleon;
                }
            }
            bestCha.throwBottle(bestColor, bottles[nextBottleInd]);
            nextBottleInd++;
        }
        bw.flush();
        long t = System.currentTimeMillis();
        while (System.currentTimeMillis() - t < 10) {

        }
        System.err.println(chameleons.get(0).curInd);
        System.err.println(chameleons.get(chameleons.size() - 1).curInd);
    }


    public class Chameleon {
        int ind;
        int curInd;
        int[] colorIndInd;

        public Chameleon(int curInd) {
            this.ind = curInd;
            this.curInd = curInd;
            colorIndInd = new int[colorInds.length];
            calcColorIndInd();
        }

        public void calcColorIndInd() {
            for (int i = 0; i < colorInds.length; i++) {
                while (colorInds[i].get(colorIndInd[i]) <= curInd) {
                    colorIndInd[i]++;
                }
            }
        }

        //from this chameleon, return the n-1th next open color of color color.
        public int nextOpenSkipN(int color, int n) {
            for (int i = 0; i <= n; i++) {//ignore other chameleons
                if (occupiedPositions.contains(colorInds[color].get(this.colorIndInd[color] + i))) {
                    n++;
                }
            }
            return colorInds[color].get(this.colorIndInd[color] + n);
        }

        //from this chameleon, return the n-1th next color of color color.
        public int nextColorSkipN(int color, int n) {
            return colorInds[color].get(this.colorIndInd[color] + n);
        }

        //estimate how helpful a chamelion is being when at location loc
        public double helpfulness(int loc, double basePow) {
            basePow=Math.max(basePow,15);
            int color = stripePattern[loc] - 'A';
            Double[] benefits = new Double[nChameleon];
            for (int j = 0; j < nChameleon; j++) {
                Chameleon earlierCha = chameleons.get(j);
                if (earlierCha == this) {
                    benefits[j] = 0.0;
                    continue;
                }
                // calculate their position with chamelion at loc and without
                int n = 0;
                int newPosWith = colorInds[color].get(earlierCha.colorIndInd[color]);
                int newPosWithout = newPosWith;
                for (int i = 0; i <= n; i++) {//ignore other chameleons
                    int ind = colorInds[color].get(earlierCha.colorIndInd[color] + i);
                    if (occupiedPositions.contains(ind) && ind != this.curInd) {
                        n++;
                    } else if (ind == loc) {
                        n++;
                        newPosWithout = ind;
                    }
                }
                newPosWith = colorInds[color].get(earlierCha.colorIndInd[color] + n);
                benefits[j] = newPosWith - newPosWithout + 0.0;
            }
            Arrays.sort(benefits, Collections.reverseOrder());
            int netGood = 0;
            for (int j = 0; j < 10; j++) {
                netGood += Math.max(Math.pow(benefits[j] - basePow, 1.5), 0);
            }
            return netGood/10;
        }

        public void throwBottle(int color, int replaceColor) throws IOException {
            occupiedPositions.remove(this.curInd);
            bw.write(this.ind + " " + (char) ('A' + color));
            bw.newLine();
            this.curInd = this.nextOpenSkipN(color, 0);
            this.calcColorIndInd();
            occupiedPositions.add(this.curInd);
            chameleons.remove(this);
            if (this.curInd > chameleons.get(chameleons.size() - 1).curInd) {
                chameleons.add(this);
            } else {
                for (int j = 0; j < chameleons.size(); j++) {
                    if (this.curInd < chameleons.get(j).curInd) {
                        chameleons.add(j, this);
                        break;
                    }
                }
            }
            // update heldBottles
            if (heldBottles.get(color) == 1) {
                heldBottles.remove(color);
            } else {
                heldBottles.put(color, heldBottles.get(color) - 1);
            }
            heldBottles.put(replaceColor, heldBottles.getOrDefault(replaceColor, 0) + 1);
        }

    }


    public static void main(String[] args) throws IOException {
        new _Marathon_ColoredPath().solve();
    }
}
