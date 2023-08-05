
/* nCr | Combination(n, r) | N choose R ~ n things taken r at a time without repetition */

/*
    - Mod operations are implicitly handled by ModInt struct mint
    - May also be used without by performing required mod ops where necessary
*/


    int maxN = 1e6;

    static vector<mint> fact{1, 1}, factinv{1, 1}, inv{0, 1};

    fact.reserve(maxN);
    factinv.reserve(maxN);
    inv.reserve(maxN);
    for (int z = fact.size(); z < maxN; z++)
    {
        // [Modular inverse](https://cp-algorithms.com/algebra/module-inverse.html#mod-inv-all-num)
        inv.push_back(inv[MOD % z] * (MOD - MOD / z));
        fact.push_back(z * fact[z - 1]);
        factinv.push_back(inv[z] * factinv[z - 1]);
    }

    auto nCr = [&](int n, int r)
    {
        return r < 0 or r > n ? 0 : fact[n] * factinv[r] * factinv[n - r];
    };




// Function to find the nCr
void printNcR(int n, int r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            // gcd of p, k
            long long m = __gcd(p, k);

            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;

            n--;
            r--;
        }

        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }

    else
        p = 1;

    // if our approach is correct p = ans and k =1
    cout << p << endl;
}