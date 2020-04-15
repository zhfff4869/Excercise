import java.util.*;

public class E02 {
    public static void main(String[] args) {
        int[] pushA={1,2,3,4,5};
        // int[] popA={5,4,3,2,1};
        // int[] popA={2,3,1,5,4};
        int[] popA={3,1,2,5,4};
        // int[] popA={4,3,5,1,2}; //false
        boolean i=IsPopOrder(pushA,popA);
        System.out.println(i);
    }

    public static boolean IsPopOrder(int[] pushA, int[] popA) {
        if (pushA.length != popA.length)
            return false;
        int length = popA.length;
        boolean flag = true;
        Stack<Integer> A = new Stack<>();
        int i = 0, j = 0;
        for (; j < length; j++) {       //每次找一个popA[j]
            if(!A.isEmpty()&&A.lastElement()==popA[j]){ //found in top of stack
                System.out.print(A.pop()+"\t");
                continue;
            }
            while (i < length) {        //search in unseen pushA
                if (pushA[i] != popA[j]){
                    A.push(pushA[i]);   //push from current to nextfound,or to end
                    i++;
                }
                else {
                    A.push(pushA[i]);   //if found,push it into A
                    i++;
                    break;
                }
            }

            if(A.lastElement()==popA[j]){   //when found by searching unseen pushA
                // j++;
                System.out.print(A.pop()+"\t");
                continue;
            }
            else{   //not found in both unseen pushA and top of stack
                flag=false;
                System.out.println("\nerror:"+popA[j]);
                break;
            }

            
        }

        return flag;
    }
}