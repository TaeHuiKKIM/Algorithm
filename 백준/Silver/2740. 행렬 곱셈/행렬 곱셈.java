import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] a = new int[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a[i][j] = sc.nextInt();
            }
        }
        int m2 = sc.nextInt();
        int k = sc.nextInt();
        int[][] b = new int[m2][k];
        for(int i=0; i<m2; i++){
            for(int j=0; j<k; j++){
                b[i][j]=sc.nextInt();
            }
        }

        int[][] result = multiply(a,b,n,m,k);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                sb.append(result[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
    public static int[][] multiply(int[][] a, int[][] b, int n, int m, int k){
        int[][] res = new int[n][k];
        for(int i=0; i<n; i++){
            for(int j=0; j<k; j++){
                for(int l = 0; l<m; l++){
                    res[i][j] += a[i][l] * b[l][j];
                }
            }
        }
        return res;
    }
}