import java.util.Arrays;
import java.util.Scanner;

public class E01 {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int totalnumber=scanner.nextInt();
        int[] Numbers=new int[totalnumber];
        for(int i=0;i<Numbers.length;i++){
            Numbers[i]=scanner.nextInt();
        }
        int[] sorted=Numbers.clone();
        Arrays.sort(sorted);
        for(int i=0;i<Numbers.length;i++){
            if(Numbers[i]!=sorted[i]){
                System.out.println("not sorted numbers");
                System.out.println(Arrays.toString(Numbers));
                
                break;
            }

        }
        System.out.println("sorted numbers");
        System.out.println(Arrays.toString(Numbers));
        scanner.close();
    }
}