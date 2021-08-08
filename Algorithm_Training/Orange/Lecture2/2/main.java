//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/mattey-multiplication-6/editorial/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int t = in.nextInt();
			while (t-- > 0) {
				String line = in.nextLine();
				BigInteger n = new BigInteger(line.split(" ")[0]);
				BigInteger m = new BigInteger(line.split(" ")[1]);
				ArrayList<Integer> result = new ArrayList<>();
				int bit = 0;
				while (!m.equals(BigInteger.ZERO)) {
					if ((m.and(BigInteger.ONE)).equals(BigInteger.ONE)) {
						result.add(bit);
					}
					m = m.shiftRight(1);
					bit++;
				}
				out.printf("(%d<<%d) ", n, result.get(result.size() - 1));
				for (int i = result.size() - 2; i >= 0; i--) {
					out.printf("+ (%d<<%d) ", n, result.get(i));
				}
				out.println();
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