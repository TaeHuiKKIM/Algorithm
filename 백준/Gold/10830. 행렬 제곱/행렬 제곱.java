import java.util.Scanner;

public class Main {
	static final int MOD = 1000;
	static int N;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		long K = sc.nextLong(); 

		long[][] matrix = new long[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				matrix[i][j] = sc.nextLong() % MOD;
			}
		}

		long[][] result = power(matrix, K);

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sb.append(result[i][j]);
				if (j != N - 1) sb.append(" ");
			}
			sb.append("\n");
		}
		System.out.print(sb);
	}

	public static long[][] power(long[][] a, long exp) {
		if (exp == 1) {
			return a;
		}

		long[][] half = power(a, exp / 2);
		long[][] res = multiply(half, half);

		if (exp % 2 == 1) {
			res = multiply(res, a);
		}

		return res;
	}

	public static long[][] multiply(long[][] a, long[][] b) {
		long[][] res = new long[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					res[i][j] += a[i][k] * b[k][j];
					res[i][j] %= MOD; 
				}
			}
		}
		return res;
	}
}