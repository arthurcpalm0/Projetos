import java.util.Scanner;
public class pratica1{
    public static void main (String[] args){
        int n;
        Scanner s = new Scanner (System.in);
        do{
            n = s.nextInt();
            if (n%2==0){
                System.out.println("O número é par");
            }
            else{
                System.out.println("O número é impar");
            }
        } while(n!=0);
        s.close();
    }
}
