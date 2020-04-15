package test;
//Chapter 5:number 1
public class test7 {
    public static void main(String[] args) {
        Double[][] R = { { 0.7, 0.6, 0.5, 0.8 }, { 0.6, 0.9, 1., 0.8 }, { 0.7, 0.4, 0.3, 0.2 } };
        Double[][] R1 = Rlamda1(R, 0.5);
        Double[][] R2 = Rlamda2(R, 0.9);
        Double[][] R3 = Rlamda1(R, 0.9);
        Double[][] R4 = Rlamda1(R, 0.2);
        System.out.println("R_0.5:");
        printMatrix(R1);
        System.out.println("R_0.9_strict:");
        printMatrix(R2);
        System.out.println("R_0.9:");
        printMatrix(R3);
        System.out.println("R_0.2:");
        printMatrix(R4);


    }

    public static Double[][] Rlamda1(Double[][] R, double lamda) {
        Double[][] X = clone(R);
        for (int i = 0; i < X.length; i++) {
            for (int j = 0; j < X[i].length; j++) {
                if (X[i][j] >= lamda)
                X[i][j]=1.;
                else
                X[i][j]=0.;
            }
        }

        return X;
    }

    public static Double[][] Rlamda2(Double[][] R, double lamda) {
        Double[][] X = clone(R);
        for (int i = 0; i < X.length; i++) {
            for (int j = 0; j < X[i].length; j++) {
                if (X[i][j] > lamda)
                X[i][j]=1.;
                else
                X[i][j]=0.;
            }
        }

        return X;
    }

    public static void printMatrix(Double[][] R){
        for(Double[] i:R){
            for(Double j:i)
                System.out.printf("%5.1f",j);   //4.0f会自动做一个四舍五入
            System.out.println();
        }
        System.out.println();
    } 

    public static Double[][] clone(Double[][] arr) {
        Double[][] fuckthem = new Double[arr.length][arr[0].length];
        for (int i = 0; i < arr.length; i++) {
            fuckthem[i] = arr[i].clone();
        }
        return fuckthem;
    }
}