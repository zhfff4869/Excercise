import java.util.ArrayList;

public class Matrix {
    public static ArrayList<Integer> printMatrix(int[][] matrix) {
        ArrayList<Integer> temp = new ArrayList<Integer>();
        int count = 0; // 处理的总点数
        int circle = 0; // 处在第几圈
        int edgej = matrix[circle].length; // 矩阵横边的长度
        int edgei = matrix.length; // 矩阵纵边的长度

/*         if (edgej <= 1) {
            temp.add(matrix[0][0]);
            return temp;
        } */

        int i, j;
        while (true) {
            if(circle==edgej-circle-1&&circle==edgei-circle-1){  //when this circle has just one point
                temp.add(matrix[circle][circle]);
                count++;
                return temp;
            }
            for (i = circle, j = circle; j < edgej - circle - 1; j++) {
                temp.add(matrix[i][j]);
                count++;
                if (count >= edgei*edgej)
                    return temp;
            }
            for (; i < edgei - 1 - circle; i++) {
                temp.add(matrix[i][j]);
                count++;
                if (count >= edgei*edgej)
                    return temp;
            }
            for (; j > circle; j--) {
                temp.add(matrix[i][j]);
                count++;
                if (count >= edgei*edgej)
                    return temp;
            }
            for (; i > circle; i--) {
                temp.add(matrix[i][j]);
                count++;
                if (count >= edgei*edgej)
                    return temp;
            }
            circle++;
        }

    }

    public static void main(String[] args) {

        int[][] matrix = new int[1][5];
        // int[][] matrix={{1}};

        int in = 1;
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = in;
                in++;
            }
        }

        System.out.println(printMatrix(matrix));
    }
}