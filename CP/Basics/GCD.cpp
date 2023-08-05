#include<bits/stdc++.h>
using namespace std;
// To find gcd we can use 
int gcd(int a, int b){
    return __gcd(a,b);
}


// Stein’s Algorithm for finding GCD in (log(max(a,b))^2) where n is the number of bits
int gcd(int a, int b)
{
    /* GCD(0, b) == b; GCD(a, 0) == a,
       GCD(0, 0) == 0 */
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    /*Finding K, where K is the greatest power of 2 that divides both a and b. */
    int k;
    for (k = 0; ((a | b) & 1) == 0; ++k)
    {
        a >>= 1;
        b >>= 1;
    }

    /* Dividing a by 2 until a becomes odd */
    while ((a & 1) == 0)
        a >>= 1;
 
    /* From here on, 'a' is always odd. */
    do
    {
        /* If b is even, remove all factor of 2 in b */
        while ((b & 1) == 0)
            b >>= 1;
 
        /* Now a and b are both odd.
           Swap if necessary so a <= b,
           then set b = b - a (which is even).*/
        if (a > b)
            swap(a, b); // Swap u and v.
 
        b = (b - a);
    }while (b != 0);
 
    /* restore common factors of 2 */
    return a << k;
}


// finding gcd of a,b where a <= 10^12 and b = 10^250

ll reduceB(ll a, char b[])
{
    // Initialize result
    ll mod = 0;
 
    // calculating mod of b with a to make
    // b like 0 <= b < a
    for (int i = 0; i < strlen(b); i++)
        mod = (mod * 10 + b[i] - '0') % a;
 
    return mod; // return modulo
}

// This function returns GCD of 'a' and 'b'
// where b can be very large and is represented
// as a character array or string
ll gcdLarge(ll a, char b[])
{
    // Reduce 'b' (second number) after modulo with a
    ll num = reduceB(a, b);
 
    // gcd of two numbers
    return gcd(a, num);
}