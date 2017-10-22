package acmkattis;

import java.util.Scanner;

//https://ecna15.kattis.com/problems/squawk
public class SquackVirus {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int s = sc.nextInt();
		int t = sc.nextInt();
		long[][] matrix = new long[n][n];
		long[][] vector = new long[n][1];
		vector[s][0] = 1; 
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			matrix[a][b]=1;
			matrix[b][a]=1;			
		}
		sc.close();
//		for (int i = 0; i < t; i++) {
//			vector = mult(matrix,vector);
//		}
		matrix = matPow(matrix,t);
		vector = mult(matrix,vector);
		long sum = 0;
		for (int i = 0; i < vector.length; i++) {
			sum+=vector[i][0];
		}
		System.out.println(sum);
	}

	private static long[][] mult(long[][] matrix, long[][] matrix2) {
		long[][] newMat = new long[matrix.length][matrix2[0].length];
		for (int i = 0; i < newMat.length; i++) {
			for (int j = 0; j < newMat[0].length; j++) {
				long val = 0;
				for (int k = 0; k < matrix2.length; k++) {
					val+= matrix[i][k]*matrix2[k][j];
				}
				newMat[i][j] = val;
			}
		}
		return newMat;
	}

	private static long[][] matPow(long[][] matrix, int pow) {
		if(pow == 0) {
			long[][] iden = new long[matrix.length][matrix.length];
			for (int i = 0; i < iden.length; i++) {
				iden[i][i] = 1;
			}
			return iden;
		}else if(pow==1) {
			return matrix;
		}
		long[][] sqrt = matPow(matrix, pow/2);
		long[][] res = mult(sqrt,sqrt);
		if(pow%2==0) {
			return res;
		}else {
			return mult(res,matrix);
		}
	}
	private static void print(int[][]matrix) {
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[0].length; j++) {
				
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}
}
