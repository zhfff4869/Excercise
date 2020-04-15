// 这个代码很乱，是暴力法随便试出来的，哈哈哈

import java.util.ArrayList;

public class E01 {
    public static void main(String[] args) {
        int[] pushA={1,2,3,4,5};
        int[] popA={5,4,3,2,1};
        // int[] popA={2,3,1,5,4};
        // int[] popA={3,2,1,5,4};
        // int[] popA={4,3,5,1,2}; //false
        boolean i=IsPopOrder(pushA,popA);
        System.out.println(i);
    }

    public static boolean IsPopOrder(int[] pushA, int[] popA) {
        if (pushA.length!=popA.length)
            return false;
        boolean flag = true;
        ArrayList<Integer> A = new ArrayList<>();
        int i = 0;
        int j = 0;
        for (; j < popA.length||i<pushA.length; ) {
            while(!A.isEmpty()&&A.get(A.size()-1)==popA[j]&&j<popA.length){
                j++;
                A.remove(A.size()-1);
            }

            while (i < pushA.length&&pushA[i] != popA[j]) {
                A.add(pushA[i]);
                i++;
            }

            while (i<pushA.length&&pushA[i] == popA[j]) {
                    i++;
                    j++;
            }

            if(i==pushA.length&&j<popA.length){
                // j++;
                if(popA[j]!=A.get(A.size()-1)){
                    flag=false;break;}
                else{
                    A.remove(A.size()-1);
                    j++;
                }
            }
        }

        return flag;
    }
}