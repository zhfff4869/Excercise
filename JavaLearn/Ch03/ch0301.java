/* given a+b+c=180,a>=b>=c,get max(min(a-b,b-c)) */
public class ch0301 {
    public static void main(String[] args) {
        int a, b, c,distance=0;
        int[] temp={60,60,60};
        for (a = 0; a <= 180; a++) {
            for (b = 0; b <= 180 - a; b++) {
                c=180-a-b;
                if(!(a>=b)||!(a>=c)||!(b>=c))
                    continue;
                if(Math.min(a-b, b-c)<=distance)
                    continue;
                distance=Math.min(a-b, b-c);
                temp[0]=a;
                temp[1]=b;
                temp[2]=c;
            }
        }
        System.out.println(""+temp[0]+"\t"+temp[1]+"\t"+temp[2]);

    }
}