using System;
 
class Ashish
{

    static double inverseSqrt5 = 1 / Math.Sqrt(5);
    static double phi = (1 + Math.Sqrt(5)) / 2;
    /* should use 
       const double inverseSqrt5 = 0.44721359549995793928183473374626
       const double phi = 1.6180339887498948482045868343656
    */

    static int Fibonacci(int n)
    {
        return (int)Math.Floor(Math.Pow(phi, n) * inverseSqrt5 + 0.5);
    }

    // Driver method
    public static void Main()
    {
        long  t = Console.ReadLine();
        while(t--){
            long n = Console.Readline();
            Console.WriteLine(Convert.ToInt64(Fibonacci(n)));
        }
    }
}