package test;
//Chapter 5:number 3

import java.util.Vector;

public class test9{

    public static void main(String[] args) {
        Double[][] R={
        {1.,0.11,0.69,0.35,0.39,0.45,0.79},
        {0.11,1.,0.15,0.81,0.66,0.52,0.01},
        {0.69,0.15,1.,0.23,0.52,0.35,0.79},
        {0.35,0.81,0.23,1.,0.38,0.65,0.27},
        {0.39,0.66,0.52,0.38,1.,0.44,0.36},
        {0.45,0.52,0.35,0.65,0.44,1.,0.35},
        {0.79,0.01,0.79,0.27,0.36,0.35,1.}
    };

/*         Double[][] tmp=new Double[R.length][R[0].length];
        int n=0;
        while(n<R.length){
            try{tmp=matrixMultiply(R, R);} catch(Exception e){System.out.println(e.getMessage());}
            if(matrixEqual(tmp, R))
                break;
            else{
                R=tmp;
            }
            n++;
        }  */          //得到传递闭包


        Vector<Double> Split=getSplit(R);           //lamda 的每个节点取值
        Vector<Double[][]> P=new Vector<>();        //P存储各个lamda对应的截关系矩阵
        for(Double i:Split){
            Double[][] temp=Rlamda1(R,i);
            P.add(temp);
        }

        for(Double[][] i:P){
            int index=P.indexOf(i);
            System.out.println("\n"+index+"--lamda is "+Split.elementAt(index)+":");
            test7.printMatrix(i);
            Double[] catogory= Cater(i);
            System.out.println("the catogory of this lamda:");
            for(Double k:catogory){
                System.out.printf("%3.0f\t",k);
            }
            System.out.println("\t 所有为1的合成为一类，为0的自己就是单独的一类");
        }
    }

    public static Double[] Cater(Double[][] R) {    //按照截关系进行分类
        Double[] catogory=new Double[R.length];
        for(int i=0;i<catogory.length;i++)
            catogory[i]=0.;
        for(int i=0;i<R.length;i++){
            for(int j=0;j<R[i].length;j++){
                if(i==j)
                    continue;
                if(R[i][j]==1){
                    catogory[i]=1.;
                    break;
                }
            }
        }

        return catogory;
    }

    public static Vector<Double> getSplit(Double[][] R) {
        Vector<Double> Split=new Vector<>();
        Split.add(R[0][0]);
        for(Double[] i:R){
            for(Double j:i){
                if(!Split.contains(j))
                    Split.add(j);
            }
        }
        Split.sort(null);;

        return Split;
    }

    public static Double[][] Rlamda1(Double[][] R, double lamda) {  //unstrict Rlamda
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

    public static Double[][] clone(Double[][] arr) {
        Double[][] fuckthem = new Double[arr.length][arr[0].length];
        for (int i = 0; i < arr.length; i++) {
            fuckthem[i] = arr[i].clone();
        }
        return fuckthem;
    }

    public static Double[][] matrixMultiply(Double[][] X,Double[][] Y) throws Exception{
        if(X[0].length!=Y.length){
            throw new Exception("matrix size error");
        }
        Double[][] Z=new Double[X.length][Y[0].length];
        for(int i=0;i<X.length;i++){
            for(int j=0;j<Y[0].length;j++){
                double temp=0;
                for(int k=0;k<X[0].length;k++){
                    temp+=X[i][k]*Y[k][j];
                }
                Z[i][j]=temp;
            }
        }

        return Z;
    }

    public static boolean matrixEqual(Double[][] X,Double[][] Y) {
        double epo=1e-5;
        if(X.length!=Y.length||X[0].length!=Y[0].length)
            return false;
        for(int i=0;i<X.length;i++){
            for(int j=0;j<X[0].length;j++){
                if(X[i][j]-Y[i][j]>epo){
                    return false;
                }
                    
            }
        }
        return true;
    }
}