//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1186
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
		Task1 solver = new Task1();
		solver.solve(1, in, out);
		out.close();
	}

	static class Task1 {

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			while (true) {
				int n = in.nextInt();
				if (n == 0) {
					break;
				}

				ArrayList<Point> points = new ArrayList<>();
				for (int i = 0; i < n; i++) {
					double x = in.nextInt();
					double y = in.nextInt();
					points.add(new Point(x, y));
				}
				Collections.sort(points, (p1, p2) -> p1.x.compareTo(p2.x));
				double ans = calMinimalDist(points, 0, n);
				if (ans >= 10000) {
					out.print("INFINITY");
				}
				else {
					out.printf("%.4f", (ans));
				}
				out.println();
			}
		}

		private double calMinimalDist(ArrayList<Point> points, int left, int right) {
			if (left - right <= 3) {
				return bruteForce(points, left, right);
			}
			int mid = (left + right) / 2;
			double distLeft = calMinimalDist(points, left, mid);
			double distRight = calMinimalDist(points, mid + 1, right);
			double distMin = Math.min(distLeft, distRight);
			return Math.min(distMin, stripClosest(points, left, right, mid, distMin));
		}

		private double stripClosest(ArrayList<Point> points, int left, int right, int mid, double distMin) {
			Point pointMid = points.get(mid);
			ArrayList<Point> splittedPoints = new ArrayList<>();
			for (int i = left; i < right; i++) {
				if (Math.abs(points.get(i).x - pointMid.x) <= distMin) {
					splittedPoints.add(points.get(i));
				}
			}

			Collections.sort(splittedPoints, (p1, p2) -> p1.y.compareTo(p2.y));
			double smallest = Double.MAX_VALUE;
			for (int i = 0; i < splittedPoints.size(); i++) {
				for (int j = i + 1; j < splittedPoints.size(); j++) {
					if ((splittedPoints.get(j).y - splittedPoints.get(i).y) <= distMin) {
						double tmp = calDist(splittedPoints.get(i), splittedPoints.get(j));
						smallest = Math.min(smallest, tmp);
					}
				}
			}
			return smallest;
		}

		private double bruteForce(ArrayList<Point> points, int left, int right) {
			double distMin = Double.MAX_VALUE;
			for (int i = left; i < right; i++) {
				for (int j = i + 1; j < right; j++) {
					double distance = calDist(points.get(i), points.get(j));
					distMin = Math.min(distMin, distance);
				}
			}
			return distMin;
		}

		private double calDist(Point p1, Point p2) {
			double x = p1.x - p2.x;
			double y = p1.y - p2.y;
			return Math.sqrt(x * x + y * y);
		}

		class Point {

			public Double x;

			public Double y;

			public Point(double x, double y) {
				this.x = x;
				this.y = y;
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

	}
}

