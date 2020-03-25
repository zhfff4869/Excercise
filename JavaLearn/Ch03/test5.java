/* test系列是关于模糊数学的贴近度的作业的代码实现 */
public class test5 {
    public static void main(String[] args) {
        model5.match();
    }
}

class model5 {
    static double[][] A = { { 0.2, 0.4, 0.5, 0.1 }, { 0.2, 0.5, 0.3, 0.1 }, { 0.2, 0.3, 0.4, 0.1 } };

    static double[][] B = { { 0, 0.6, 0.3, 0.1 }, { 0.2, 0.3, 0.5, 0 } };


    public static double sigma1(double[] A, double[] B) {    
        double up = 0, down = 0;
        for (int i = 0; i < A.length; i++) {
            up += Math.min(A[i], B[i]);
            down += A[i]+B[i];
        }
        return 2*up / down;
    }

    public static double sigma0(double[] A, double[] B) {   //格贴近度
        double left = 0, right = 0;
        double[] C=new double[A.length];
        double[] D=new double[A.length];
        for (int i = 0; i < A.length; i++) {
            C[i]=Math.min(A[i], B[i]);
            D[i]=Math.max(A[i], B[i]);
        }
        for (int i = 0; i < A.length; i++) {
            if(left<C[i])
                left=C[i];
            if(right>D[i])
                right=D[i];
        }
        return Math.min(left, 1-right);
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
        double[][] score = new double[B.length][A.length];
        for (int k = 0; k < B.length; k++) {
            for (int i = 0; i < A.length; i++) {
                score[k][i] = sigma0(A[i], B[k]);
            }
        }
        double[] maxscore = new double[score.length];
        int[] maxindex = new int[score.length];
        for (int k = 0; k < score.length; k++) {
            for (int i = 0; i < score[k].length; i++) {
                System.out.printf("B%d of model A%d: score is %.4f\n", k+1,i + 1, score[k][i]);
                if (score[k][i] > maxscore[k]) {
                    maxscore[k] = score[k][i];
                    maxindex[k] = i + 1;
                }
            }
        }
        for(int k=0;k<B.length;k++)
            System.out.println("B"+(k+1)+" is relatively of A" + maxindex[k]);
    }
}