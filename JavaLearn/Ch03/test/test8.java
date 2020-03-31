package test;
import java.util.Vector;

import test.test7;

public class test8{
    public static void main(String[] args) {
        Double[][] R={{1.,0.39,0.16,0.59},{0.39,1.,0.55,0.41},{0.16,0.55,1.,0.26},{0.59,0.41,0.26,1.}};
        Vector<Double> Split=getSplit(R);
        Vector<Double[][]> P=new Vector<>();
        for(Double i:Split){
            Double[][] temp=test7.Rlamda1(R,i);
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
}
