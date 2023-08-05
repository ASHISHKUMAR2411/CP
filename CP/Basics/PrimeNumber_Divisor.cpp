//  for finding nth prime number where n <= 10^4
int maxN = 1e6
vector<int> primes;
int prime[(int)1e6 + 1];
void sieveForSegment(int maxN)
{
    vector<int> ar(maxN + 1, 0); // creating an array for the the range
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

// for chcking whether number is prime or not 
bool isprime(int n){
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2== 0 || n%3 == 0) return false;
    for(int i = 5; i*i <= n ; i+= 6){
        if(n%i == 0 || n%(i+2) == 0)
            return false;
    }
    return true;
}


// for prime factor 

void primeFactor(int n){
    if(n<=1) return;
    for(int i = 2; i * i <= n;i++){
        while (n%i == 0)
        {
            /* code */
            cout << i << endl;
            n = n / i;
        }
    }
    if(n>1) cout << n << endl;
}

// more optimised way 
void PrimeFactor(int n){
    if(n<=1) return;
    if(n%2==0){
        while(n%2==0){
            cout << 2 << endl;
            n /= 2;
        }
    }
    if(n%3==0){
        while(n%3==0){
            cout<<3<< endl;
            n /= 3;
        }
    }
    for (int i = 5; i*i <= n;i+=6){
        while(n%i==0){
            cout << i << endl;
            n /= i;
        }
        while(n%(i+2) == 0){
            cout << i + 2 << endl;
            n /= (i + 2);
        }
    }
    if(n>3)
        cout << n << endl;
}
// finding factors/divisor of n in any order

void Factors(int n){
    for (int i = 1; i * i <= n;i++){
        if(n%i==0){
            cout<<i<<endl;
            if(i!=n/i)
                cout<<n/i<<endl;
        }
    }
}


// for finding divisor in sorted way using O(divisor) auxillary space

void divisor(int n){
    int count = 0;
    vector<int> factors;
    if(n<1)
        return;
    factor.push_back(1);
    while(n%2==0){
        count++;
        factor.push_back(pow(2,count));
        n /= 2;
    }
    count = 0;
    while(n%3==0){
        count++;
        factor.push_back(pow(3, count));
        n /= 3;
    }
    count = 0;
    for (int i = 5;i*i<=n;i+=6)
    {
        count = 0;
        while(n%i == 0){
            count++;
            factor.push_back(pow(i,count));
            n /= i;
        }
        count = 0;
        while(n%(i+2) == 0){
            count++;
            factor.push_back(pow(i + 2, count));
            n /= (i + 2);
        }
    }
    if(n>3)
        factors.push_back(n);
    sort(factors.begin(), factors.end());
    for (auto i = factors.begin(); i != factors.end();i++){
        cout << *i << " ";
    }
}

// printing divisor in O(1) auxiliary space with sqrt(n) time complexity with sorted way

int PrintDivisor(int n){
    int i;
    for (i = 1; i * i < n; i++){
        if(n%i == 0) cout << i << " ";
    }
    for (; i >= 1; i--){
        if (n%i == 0) cout << n/i << " ";
    }
}




