import java.util.*;
public class E02{
    public static void main(String[] args) {
        int[] a = { 9, 5, 7, 8, 5, 6, 4 };
        // listsort(a);
        Arrays.parallelSort(a);
        for(int i:a){
            System.out.println(i);
        }
        System.out.println(Arrays.toString(a));
    }

    public static void listsort(int[] a){
        for(int i=0;i<a.length;i++)
        {
            int j=findminindex(i,a);
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }

    public static int findminindex(int i,int[] a) {
        int min=a[i];
        int index=i;
        for(int j=i;j<a.length;j++){
            if(a[j]<min){
                min=a[j];
                index=j;
            }
        }
        return index;
    }
}
