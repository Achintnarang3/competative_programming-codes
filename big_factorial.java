import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    static void big_factorial(int n){
        BigInteger s = new BigInteger("1");
        for( int i=1 ; i<=n ; i++){
           s = s.multiply(BigInteger.valueOf(i));
        }
        System.out.println(s);
    }
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        big_factorial(a);
    }
}