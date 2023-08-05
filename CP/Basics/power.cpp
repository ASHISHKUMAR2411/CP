//  to compute the a^n in using different approach

// naive approach

int powerN(int a , int n){
    if(n==0) return 1;
    int res = 1;
    for (int i = 1; i <= n;i++)
    {
        res = res * a;
    }
    return res;
}


// using optimized but recursion solution

int powerR(int a, int n ){
    if(n==0)
        return 1;
    int temp = powerR(a,n/2);
    temp =  temp * temp;
    if(n%2)
        return temp * a;
    else{
        return temp;
    }
}

// Iterative solution for power of a^n

int powerI(int a, int n)
{
    int res = 1;
    while(n){
        if(a&1)
            res = res * a;
        a = a*a;
        n >>= 1;
    }
    return res;
}
