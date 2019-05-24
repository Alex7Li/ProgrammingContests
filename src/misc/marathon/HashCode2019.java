package misc.marathon;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;
// https://codingcompetitions.withgoogle.com/hashcode/archive
class HashCode2019 {

    /**
     * provides an orientation enum for the Node object
     */
    enum Orientation {
        H, V;
    }

    /**
     * stores all the tags in the file, maps the strings to numbers
     */
    static HashMap<String, Integer> tagMapInt;
    /**
     * Given a tag, which photos have it?
     */
    static List<List<Node>> nodesWithTag;

    static List<Node> verticalNodes;
    /**
     * Stores all of the nodes.
     */
    static List<Node> nodeList;
    /**
     * Stores the total number of tags.
     */
    static int tagID;
    /**
     * Stores the total number of photos (nodes).
     */
    static int photoID;

    static class Photo {
        Orientation o;
        List<Integer> tags;
        int photoIndex;

        Photo(Orientation o, List<Integer> tags) {
            this.photoIndex = photoID;
            photoID++;
            this.o = o;
            this.tags = tags;
        }
    }

    static class Node {
        Orientation o;
        Photo photo1;
        private Photo photo2;
        List<Integer> tagUnion;

        Node next;
        Node prev;

        Node(Photo p1) {
            o = Orientation.H;
            this.photo1 = p1;
            this.photo2 = null;
        }

        Node(Photo p1, Photo p2) {
            o = Orientation.V;
            this.photo1 = p1;
            this.photo2 = p2;

        }

        public List<Integer> tags() {
            if (this.photo2 == null) {
                return this.photo1.tags;
            }
            if (tagUnion == null) {
                tagUnion = mergeList(this.photo1.tags, this.photo2.tags);
            }
            return tagUnion;
        }

        public String toString() {
            if (o == Orientation.V) {
                return String.format("%d %d", photo1.photoIndex, photo2.photoIndex);
            } else {
                return String.format("%d", photo1.photoIndex);
            }
        }

        public void swap(Node a, int tIsFirst, int aIsFirst) {
            assert this.o == Orientation.V;
            assert a.o == Orientation.V;
            Photo pt;
            Photo pa;
            if (tIsFirst != 0) {
                pt = this.photo1;
            } else {
                pt = this.photo2;
                tagUnion = null;
            }
            if (aIsFirst != 0) {
                pa = a.photo1;
                a.photo1 = pt;
            } else {
                pa = a.photo2;
                a.photo2 = pt;
                a.tagUnion = null;
            }
            if (tIsFirst != 0) {
                this.photo1 = pa;
            } else {
                this.photo2 = pa;
                tagUnion = null;
            }

        }
    }

    //merge two sorted lists representing sets into a new sorted list
    public static List<Integer> mergeList(List<Integer> a, List<Integer> b) {
        List<Integer> result = new LinkedList<Integer>();
        int p2Index = 0;

        for (int element : a) {
            // add the stuff below a
            for (; p2Index < b.size() && element > b.get(p2Index); p2Index++) {
                result.add(b.get(p2Index));
            }

            // add a
            result.add(element);
            if (p2Index < b.size() && element == b.get(p2Index)) {
                p2Index++;
            }
        }

        // add the stuff larger than any element of a
        for (; p2Index < b.size(); p2Index++) {
            result.add(b.get(p2Index));
        }

        return result;
    }

    // sets up the linked list of nodes given an array list
    public static void setUpDatList(List<Node> order) {
        int n = order.size();
        for (int i = 0; i < order.size(); i++) {
            order.get(i).next = order.get((i + 1) % n);
            order.get(i).prev = order.get((n + i - 1) % n);
        }
    }

    //Splits the linked list into an arraylist of notes in the best way,
    // then prints out the result
    public static void printList(PrintWriter out, Node v, int size) {
        int min = Integer.MAX_VALUE;
        int minIndex = 0;
        for (int i = 0; i < size; i++) {
            int score = calcScore(v, v.next);
            if (score < min) {
                min = score;
                minIndex = i;
            }
            v = v.next;
        }
        for (int i = 0; i <= minIndex; i++) {

            v = v.next;
        }
        printScoreToConsole(v, size);
        out.println(size);
        for (int i = 0; i < size; i++) {
            out.println(v.toString());
            v = v.next;
        }
    }

    public static void printScoreToConsole(Node v, int size) {
        int score = 0;
        for (int i = 0; i < size - 1; i++) {
            score += calcScore(v, v.next);
            v = v.next;
        }
        System.out.println("Score: " + score);
    }


    public static int[] improvement2(Node a, Node b) {
        assert a.o == Orientation.V;
        assert b.o == Orientation.V;
        int oldScore = calcScore(a, a.next) + calcScore(a.prev, a) + calcScore(b, b.next) + calcScore(b, b.prev);
        //swap a2 and b1
        int aBest = 1;
        int bBest = 1;
        int curA = 1;
        int curB = 1;
        int newScore = -1;
        for (int i = 0; i < 2; i++) {
            curA = 1 - curA;
            for (int j = 0; j < 2; j++) {
                curB = 1 - curB;
                a.swap(b, curA, curB);
                int tempNewScore = calcScore(a, a.next) + calcScore(a.prev, a) + calcScore(b, b.next) + calcScore(b, b.prev);
                if (tempNewScore > newScore) {
                    newScore = tempNewScore;
                    aBest = curA;
                    bBest = curB;
                }
                a.swap(b, curA, curB);
            }
        }
        return new int[]{newScore - oldScore, aBest, bBest};
    }


    // calculate the improvement that will be obtained by calling merge
    public static int improvement(Node a, Node b) {
        int oldScore = calcScore(a.prev, a) + calcScore(a, a.next) + calcScore(b, b.next);
        int newScore = calcScore(a.prev, a.next) + calcScore(b, a) + calcScore(a, b.next);
        return newScore - oldScore;
    }

    // merge 2 nodes that are sufficient far apart
    public static void merge(Node a, Node b) {
        /*
         * The left-to-right order is the original order.
         * The arrow order is the final order:
         *
         *                   v---<---<---<---<--v
         *  ... -> o -> o -> LimitedInsertion   o -> o -> o -> B    o -> o -> ...
         *              ^    ^---^>--->--->--->-->---^
         *              ^---->---^
         */
        a.prev.next = a.next;
        a.next.prev = a.prev;

        a.next = b.next;
        b.next.prev = a;

        b.next = a;
        a.prev = b;
    }


    //calculate the added coolness of this edge
    public static int calcScore(Node a, Node b) {
        List<Integer> aTags = a.tags();
        List<Integer> bTags = b.tags();
        int unionSize = mergeList(aTags, bTags).size();
        int aSize = aTags.size();
        int bSize = bTags.size();
        int intersection = aSize + bSize - unionSize;
        int min1 = Math.min(aSize - intersection, bSize - intersection);
        return Math.min(min1, intersection);
        // TODO: potentially make faster, take advantage of sortedness of arrays.
    }

    public static void anneal(List<Node> nodes, List<Node> bigNodes) {
        int iterations = 5_000_000;
        assert nodes.size() > 20;
        for (int i = 1; i <= iterations; i++) {
            if (i % 40000 == 0) {
                System.out.println(i);
            }
            double temperature = (double) (i) / iterations;
            // pick random neighbor
            Node n1 = nodes.get(rand(nodes.size()));
            Node n2 = nodes.get(rand(nodes.size()));

            //can only merge if nodes are sufficiently far apart
            if (n1 == n2 || n1.next == n2 || n1.prev == n2 || n1.prev.prev == n2) {
                continue;
            }
            int improvement = improvement(n1, n2);

            if (improvement > 0 || shouldSwitch(improvement, temperature)) {
                merge(n1, n2);
            }
            if (bigNodes.size()>0 && i % 10 == 0) {
                Node aNode = bigNodes.get(rand(bigNodes.size()));
                Node bNode = bigNodes.get(rand(bigNodes.size()));
                int[] improvement2 = improvement2(aNode, bNode);
                if (improvement > 0 || shouldSwitch(improvement2[0], temperature)) {
                    aNode.swap(bNode, improvement2[1], improvement2[2]);
                }
            }
        }

    }

    public static boolean shouldSwitch(int improvement, double temperature) {
        return Math.exp(improvement / temperature) > Math.random();
    }

    //return random integer in [0, max)
    public static int rand(int max) {
        return (int) (Math.random() * max);
    }

    private static void readInput(Scanner sc) {
        int numPhotos = sc.nextInt();
        Queue<Photo> verticals = new ArrayDeque<>();
        /*
         * consume new line character (CHECK THIS IF INPUT BAD)
         */
        sc.nextLine();
        /*
         * read in each line
         */
        for (int i = 0; i < numPhotos; i++) {

            /*
             * split the line into an array
             */
            String line = sc.nextLine();
            String[] lineArr = line.split(" ");
            /*
             * create params for node
             */
            Orientation o;
            List<Integer> photoTags = new ArrayList<Integer>();

            if (lineArr[0].equals("H")) {
                o = Orientation.H;
            } else {
                o = Orientation.V;
            }
            int numTags = Integer.parseInt(lineArr[1]);


            /*
             * read in tag, if it is in map already
             * then put in list, if it is not, add it to the map
             * and increment the ID integer
             */
            Photo currentPhoto = new Photo(o, photoTags);
            for (int j = 0; j < numTags; j++) {

                String tag = lineArr[j + 2];

                if (!tagMapInt.containsKey(tag)) {
                    tagMapInt.put(tag, tagID);
                    tagID++;
                }
                int tagInt = tagMapInt.get(tag);
                photoTags.add(tagInt);
                // if (!nodesWithTag.containsKey(tagInt)) {
                //     nodesWithTag.put(tagInt, new ArrayList<Node>());
                // }
                //nodesWithTag.get(tagInt).add(currentNode);
            }

            Collections.sort(photoTags);
            if (o == Orientation.V) {
                verticals.add(currentPhoto);
            } else {
                nodeList.add(nodeList.size(), new Node(currentPhoto));
            }
        }
        while (verticals.size() >= 2) {
            Node newNode = new Node(verticals.remove(), verticals.remove());
            nodeList.add(newNode);
            verticalNodes.add(verticalNodes.size(), newNode);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("C:\\Users\\7Alex\\IdeaProjects\\ProgrammingContests\\ProgrammingContests\\resources\\d_pet_pictures.txt"));
        PrintWriter out = new PrintWriter(new File("output.txt"));

        tagMapInt = new HashMap<String, Integer>();
        nodeList = new ArrayList<Node>();
        //nodesWithTag = new HashMap<>();
        verticalNodes = new ArrayList<Node>();
        tagID = 0;
        photoID = 0;

        readInput(sc);
        setUpDatList(nodeList);
        anneal(nodeList, verticalNodes);

        printList(out, nodeList.get(0), nodeList.size());


        out.close();
    }
}

