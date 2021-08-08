//https://codeforces.com/problemset/problem/448/C
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
 * Built using CHelper plug-in Actual solution is at the top
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

		public ArrayList<Integer> a;

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int n = in.nextInt();
			a = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				a.add(in.nextInt());
			}
			int ans = solve(0, n - 1, 0);
			out.println(ans);
		}

		public int solve(int left, int right, int paintedHeight) {
			if (left > right) {
				return 0;
			}

			int min = left;
			for (int i = left; i <= right; i++) {
				if (a.get(i) < a.get(min)) {
					min = i;
				}
			}

			int range = right - left + 1;
			int recursive = a.get(min) - paintedHeight + solve(left, min - 1, a.get(min)) + solve(min + 1, right, a.get(min));

			return Math.min(range, recursive);
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
				}
				catch (IOException e) {
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

