package test;

import java.util.Vector;

import test.test8;

public class test9{
    public static void main(String[] args) {
        Double[][] R={{1.,0.11,0.69,0.35,0.39,0.45,0.79},{0.11,1.,0.15,0.81,0.66,0.52,0.01},{0.69,0.15,1.,0.23,0.52,0.35,0.79},{0.35,0.81,0.23,1.,0.38,0.65,0.27},{0.39,0.66,0.52,0.38,1.,0.44,0.36},{0.45,0.52,0.35,0.65,0.44,1.,0.35},{0.79,0.01,0.79,0.27,0.36,0.35,1.}};

        Vector<Double> Split=test8.getSplit(R);
        Vector<Double[][]> P=new Vector<>();
        for(Double i:Split){
            Double[][] temp=test7.Rlamda1(R,i);
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

    public static Double[] Cater(Double[][] R) {
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
}