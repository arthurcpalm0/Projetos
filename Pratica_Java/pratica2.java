public class pratica2{
    public static void main (String[] args){
        int i;
        for (i = 0;i<100;i++){
            if (i%3==0&&i%5!=0){
                System.out.println("Java");
            }
            else if(i%5==0&&i%3!=0){
                System.out.println("Code");
            }
            else if (i%5==0&&i%3==0){
                System.out.println("JavaCode");
            }
        }
    }
}