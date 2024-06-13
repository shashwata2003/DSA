package STS.Cat1;
import java.util.*;
public class CelebrityProblem {
    public static void main(String[] arg){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] matrix = new int[n][n];
        for(int i = 0; i< n;i++){
            for(int j = 0; j<n;j++){
                matrix[i][j]=sc.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
