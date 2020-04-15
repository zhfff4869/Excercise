package test;
import java.util.Vector;
//Chapter 5:number 2


public class test8{
    public static void main(String[] args) {
        Double[][] R={{1.,0.39,0.16,0.59},{0.39,1.,0.55,0.41},{0.16,0.55,1.,0.26},{0.59,0.41,0.26,1.}};
        Vector<Double> Split=getSplit(R);
        Vector<Double[][]> P=new Vector<>();
        for(Double i:Split){
            Double[][] temp=Rlamda1(R,i);
            P.add(temp);
        }

        for(Double[][] i:P){
            int index=P.indexOf(i);
            System.out.println(index+"--lamda is "+Split.elementAt(index)+":");
            test7.printMatrix(i);
            for(int j=3,k=0;k<3;k++){
                if(i[k][j]==1.)
                    {System.out.println("result:this year is of "+(k+1)+"\n\n");break;}
            }
        }
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
