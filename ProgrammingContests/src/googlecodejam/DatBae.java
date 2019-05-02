package googlecodejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class DatBae {
    public void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());
        System.err.println(cases);
        for (int testNum = 1; testNum <= cases; testNum++) {
            int[] params = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(x -> Integer.parseInt(x)).toArray();
            System.err.println(Arrays.toString(params));
            int n = params[0];
            int broken = params[1];
            int tries = params[2];

            // formulate questions
            StringBuilder[] queries = new StringBuilder[4];
            for (int i = 0; i < queries.length; i++) {
                queries[i] = new StringBuilder();
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 4; j++) {
                    queries[j].append((i >> j) % 2);
                }
            }
            // ask queries and read answers
            for (int i = 0; i < queries.length; i++) {
                System.out.println(queries[i]);
                System.err.println(queries[i]);
            }
            System.out.flush();
            //read answers
            int[] answers = new int[n - broken + 1];
            for (int j = 0; j < 4; j++) {
                char[] in = br.readLine().toCharArray();
                System.err.println(Arrays.toString(in));
                for (int i = 0; i < n - broken; i++) {
                    if (in[i] == '1') {
                        answers[i] += (1 << j);
                    }
                }
            }
            answers[n - broken] = -1;
            System.err.println(Arrays.toString(answers));
            // detect missing bits
            int expected = 0;
            int wrongSeen = 0;
            List<Integer> wrong = new ArrayList<>(n - broken);
            for (int i = 0; i < n; i++) {
                while (i < n && expected % 16 != answers[i - wrongSeen]) {
                    expected++;
                    wrong.add(i);
                    wrongSeen++;
                    i++;
                }
                expected++;
            }

            // print answer
            StringBuilder ans = new StringBuilder("" + wrong.get(0));
            for (int i = 1; i < wrong.size(); i++) {
                ans.append(" " + wrong.get(i));
            }
            System.out.println(ans);
            System.err.println(ans);
            System.out.flush();
            int verdict = Integer.parseInt(br.readLine());
            System.err.println(verdict);
            if (verdict == -1) {
                return;
            }
        }
        br.close();
    }

    public static void main(String[] args) throws IOException {
        DatBae solution = new DatBae();
        solution.solve();
    }
}
