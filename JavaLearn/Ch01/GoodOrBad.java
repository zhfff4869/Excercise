package JavaLearn.Ch01;
import java.util.Scanner;

public class GoodOrBad {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

/*         while (scanner.hasNext()) {
            double x=scanner.nextDouble();
            System.out.println(0.5*Math.tanh(2*(x-0.5))+0.5);
        } */
        Person huazi=new Person(0.7);
        Person si=new Person(0.4);
        Person nene=new Person(0.8);
        Person guang=new Person(0.8);
        Person hui=new Person(0.9);
        huazi.kill(si);
        huazi.kill(huazi);
        huazi.save(nene);
        huazi.save(guang);
        hui.kill(huazi);
        System.out.println(huazi.getgood());
        System.out.println(hui.getgood());
        scanner.close();
    }

    public static class Person {
        private double good = 0.6;
        public Person(double x) {
            good = x;
        }

        public void kill(Person p) {
            good = 0.5*Math.tanh(2*(good*0.3/p.good-0.5))+0.5;
        }

        public void kill1(Person p){
            if(p.good<0.3)
                this.good=this.good*((1-p.good)+0.5);
            else
                this.good=this.good*(1-p.good);
        }

        public void save(Person p) {
            this.good=this.good*(p.good+0.7);   //save person whoes good >0.3 will add his good
        }

        public double getgood() {
            return good;
        }
    }
}