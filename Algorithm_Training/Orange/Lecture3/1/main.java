//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=382
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        Task1 solver = new Task1();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1 {
        private static int[] s;
        private static boolean[] used;
        private static int[] ans = new int[6];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            while (true) {
                int n = in.nextInt();
                if (n == 0) break;

                s = new int[n];
                used = new boolean[n];
                Arrays.fill(used, false);
                for (int i = 0; i < n; i++) {
                    s[i] = in.nextInt();
                }
                backtracking(0, 0, out);
            }
        }

        private void backtracking(int index, int indexS, PrintWriter out) {
            if (index == 6) {
                for (int i = 0; i < 6; i++) {
                    out.print(ans[i] + " ");
                }
                out.println();
                return;
            }
            for (; indexS < s.length; indexS++) {
                ans[index] = s[indexS];
                backtracking(index + 1, indexS + 1, out);
            }

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

