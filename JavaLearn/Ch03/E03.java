
public class E03 {
    public static void main(String[] args) {
        double[][] x={{1,2,3},{4,5,6}};
        double[][] y={{7,8,9,10},{1,1,1,1},{2,2,2,2}};
        double[][] z=null;
        try{z=MatrixMultiply(x, y);} catch(Exception e){System.out.println(e.getMessage());}
        for(double[] i:z){
            System.out.println();
            for(double j:i)
                System.out.print(j+" ");
        }
        
    }

    public static double[][] MatrixMultiply(double[][] x,double[][] y) throws Exception{
        if(x[0].length!=y.length)
        {throw new Exception("MatrixSizeMismatch!");
        }
        double[][] res=new double[x.length][y[0].length];
        for(int i=0;i<res.length;i++){
            for(int j=0;j<res[0].length;j++){
                double value=0;
                for(int k=0;k<x[i].length;k++)
                    value+=x[i][k]*y[k][j];
                res[i][j]=value;
            }
        }
        return res;
    }
}