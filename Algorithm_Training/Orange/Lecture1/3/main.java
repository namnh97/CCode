//https://codeforces.com/problemset/problem/510/C
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.LinkedList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task3 solver = new Task3();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task3 {
        public static final int MAX = 26;
        public static List<List<Integer>> graph;
        public static int n;
        public static List<Integer> result;
        public static List<String> names;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            graph = new ArrayList<>();
            for (int i = 0; i < MAX; i++) {
                graph.add(new ArrayList<>());
            }
            names = new ArrayList<>();
            result = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                names.add(in.nextLine());
            }

            boolean hasIndex = false;
            if (names.size() != 1) {
                for (int i = 0, j = 1; j < names.size(); i++, j++) {
                    int index = getDiffIndex(names.get(i), names.get(j));
                    if (index != -1) {
                        int src = names.get(i).charAt(index) - 'a';
                        int des = names.get(j).charAt(index) - 'a';
                        graph.get(src).add(des);
                        hasIndex = true;
                    }

                    if (!hasIndex && names.get(i).length() > names.get(j).length()) {
                        out.print("Impossible");
                        return;
                    }
                }
            }

            String res = "";
            if (hasTopological(graph, result)) {
                for (int i : result) {
                    res += (char) (i + 'a');
                }
            } else {
                res = "Impossible";
            }
            out.print(res);
        }

        private boolean hasTopological(List<List<Integer>> graph, List<Integer> result) {
            int[] inDegree = new int[MAX];
            Queue<Integer> zeroInDegree = new LinkedList<>();
            for (int i = 0; i < MAX; i++) {
                for (int v : graph.get(i)) {
                    inDegree[v]++;
                }
            }

            for (int i = 0; i < MAX; i++) {
                if (inDegree[i] == 0) {
                    zeroInDegree.add(i);
                }
            }

            while (!zeroInDegree.isEmpty()) {
                int u = zeroInDegree.poll();
                result.add(u);
                for (int v : graph.get(u)) {
                    inDegree[v]--;
                    if (inDegree[v] == 0) {
                        zeroInDegree.add(v);
                    }
                }
            }

            for (int i = 0; i < MAX; i++) {
                if (inDegree[i] != 0) {
                    return false;
                }
            }
            return true;
        }

        private int getDiffIndex(String s, String s1) {
            int len = Math.min(s.length(), s1.length());
            int result = -1;
            for (int i = 0; i < len; i++) {
                if (s.charAt(i) == s1.charAt(i)) {
                    continue;
                }
                result = i;
                break;
            }
            return result;
        }

    }

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}

