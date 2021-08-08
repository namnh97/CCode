//https://www.spoj.com/problems/MAKETREE/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        Task2 solver = new Task2();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task2 {
        public static ArrayList<ArrayList<Integer>> graph;
        public static boolean[] visited;
        public static ArrayList<Integer> topo;
        public static int n;
        public static int k;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            graph = new ArrayList<>();
            visited = new boolean[n + 5];
            topo = new ArrayList<>();
            for (int i = 0; i <= n; i++) {
                graph.add(new ArrayList<>());
            }

            for (int i = 1; i <= k; i++) {
                int numberOfW = in.nextInt();
                for (int j = 1; j <= numberOfW; j++) {
                    int w = in.nextInt();
                    graph.get(i).add(w);
                }
            }

            findTopo();

            int p = 0;
            int[] parent = new int[n + 5];
            for (int i = n - 1; i >= 0; i--) {
                parent[topo.get(i)] = p;
                p = topo.get(i);
            }
            for (int i = 1; i <= n; i++) {
                out.println(parent[i]);
            }
        }

        private void findTopo() {
            for (int i = 1; i <= n; i++) {
                if (visited[i] == false) {
                    dfs(i);
                }
            }
        }

        private void dfs(int index) {
            visited[index] = true;
            for (int v : graph.get(index)) {
                if (!visited[v]) {
                    dfs(v);
                }
            }
            topo.add(index);
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

    }
}