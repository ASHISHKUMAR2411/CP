// for finding a^b mod m
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// for find a^-1 mod m
// we use binary exponentiation 
long long mul_inv(long long a, long long m){
    long long inv = binpow(a, m - 2, m);
}

// for find a^-b mod m
long long neg_pow(long long a, long long b, long long b){
    
}