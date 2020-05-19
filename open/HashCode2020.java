package open;

import java.io.*;
import java.util.*;

class HashCode2020 {
    static int NBooks;
    static int NLibraries;
    static int NDays;
    static int remainingDays;
    static final boolean GREEDY_SOLVE = false;
    static final boolean DETERMINISTIC = true;
    static final int NUM_ITERATIONS = 1;
    static List<Library> libraries;
    static int globalScore;
    static int[] scores; // id -> score given by choosing this book
    /* maps ids to total count across all libraries */
    static Map<Integer, Integer> bookIDCount;


    /**
     * Output class we build, call toString to return solution
     */
    public static class Output {
        List<Integer> listOfLibraryIds;

        /* listOfBookIds[i] := list of books that library i is using*/
        List<List<Integer>> listOfBookIds;

        public Output() {
            listOfLibraryIds = new ArrayList<>();
            listOfBookIds = new ArrayList<>();
        }

        public int computeScore() {
            Set<Integer> books = new HashSet<>();
            globalScore = 0;
            for (int i = 0; i < listOfLibraryIds.size(); i++) {
                for (int book : listOfBookIds.get(i)) {
                    if (books.contains(book)) {
                        throw new RuntimeException("Duplicate books shouldn't happen");
                    } else {
                        books.add(book);
                        globalScore += scores[book];
                    }
                }
            }
            return globalScore;
        }

        public void addLibrary(int libraryIndex, List<Integer> list) {
            assert listOfLibraryIds.size() == listOfBookIds.size();
            listOfLibraryIds.add(libraryIndex);
            listOfBookIds.add(list);
        }

        public void deleteEmpties() {
            int n = listOfLibraryIds.size();
            List<Integer> newListOfLibraryIds = new ArrayList<>(n);
            List<List<Integer>> newListOfBookIds = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                Integer libId = listOfLibraryIds.get(i);
                List<Integer> bookList = listOfBookIds.get(i);
                if (!bookList.isEmpty()) {
                    newListOfLibraryIds.add(libId);
                    newListOfBookIds.add(bookList);
                }
            }
            this.listOfBookIds = newListOfBookIds;
            this.listOfLibraryIds = newListOfLibraryIds;
        }

        @Override
        public String toString() {
            deleteEmpties();
            computeScore();
            StringBuilder sb = new StringBuilder("");
            sb.append(listOfLibraryIds.size()).append("\n");
            for (int i = 0; i < listOfLibraryIds.size(); i++) {
                List<Integer> bookList = listOfBookIds.get(i);
                int size = bookList.size();
                if (size == 0) {
                    continue;
                }

                sb.append(listOfLibraryIds.get(i)).append(" ").append(size).append("\n");
                List<String> strList = new ArrayList<>();
                for (int bid : bookList) {
                    strList.add(Integer.toString(bid));
                }
                sb.append(String.join(" ", strList));
                sb.append("\n");
            }
            sb.deleteCharAt(sb.length() - 1);
            return sb.toString();
        }
    }

    public static class Library {
        public static class Book {
            int bookID;
            int score;
            /*
             * book heuristic
             */
            double value;

            public Book(int bookID, int score) {
                this.bookID = bookID;
                this.score = score;
            }

            @Override
            public int hashCode() { //needs to be compatable with equals.
                return bookID;
            }

            @Override
            public boolean equals(Object obj) {
                assert obj instanceof Book;
                Book b = (Book) obj;
                return bookID == b.bookID;
            }
        }

        int signupTime; // days to finish signup
        int booksPerDay; //shipped per day
        Book[] bookCatalog;
        //double catalogScore;
        int index;
        double libraryHeur;

        public Library(Library o) {
            this.signupTime = o.signupTime;
            this.index = o.index;
            this.booksPerDay = o.booksPerDay;
            //this.catalogScore = -1;
            this.bookCatalog = new Book[o.bookCatalog.length];
            for (int i = 0; i < o.bookCatalog.length; i++) {
                this.bookCatalog[i] = new Book(o.bookCatalog[i].bookID, o.bookCatalog[i].score);
            }
        }

        public Library(int signupTime, int booksPerDay, Set<Integer> ids, int[] scores, int index) {
            this.signupTime = signupTime;
            this.index = index;
            this.booksPerDay = booksPerDay;
            //this.catalogScore = -1;
            this.bookCatalog = new Book[ids.size()];
            List<Integer> idList = new ArrayList<>(ids);
            for (int i = 0; i < ids.size(); i++) {
                int id = idList.get(i);
                this.bookCatalog[i] = new Book(id, scores[id]);
            }
        }

        public int maxScannableBooks(int totalDays) {
            return (totalDays - this.signupTime) * this.booksPerDay;
        }

        // requires bookCatalog to be sorted
        public void computeLibraryHeuristic() {
            this.sortBookList();
            double sum = 0;
            for (int i = 0; i < Math.min(this.maxScannableBooks(remainingDays), bookCatalog.length); i++) {
                double val = bookCatalog[i].value;
                sum += val;
            }
            if (!DETERMINISTIC) {
                sum *= (1.25 - .5 * Math.random());
            }
            this.libraryHeur = sum / this.signupTime;
        }

        // public void scoreCatalog() { //updates and computes score for the catalog
        //     double sum = 0;
        //     for( int i = 0; i < bookCatalog.length; i++) {
        //         sum += bookCatalog[i].value;
        //     }
        //     this.catalogScore = sum;
        // }

        public void sortBookList() {

            // update libraries
            for (int i = 0; i < bookCatalog.length; i++) {
                Book book = bookCatalog[i];
                book.value = ((double) (book.score)) / bookIDCount.get(book.bookID); // count / score
            }

            // sort the book Catalog
            Arrays.parallelSort(this.bookCatalog, new Comparator<Book>() {
                @Override
                public int compare(Book o1, Book o2) {
                    return Double.compare(o2.value, o1.value);
                }

                @Override
                public boolean equals(Object obj) {
                    return false;
                }
            });
        }
    }

    public static void sortLibraries() {
        libraries.sort(new Comparator<>() {
            @Override
            public int compare(Library o1, Library o2) {
                return Double.compare(o1.libraryHeur, o2.libraryHeur);
            }

            @Override
            public boolean equals(Object obj) {
                return false;
            }
        });
    }

    public static String solve(BufferedReader br) throws IOException {
        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        NBooks = input[0];
        NLibraries = input[1];
        NDays = input[2];
        remainingDays = NDays;
        scores = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        libraries = new ArrayList<Library>();
        for (int i = 0; i < NLibraries; i++) {
            input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int n = input[0];
            int t = input[1];
            int m = input[2];
            input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            // int numbooks, int signupTime, int booksPerDay, int[] ids, int[] scores, int index
            // initialize libraries
            Set<Integer> bookIds = new HashSet<>();
            for (int id : input) {
                bookIds.add(id);
            }

            libraries.add(new Library(t, m, bookIds, scores, i));
        }

        bookIDCount = new HashMap<>();
        // count books
        for (Library L : libraries) {
            for (Library.Book b : L.bookCatalog) {
                bookIDCount.put(b.bookID, bookIDCount.getOrDefault(b.bookID, 0) + 1);
            }
        }


        //////////////////////////////
        // Compute a decent solution//
        //////////////////////////////
        List<Library> solution = new ArrayList<>();

        List<Integer> booksThatCanBeScanned = new ArrayList<>();
        while (!libraries.isEmpty() && remainingDays > 0) {
            for (Library L : libraries) {
                L.computeLibraryHeuristic();
            }
            sortLibraries();
            Library lib = libraries.remove(libraries.size() - 1);
            remainingDays -= lib.signupTime;
            solution.add(lib);
            booksThatCanBeScanned.add(remainingDays * lib.booksPerDay);
        }

        libraries = solution;

        //////////////////////////////
        ///// Improve solution ///////
        //////////////////////////////
        // TODO
        // We basically wanna maximize the number of disjoint books in
        // each library. Suppose that we switch the order of two libraries... fuuck

        //////////////////////////////
        ////////  Output  ////////////
        //////////////////////////////

        // Output outputObj = new Output();
        // if (GREEDY_SOLVE) {
        //     Set<Library.Book> scanned = new HashSet<>(10000);
        //     for (int i = 0; i < libraries.size(); i++) {
        //         Library L = libraries.get(i);
        //         int toScan = booksThatCanBeScanned.get(i);
        //         List<Integer> libBooks = new ArrayList<>();
        //         for (Library.Book b : L.bookCatalog) {
        //             int id = b.bookID;
        //             if (!scanned.contains(b) && toScan > 0) {
        //                 toScan--;
        //                 scanned.add(b);
        //                 libBooks.add(id);
        //             }
        //         }
        //         outputObj.addLibrary(L.index, libBooks);
        //     }
        // } else {
        //     outputObj = setupGraph();
        // }

        // new strategy: swap and anneal
        return anneal(NUM_ITERATIONS).toString();
    }

    // the chance that a swap should be taken
    public static double acceptanceProbability(double score1, double score2, double temp) {
        if (score2 > score1) {
            return 1;
        } else {
            return 0;
        }
        //return Math.exp((score1-score2)/(T));
    }

    //return if you should do a swap
    public static Output anneal(int iterations) {
        for (int i = 1; i <= iterations; i++) {
            double temp = (double) (iterations) / (i);
            Output o1 = setupGraph();
            int score1 = o1.computeScore();
            int[] unswappers = swap();
            Output o2 = setupGraph();
            int score2 = o2.computeScore();
            if (acceptanceProbability(score1, score2, temp) <= Math.random()) {
                unswap(unswappers);
            } else {
                System.out.println(score1 + " " + score2);
            }
            if(i%20==0){
                System.out.println(i + " out of " + NUM_ITERATIONS);
            }
        }
        return setupGraph();
    }

    public static int[] swap() {
        int index1 = (int) (3 * Math.random() / 4 * libraries.size());
        int distance = (int) (Math.random() * libraries.size() / 4);
        int index2 = index1 + distance;
        while (index2 < 0) {
            index2++;
        }
        while (index2 > libraries.size()) {
            index2--;
        }

        // swap the libraries
        Library temp = libraries.get(index1);
        libraries.set(index1, libraries.get(index2));
        libraries.set(index2, temp);

        return new int[]{index1, index2};
    }

    public static void unswap(int[] arr) {
        Library temp = libraries.get(arr[0]);
        libraries.set(arr[0], libraries.get(arr[1]));
        libraries.set(arr[1], temp);
    }


    public static void runRepeat(String infile, File outfile, int times) throws IOException {
        System.out.println("Running " + infile + "...");
        int maxScore = 0;
        String bestStr = "";
        for (int i = 0; i < times; i++) {
            BufferedReader in = new BufferedReader(new FileReader(new File(infile)));
            String result = solve(in);
            if (maxScore < globalScore) {
                maxScore = globalScore;
                bestStr = result;
            }
            if ((i + 1) % (times / 3 + 10) == 0) {
                System.out.println(i + 1 + " times out of " + times);
            }
        }
        System.out.println("Score: " + maxScore);
        PrintWriter out = new PrintWriter(outfile);
        out.println(bestStr);
        out.flush();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        //runOne(new File("input/test.txt"), new File("output/test.out"));
        // runRepeat("input/b_read_on.txt", new File("output/b.out"), 1);
        // runRepeat("input/c_incunabula.txt", new File("output/c.out"), 1);
        // runRepeat("input/d_tough_choices.txt", new File("output/d.out"), 1);
        // runRepeat("input/e_so_many_books.txt", new File("output/e.out"), 1);
        runRepeat("input/f_libraries_of_the_world.txt", new File("output/f.out"), 1);
    }

    public static Output setupGraph() {
        int daysLeft = NDays;
        int nLibs = 0;
        List<Integer> libraryPower = new ArrayList<>();
        List<List<Library.Book>> notRemovedBooks = new ArrayList<>();
        for (; nLibs < libraries.size(); nLibs++) {
            daysLeft -= libraries.get(nLibs).signupTime;
            if (daysLeft < 0) {
                break;
            }
            libraryPower.add(libraries.get(nLibs).booksPerDay * daysLeft);
            notRemovedBooks.add(new ArrayList<>());
            for (Library.Book b : libraries.get(nLibs).bookCatalog) {
                notRemovedBooks.get(nLibs).add(b);
            }
        }
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < nLibs; i++) {
            edges.add(new ArrayList<>());
        }
        int decrement = 50;
        for (int valueBound = 1000; valueBound >= 0; valueBound -= decrement) {
            improveFlow(edges, notRemovedBooks, libraryPower, valueBound, valueBound + decrement);//mutates edges
        }
        return resultFromEdge(edges, nLibs);
    }

    public static void improveFlow(List<List<Integer>> edges, List<List<Library.Book>> notRemovedBooks, List<Integer> libraryPower, int valueBoundLower, int valueBoundUpper) {
        int nodes = libraryPower.size() + NBooks;
        Dinic dinic = new Dinic(nodes);
        int source = nodes;
        int sink = nodes + 1;
        // source to libraries
        for (int i = 0; i < libraryPower.size(); i++) {
            dinic.add(source, i, libraryPower.get(i), 0);
            for (Library.Book b : notRemovedBooks.get(i)) {
                if (valueBoundLower <= b.value && b.value < valueBoundUpper) {
                    dinic.add(i, libraryPower.size() + b.bookID, 1, 0);
                }
            }
        }
        for (int i = libraryPower.size(); i < nodes; i++) {
            dinic.add(i, sink, 1, 0);
        }
        dinic.flow(); // compute flow
        updateEdges(dinic, edges, notRemovedBooks, libraryPower, source);
    }

    public static void updateEdges(Dinic dinic, List<List<Integer>> edges, List<List<Library.Book>> notRemovedBooks, List<Integer> libraryPower, int source) {
        ArrayList<Edge>[] adj = dinic.adj;
        for (int i = 0; i < libraryPower.size(); i++) {
            for (Edge e : adj[i]) {
                if (e.v2 != source & e.flow != 0) {
                    edges.get(i).add(e.v2 - libraryPower.size());
                    //remove book i from the library
                    for (Library.Book b : libraries.get(i).bookCatalog) {
                        if (b.bookID == e.v2 - libraryPower.size()) {
                            notRemovedBooks.get(i).remove(b);
                            break;
                        }
                    }
                    libraryPower.set(i, libraryPower.get(i) - 1);
                }
            }
        }
    }

    public static Output resultFromEdge(List<List<Integer>> edges, int nLibs) {
        Output o = new Output();
        for (int i = 0; i < nLibs; i++) {
            o.addLibrary(libraries.get(i).index, edges.get(i));
        }
        return o;
    }

    // An edge connects v1 to v2 with a capacity of cap, flow of flow.
    static class Edge {
        int v1, v2, cap, flow;
        Edge rev;

        Edge(int V1, int V2, int Cap, int Flow) {
            v1 = V1;
            v2 = V2;
            cap = Cap;
            flow = Flow;
        }
    }

    public static class Dinic {

        // Queue for the top level BFS.
        public ArrayDeque<Integer> q;

        // Stores the graph.
        public ArrayList<Edge>[] adj;
        public int n;

        // s = source, t = sink
        public int s;
        public int t;


        // For BFS.
        public boolean[] blocked;
        public int[] dist;

        final public static int oo = (int) 1E9;

        // Constructor.
        public Dinic(int N) {

            // s is the source, t is the sink, add these as last two nodes.
            n = N;
            s = n++;
            t = n++;

            // Everything else is empty.
            blocked = new boolean[n];
            dist = new int[n];
            q = new ArrayDeque<Integer>();
            adj = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                adj[i] = new ArrayList<Edge>();
        }

        // Just adds an edge and ALSO adds it going backwards.
        public void add(int v1, int v2, int cap, int flow) {
            Edge e = new Edge(v1, v2, cap, flow);
            Edge rev = new Edge(v2, v1, 0, 0);
            adj[v1].add(rev.rev = e);
            adj[v2].add(e.rev = rev);
        }

        // Runs other level BFS.
        public boolean bfs() {

            // Set up BFS
            q.clear();
            Arrays.fill(dist, -1);
            dist[t] = 0;
            q.add(t);

            // Go backwards from sink looking for source.
            // We just care to mark distances left to the sink.
            while (!q.isEmpty()) {
                int node = q.poll();
                if (node == s)
                    return true;
                for (Edge e : adj[node]) {
                    if (e.rev.cap > e.rev.flow && dist[e.v2] == -1) {
                        dist[e.v2] = dist[node] + 1;
                        q.add(e.v2);
                    }
                }
            }

            // Augmenting paths exist iff we made it back to the source.
            return dist[s] != -1;
        }

        // Runs inner DFS in Dinic's, from node pos with a flow of min.
        public int dfs(int pos, int min) {

            // Made it to the sink, we're good, return this as our max flow for the augmenting path.
            if (pos == t)
                return min;
            int flow = 0;

            // Try each edge from here.
            for (Edge e : adj[pos]) {
                int cur = 0;

                // If our destination isn't blocked and it's 1 closer to the sink and there's flow, we
                // can go this way.
                if (!blocked[e.v2] && dist[e.v2] == dist[pos] - 1 && e.cap - e.flow > 0) {

                    // Recursively run dfs from here - limiting flow based on current and what's left on this edge.
                    cur = dfs(e.v2, Math.min(min - flow, e.cap - e.flow));

                    // Add the flow through this edge and subtract it from the reverse flow.
                    e.flow += cur;
                    e.rev.flow = -e.flow;

                    // Add to the total flow.
                    flow += cur;
                }

                // No more can go through, we're good.
                if (flow == min)
                    return flow;
            }

            // mark if this node is now blocked.
            blocked[pos] = flow != min;

            // This is the flow
            return flow;
        }

        public int flow() {
            clear();
            int ret = 0;

            // Run a top level BFS.
            while (bfs()) {

                // Reset this.
                Arrays.fill(blocked, false);

                // Run multiple DFS's until there is no flow left to push through.
                ret += dfs(s, oo);
            }
            return ret;
        }

        // Just resets flow through all edges to be 0.
        public void clear() {
            for (ArrayList<Edge> edges : adj)
                for (Edge e : edges)
                    e.flow = 0;
        }
    }
}
