#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;


// to calculate a^n % p
int power(int a, unsigned int n, int p);

// to find gcd of a and b using euclidean method 
int gcd(int a, int b);

// for basic primality test - O(n)
bool isPrimeI(int n);

// for optimised primality test - O(√n)
bool isPrimeII(int n);

// for Fermat primality test - O(k*log(n))
bool isPrimeIII(int n, int k);

// for miller robin test - O(k*log(n))
bool millerTest(int d, int n);
bool isPrimeIV(int n, int k);

int main()
{
    srand(time(0));
    // to check performance between two methods we will check it time complexity, space complexity & actual time of execution on a local machine
    int n;
    cout << "Enter the number whose performance you want to test for miller rabin & others : ";
    cin >> n;
    std::chrono::duration<long, std::micro> int_usec;
    // For 1st Method -
    cout << "For 1st Method\n";
    auto start = high_resolution_clock::now();
    if (isPrimeI(n))
        cout << n << " is Prime\n";
    else
        cout << n << " is not Prime\n";
    cout << "Time taken by first Basic method is millisecond is: ";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    int_usec = duration;
    cout << int_usec.count() << " microseconds" << endl;
    cout << endl;

    // 2nd Method -
    cout << "For 2nd Method\n";
    start = high_resolution_clock::now();
    if (isPrimeII(n))
        cout << n << " is Prime\n";
    else
        cout << n << " is not Prime\n";
    cout << "Time taken by Optimized Basic method is millisecond is: ";
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    int_usec = duration;
    cout << int_usec.count() << " microseconds" << endl;
    cout << endl;
    
    // 3rd Method
    cout << "For 3rd Method\n";
    start = high_resolution_clock::now();
    // taking k = 100 iterative for better ans
    if (isPrimeIII(n, 100))
        cout << n << " is Prime\n";
    else
        cout << n << " is not Prime\n";
    cout << "Time taken by Fermat's method is millisecond is: ";
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    int_usec = duration;
    cout << int_usec.count() << " microseconds" << endl;
    cout << endl;

    // 4rt Method
    cout << "For4rt Method\n";
    start = high_resolution_clock::now();
    // taking k = 100 iterative for better ans
    if (isPrimeIV(n, 100))
        cout << n << " is Prime\n";
    else
        cout << n << " is not Prime\n";
    cout << "Time taken by Miller-Robin method is millisecond is: ";
    
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    int_usec = duration;
    cout << int_usec.count() << " microseconds" << endl;
    cout << endl;
}

/* Iterative Function to calculate (a^n)%p in O(logy) */
int power(int a, unsigned int n, int p)
{
    int res = 1; // Initialize result
    a = a % p;   // Update 'a' if 'a' >= p

    while (n > 0)
    {
        // If n is odd, multiply 'a' with result
        if (n & 1)
            res = (res * a) % p;

        // n must be even now
        n = n >> 1; // n = n/2
        a = (a * a) % p;
    }
    return res;
}

/*Recursive function to calculate gcd of 2 numbers*/
int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    else if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}



// Methods 

// 1. 
// Basic Test : to check if number is prime using basic intuition that prime numbers are divisible by 1 and the number itself, so there are only two numbers between 1 to N which divides N,
// Time Complexity : O(n)
// Space Complexity : O(1)

bool isPrimeI(int n){
    int count = 0;
    for (int i = 1; i <= n; i++){
        if(n%i == 0){
            count++;
        }
    }
    if(count == 2)
        return true;
    else
        return false;
}


// 2. 
// Optimized Basic Tet: Another approach is to instead of checking till n, we can check till √n because a larger factor of n must be a multiple of a smaller factor that has been already checked.
// Time Complexity : O(√n)
// Space Complexity : O(1)

bool isPrimeII(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

// 3. 
// Fermat's Primarily Test
// drawback for fermat test is that it is in fermat test we check for every number between 1 to N such that a^N-a is divisible by a or not which is a tedious task.
// Time Complexity : O(k*log(n)) where higher k gives more better result
// Space Complexity : O(1)


// If n is prime, then always returns true, If n is
// composite than returns false with high probability
// Higher value of k increases probability of correct
// result.
bool isPrimeIII(int n, int k)
{
    // Corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    // Try k times
    while (k > 0)
    {
        // Pick a random number in [2..n-2]
        // Above corner cases make sure that n > 4
        int a = 2 + rand() % (n - 4);

        // Checking if a and n are co-prime
        if (gcd(n, a) != 1)
            return false;

        // Fermat's little theorem
        if (power(a, n - 1, n) != 1)
            return false;

        k--;
    }

    return true;
}

// 4.
//  Miller-Rabin primality test
// In Miller-Rabin Test we 
// 1st Step : find the m, k from n-1 = (2^k )* m
// 2nd Step : Choose a number A from 1 < A < n-1
// 3rd Step : bi =( bi-1)^2 (mod n) until we get -1 or 1 for composite and prime respectively.   

//  Time Complexity : O(k*log(n)) where higher k gives more better result
//  Space Complexity : O(1)

bool millerTest(int d, int n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    int a = 2 + rand() % (n - 4);

    // Compute a^d % n
    int x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }

    // Return composite
    return false;
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrimeIV(int n, int k)
{
    // Corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Iterate given number of 'k' times
    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return false;
    return true;
}

