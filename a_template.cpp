// a template which help me in solving problem

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
using namespace std;
//? ARRAY 
// array rotation 
//1.) juggling algorithm O(n) and O(1) for array rotation 
void jugglingAlgorithm(int a[], int n ,int d)
{
    // where d is the number of rotation of array should happen 
    int k,temp,j;
    for(int i = 0;i<__gcd(d%n , n);i++)
    {
        temp = a[i];
        j = i;
        while(1)
        {
            k = j+d%n;
            if(k>=n) k = k-n;
            if(k == i) break;
            a[j] = arr[k];
            j = k;
        }
        a[j] = temp;
    }
}

// 2.) block Swap Algorithm O(n) and O(1) it swap towards 0 index i.e 1st values goes to the last i.e left Rotate
void Swap(int arr[], int fi, int si, int d)
{
    int i, temp;
    f(i, d)
    {
        temp = arr[fi + i];
        arr[fi + i] = arr[si + i];
        arr[si + i] = temp;
    }
}
void blockSwapAlgorithm(int a[], int n, int d)
{
    int i, j;
    if (d == 0 || d == n)
        return;
    i = d;
    j = n - d;
    while (i != j)
    {
        if (i < j)
        {
            Swap(a, d - i, d + j - i, i);
            j -= i;
        }
        else
        {
            Swap(a, d - i, d, j);
        }
    }
    Swap(a, d - i, d, i);
}

// 3.) reversal algorithm O(n) & O(1) , in this we divide the array ar[0..d] and ar[d+1...n] and then we first reverse ar[0..d] and reverse the ar[d+1,n] part and then we reverse the array and this is how we get the array ...
// this is also helped to rotate the array in left
void reverseArray(int arr[], int start, int end)
{
    int temp = 0;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void reversalAlgorithm(int arr[], int n, int d)
{
    if (d == 0)
    {
        return;
    }
    d = d % n;
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
}

// ? NUMBER THEORY

// always use "\n" than endl ,

// for sieve of eratosthenes where we have to find the kth prime or check for primes then this is used

#define MAX 1000000

int isPrime[MAX + 1];
/* or we can use bool isPrime[max+1] */
//  the algo takes sqrt(n)  time complexity but sieve takes O(n) times due to its initialisation
void sieve()
{
    int maxN = MAX;
    fi(i, maxN) isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxN; j += i) // we are looking for multiple of i so that we can mark them as 0 as they are not prime .
            {
                isPrime[j] = 0;
            }
        }
    }
}

// sieve for factorization optimized one (better)
int ar[(int)1e6 + 1];
void sieveFactorization()
{
    int maxN = 1e6;
    for (int i = 1; i <= maxN; i++)
        ar[i] = -1;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (ar[i] == -1)
        {
            for (int j = i * i; j <= maxN; j += i) // for each multiple of i starting from the square of i after which it is actually effective
            {
                if (ar[j] == -1)
                    ar[j] = i;
            }
        }
    }
}

// original sieve for factorization
int ar[(int)1e6 + 1];
void sieveFactorisation()
{
    int maxN = 1e6;
    fi(i, maxN) ar[i] = -1;
    for (int i = 2; i <= maxN; i++)
    {
        if (ar[i] == -1)
        {
            for (int j = i; j <= maxN; j += i) // this steps means for each multiple of i .
            {
                if (a[j] == -1)
                    a[j] = i;
            }
        }
    }
}

// segmented sieve to find the prime number between a particular range where range is not larger than 1e6 but range limit can go upto 1e12 as this much big number of array is not possible so we use segmented sieve .

// 1 step is to generate sieve upto 1e6 which is already done above we will add one thing more in it which is adding the primes in separate list .
vi primes;
int prime[(int)1e6 + 1];
void sieveForSegment(int maxN)
{
    vi ar(maxN + 1, 0); // creating an array for the the range
    ar[1] = 1;
    for (int i = 2; i <= maxN; i++)
    {
        if (ar[i] == 0)
        {
            for (int j = 2 * i; j <= maxN; j += i)
            {
                ar[j] = 1;
            }
        }
    }
    fi(i, maxN) if (ar[i] == 0) primes.push_back(i);
}

// now creating an init function for the segmented sieve to work
void segmentedSieve(int L, int R)
{
    if (L == 1)
        L++;
    int maxN = R - L + 1;
    vi ar(maxN, 0);
    for (lli p : primes)
        if (p * p <= R)
        {
            int i = (L / p) * p;
            if (i < L)
                i += p;
            for (; i <= R; i += p)
            {
                if (i != p)
                    ar[i - L] = 1;
            }
        }
    f(i, maxN) 
        if (ar[i] == 0)
        cout<< L + i << endl; // here L+i is the prime in the range L to R
}

// for calculating (A^N)%P in log(n) complexity
lli modularExponent(lli a, lli n, lli p)
{
    lli res = 1;
    while (n)
    {
        if (n % 2)
            res = (res % p * a % p) % p, n--;
        else
            a = (a % p * a % p) % p, n /= 2;
    }
    return res;
}

// for calculating the power of a number i.e A^N  in log(n) approach
lli power(lli a, lli n)
{
    lli res = 1;
    while (n)
    {
        if (n % 2)
            res = res * a;
        n = n >> 1;
        a = a * a;
    }
    return res;
}

// for finding whether the number is prime or not in sqrt(n) in complexity
bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// prime factors of N in O(sqrt(n))
void primeFac(int N)
{
    for (int i = 2; i * i <= N; i++)
    {
        int cnt = 0;
        while (N % i == 0)
        {
            cnt++;
            N /= i;
        }
        if (cnt > 0)
            factors.push_back((i * cnt));
    }
    if (N > 1)
        factors.push_back(N);
}

// gcd O(min(A,B)) with recursion not a good approach or competitive use __gcd(a,b) instead
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// for finding the common divisor of K,N where N is given beforehand and k is given at each query 
// in O(log(n)^2)


// for calculating gcd of two number here x will give us the gcd
long int d, x, y;
void extendedEuclid(long int A, long int B)
{
    if (B == 0)
        d = A, x = 1, y = 0;
    else
    {
        extendedEuclid(B, A % B);
        long int temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}

// for calculting modular inverse of a number modulo mod
long int modInverse(long int A, long int M)
{
    if (prime(M))
        return modularExponentiation(A, M - 2, M);
    extendedEuclid(A, M);
    return ((x % M + M) % M);
}

// for euler totient function in which we have to find the number of integers between 1 to n (inclusive ) which are coprime with n .
// for this we are using ETF function which takes O(sqrt(n)) time to calculate that .
int ETF(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res /= i;
            res *= (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res /= n, res *= (n - 1);
    return res;
}

// ETF in (n*log(log(n))) which is good
int phi[(int)1e6 + 1];
void etfBetter(int n)
{
    fi(i, n) phi[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}

// for binomial coefficient of modulo some number nCk%p type
// let suppose we have to find the nCk where n can be 1e6 so we have to predefine if we have no of queries which is also 1e6 or 1e7 this will not be good approach to find the coefficient inside the loop of query it will result in tle nobody want that to happen
int AR[(int)1e6 + 1];
int C(int n, int k)
{
    int res = 1;
    res = (res * 1LL * AR[n]) % mod;
    res = (res * 1LL * modularExponentiation(A[k], mod - 2, mod)) % mod;
    res = (res * 1LL * modularExponentiation(A[n - k], mod - 2, mod)) % mod;
    return res;
}

//  when we have to find the gcd of all the number 1 to n (inclusive) with n , then we can use this method  in O(sqrt(n)) time complexity
int getCount(int d, int n)
{
    return phi[n / d];
}

// driver program
int main()
{
    fast;
    /* code  */
    // for binomial coefficient
    AR[0] = AR[1] = 1;
    for (int i = 2; i <= 1e6; i++)
        AR[i] = (AR[i - 1] * 1LL * i) % mod;
    int q, n, k;
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        cout << C(n, k) << endl;
    }

    // for etfBetter ETF better approach
    etfBetter(1e6);
    int q, n;
    cin >> q;
    while (q--)
    {
        cin >> n;
        cout << phi[n] << endl;
    }

    // for summation of gcd of 1 to N with N
    int q, n, res, d1, d2;
    cin >> q;
    while (q--)
    {
        cin >> n;
        res = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                d1 = i;
                d2 = n / i;
                res += d1 * getCount(d1, n);
                if (d1 != d2)
                    res += d2 * getCount(d2, n);
            }
        }
        cout << res << endl;
    }

    return 0;
}
