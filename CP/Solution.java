
import java.io.*;
import java.math.*;
import java.util.*;


class Result {

    /*
     * Complete the 'extraLongFactorials' function below.
     *
     * The function accepts INTEGER n as parameter.
     */

    public static void extraLongFactorials(int n) {
    // Write your code here
    BigInteger f = new BigInteger("1"); // Or BigInteger.ONE

        // Multiply f with 2, 3, ...N
        for (int i = 2; i <= n; i++)
            f = f.multiply(BigInteger.valueOf(i));

        System.out.println(f);

    }

}

class Solution {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i =0;i<n;i++){
            int t = sc.nextInt();
            Result.extraLongFactorials(t);
        }
        sc.close();
    }
}
