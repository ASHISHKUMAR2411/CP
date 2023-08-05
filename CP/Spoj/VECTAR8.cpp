#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl '\n'
#define ll long long int
using namespace std;
const int MAXN = 1e6 + 5;
int isPrime[MAXN];

void sieve()
{
    isPrime[0] = isPrime[1] = 1;
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (isPrime[i] == 0)
        {
            if (i * 1LL * i <= 1000000)
            {
                for (int j = i * i; j <= 1000000; j += i)
                    isPrime[j] = 1;
            }
        }
    }
}

int cnt[MAXN];

bool toBeAfraid(ll num)
{
    ll dig = 0;
    ll tmpNum = num;
    while (num > 0)
    {
        if (num % 10 == 0)
            return false;
        dig++;
        num /= 10;
    }
    ll div = exp(10LL, dig - 1);
    num = tmpNum;
    while (num > 0)
    {
        num %= div;
        div /= 10;
        if ((num != 0 && isPrime[num] == 1))
            return false;
    }
    return true;
}

void precal()
{
    for (int i = 2; i <= 1000000; i++)
    {
        cnt[i] = cnt[i - 1];
        if (isPrime[i] == 0)
        {
            if (toBeAfraid(i))
                cnt[i]++;
        }
    }
}

int main()
{
    fast;
    sieve();
    precal();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << cnt[n] << endl;
    }
    return 0;
}
// #include<bits/stdc++.h>
// #define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define endl '\n'
// using namespace std;
// vector<int> p;
// bool isPrime(int n)
// {
//     if (n < 2)
//         return false;
//     if (n == 2)
//         return true;
//     if (n % 2 == 0)
//         return false;
//     for (int i = 3; i <= n / i; i += 2)
//         if (n % i == 0)
//             return false;

//     return true;
// }
// void sieve(){
//     p.push_back(2);
//     p.push_back(3);
//     p.push_back(5);
//     p.push_back(7);
//     int num = 0;
//     for(int i = 3 ; i<=7;i+=4){
//         num = i;
//         for(int j = 1;j<=6;j++){
//             for(int k = 1;k<=9;k++){
//                 num += k*pow(10,j);
//                 if(isPrime(num))
//                     p.push_back(num);
//             }
//         }
//     }
//     sort(p.begin(), p.end());
//     unique(p.begin(), p.end());
// }
// int main(){
//     fast;
//     sieve();
//     int t,n,count;
//     cin>>t;
//     while(t--){
//         count = 0;
//         cin>>n;
//         for(int i = 0 ; i<(int)(p.size());i++){
//             if(p[i]>n){
//                 break;
//             }
//             count++;
//         }
//         cout<<count<<endl;
//     }

// }