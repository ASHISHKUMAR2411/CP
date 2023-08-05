// Question 8 For Prime Number upto N
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num, i, n;
    // Take input from user
    cout << "Find prime numbers upto : ";
    cin >> n;
    cout << endl << "All prime numbers upto " << n << " are : " << endl;
    // using segmented sieve to find prime numbers upto n it calculates prime number in O(n * Log(Log(n))) time which lot better than naive approach 
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for(int i = 0 ; i<n;i++){
        if (is_prime[i])
            cout << " " <<i ;
    }
    return 0;
}