#include<bits/stdc++.h>
using namespace std;

void find_nCr(ll n, ll r, ll mod)
{
    nCr[0] = 1;
    for (ll i = 1; i <= 100000; i++)
    {
        nCr[i] = (i * nCr[i - 1]) % mod;
    }
}

int main(){
    int a;
    cin >> a;
    long long b = 0;
    cin >> b;
    cout << __builtin_ctz(a) << " : trailing zeroes" << endl;
    cout << __builtin_clz(a) << " : leading zeroes" << endl;
    cout << __builtin_popcount(a) << " : number of set bits \n";
    cout << __builtin_popcountll(b) << " : number of set bits in long long \n";

    // for finding if ith bit is set or not
    if( (n>>i) & 1){
        cout << "Yes\n";
    }

    // Or we can use 
    if( n & (1 << i)){
        cout << "Yes\n";
    }

    // Or for long long 
    if(n & (1LL << i)){
        cout << "Yes\n";
    }

    // To remove the last set bit 
    a = a&(a-1);

    // OR

    a = a ^ (1 << (__builtin_ctz(a) + 1));

    // To find the combination of all set bits of the number like 
    // like {1,2,4} bits are set and find all the below combination is the task then, 
    // 1 1 0 1 0 0
    // 1 0 0 1 0 0
    // 1 1 0 0 0 0
    // 1 0 0 0 0 0
    // 0 1 0 1 0 0
    // 0 1 0 0 0 0
    // 0 0 0 1 0 0
    // 0 0 0 0 0 0 
    int n = a;
    // finding all combination of the set bits of n
    for (int i = n; i; i = (i-1)&n){
        // every i is the combination 
    }

    // and to find combination of all the numbers from 1 to n then
    for (int i = 0; i < n; i++){
        // for each i 
        for (int j = i; j; j = (j-1)&a){
            // every combination of i
        }
    }

    // for or - sum of xor and and or total - nC2
    vector<int> cnt1(31, 0);
    for (int i = 0; i < n; i++){
        int x = nums[i];
        for (int i = 0; i < 31; i++){
            if((x >> i) & 1){
                cnt1[i]++;
            }
        }
    }
    long long ans1 = 0;
    for (int i = 0; i < 31; i++){
        ans1 += (cnt[i] * 1ll* (n - cnt[i])) * (1ll << i);
    }
    
    // for and
    vector<int> cnt2(31, 0);
    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        for (int i = 0; i < 31; i++)
        {
            if ((x >> i) & 1)
            {
                cnt2[i]++;
            }
        }
    }
    long long ans2 = 0;
    for (int i = 0; i < 31; i++)
    {
        ans2 += (findnCr(cnt[i], 2, mod)) * (1ll << i);
    }
    cout << ans2 + ans1 << endl;

    

}
#include <bits/stdc++.h>
using namespace std;
int prefSum[1000001][31];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n, q;
        int i;
        cin >> n;
        for (i = 0; i <= n; i++)
            for (int j = 0; j < 31; j++)
                prefSum[i][j] = 0;
        for (i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            int cnt = 0;
            while (a > 0)
            {
                prefSum[i][cnt] = a % 2;
                a /= 2;
                cnt++;
            }
        }
        for (i = 1; i <= n; i++)
        {
            for (int j = 0; j < 31; j++)
                prefSum[i][j] += prefSum[i - 1][j];
        }
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            double total = (r - l + 1.0) / (2);
            long long x1 = 0, x2 = 0, x3 = 0;
            for (i = 0; i < 31; i++)
            {
                int p = prefSum[r][i] - prefSum[l - 1][i];
                if (p < total)
                    x1 += (1LL << i);
                if (p != (r - l + 1))
                    x2 += (1LL << i);
                if (p)
                    x3 += (1LL << i);
            }
            long long ans = x1 + x2 + x3;
            cout << ans << "\n";
        }
    }
}