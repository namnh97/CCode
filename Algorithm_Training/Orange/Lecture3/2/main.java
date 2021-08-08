//https://tanjim131.github.io/2020-06-13-uva-729/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet;
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

		public static final int[] dx = { 1, -1, 0, 0 };

		public static final int[] dy = { 0, 0, 1, -1 };

		int n;

		public char[][] graph;

		public boolean[][] visited;

		TreeSet<Long> octaves;

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int t = in.nextInt();
			while (t-- > 0) {
				n = in.nextInt();
				graph = new char[n][n];
				visited = new boolean[n][n];
				octaves = new TreeSet<>();

				for (int i = 0; i < n; i++) {
					String line = in.nextLine();
					for (int j = 0; j < n; j++) {
						graph[i][j] = line.charAt(j);
					}
				}

				long bits;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (graph[i][j] == 'X') {
							bits = 0;
							dfs(i, j, 1, bits);
						}
					}
				}
				out.println(octaves.size());
			}
		}

		private void dfs(int x, int y, int count, long bits) {
			visited[x][y] = true;
			bits |= (1L << (n * x + y));

			if (count == 8) {
				octaves.add(bits);
			}
			else {
				for (int i = 0; i < dx.length; i++) {
					int nextX = x + dx[i];
					int nextY = y + dy[i];
					if (onGraph(nextX, nextY) && !visited[nextX][nextY] && graph[nextX][nextY] == 'X') {
						dfs(nextX, nextY, count + 1, bits);
					}
				}
			}

			visited[x][y] = false;
			bits &= ~(1L << (n * x + y));
		}

		private boolean onGraph(int x, int y) {
			if (x >= 0 && x < n && y >= 0 && y < n) {
				return true;
			}
			return false;
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

		public String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

	}
}

