/* test系列是关于模糊数学的贴近度的作业的代码实现 */


import java.util.Scanner;

public class test2 {
    public static void main(String[] args) {
        model.inputB();
        model.match();
    }
}

class model {
    static double[] A1 = { 1, 0.8, 0.5, 0.4, 0, 0.1 };
    static double[] A2 = { 0.5, 0.1, 0.8, 1, 0.6, 0 };
    static double[] A3 = { 0, 1, 0.2, 0.7, 0.5, 0.8 };
    static double[] A4 = { 0.4, 0, 1, 0.9, 0.6, 0.5 };
    static double[] A5 = { 0.8, 0.2, 0, 0.5, 1, 0.7 };
    static double[] A6 = { 0.5, 0.7, 0.8, 0, 0.5, 1 };
    static double[] B = new double[6];

    public static void inputB() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < B.length; i++) {
            B[i] = scanner.nextDouble();
        }
        scanner.close();
    }

    public static double sigma(double[] A, double[] B) {
        double up = 0, down = 0;
        for (int i = 0; i < A.length; i++) {
            up += Math.min(A[i], B[i]);
            down += Math.max(A[i], B[i]);
        }
        return up / down;
    }

    public static void match() {
        double[] score = new double[6];
        score[0] = sigma(A1, B);
        score[1] = sigma(A2, B);
        score[2] = sigma(A3, B);
        score[3] = sigma(A4, B);
        score[4] = sigma(A5, B);
        score[5] = sigma(A6, B);
        double maxscore = 0;
        int maxindex = 0;
        for (int i = 0; i < 6; i++) {
            System.out.printf("model %d: score is %.4f\n",i+1,score[i]);
            if (score[i] > maxscore) {
                maxscore = score[i];
                maxindex = i+1;
            }
        }
        System.out.println("B is relatively of A"+maxindex);
    }
}