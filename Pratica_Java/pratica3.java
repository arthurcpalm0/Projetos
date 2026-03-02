import java.util.Scanner;
public class pratica3{
    static int quadrado(int n){
        return (int) Math.pow(n,2);
    }
    public static void main(String[] args){
        Scanner s = new Scanner (System.in);
        int n = s.nextInt();
        int nq=quadrado(n);
        System.out.printf("Número ao quadrado: %d\n",nq);
        s.close();
    }
}