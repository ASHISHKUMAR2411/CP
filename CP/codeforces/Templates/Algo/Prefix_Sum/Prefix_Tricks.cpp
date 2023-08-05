// https://docs.google.com/document/d/1dmwKC-iXc4ZgF2a2AK-NoVM3YgETm0WutsGeU7ssdEY/edit
#include<bits/stdc++.h>
using namespace std;

// Basic Prefix Sum
void prefix_sum(vector<int> &prefix_arr)
{
    for (int i = 1; i < a.size(); i++)
    {
        prefix_arr[i] += prefix_arr[i - 1];
    }
}


// If we have to find the number of sub array from l to r such that their sum % n == 0, it is same as finding the subarray with sum k,
// Idea we use prefix sum and map in order to find the

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{

    // Used to store a number of subarrays starting from index zero having a particular value of sum.
    unordered_map<int, int> prevSum;
    int n = arr.size();
    int res = 0;

    // To keep track of the sum of elements so far.
    int currsum = 0;

    for (int i = 0; i < n; i++)
    {

        // Add the current element to sum so far.
        currsum += arr[i];

        // If the current sum is equal to the desired sum,
        // then a new subarray is found.
        // So, increase the count of subarrays.
        if (currsum == k)
        {
            res += 1;
        }

        /*
            If current sum exceeds given sum by current sum  - sum then
            find the number of subarrays having this sum in our map and exclude these subarrays.
        */
        if (prevSum.find(currsum - k) != prevSum.end())
        {
            res += prevSum[currsum - k];
        }

        // Add current sum value to count of different values of sum.
        prevSum[currsum] += 1;
    }

    return res;
}


// Given N Line Segments (n <= 10^5) and we need to find those sum of lengths of the segments which >= k segments together, like >= 1 segments are those lengths which are under 1 segments and all the possible segments together, like that we need to find all those for k segments li, ri (li,ri <= 10^18) are the points give to us, we need to find for values of k. 

void solve_for_segments(){
    long long n = 0, k =0;
    cin >> n >> k;
    vector<pair<long long, long long>> vp;
    for (long long i = 0; o < n; i++){
        long long l, r;
        cin >> l >> r;
        vp.push_back({l, +1});
        vp.push_back({r, -1});
    }
    sort(vp.begin(), vp.end());
    long long segments[n + 1], ans[n+1];
    memset(segments, 0, sizeof(segments));
    int count = 0; // to count the current segments together
    for (int i = 0; i < vp.size(); i++){
        int j = i; 
        while(j < vp.size() && vp[i].first == vp[j].second){
            count++;
            j++;
        }
        j = i - 1;
        if((i + 1 ) < vp.size()){
        int segment = vp[i + 1].first - vp[i].first;
        segments[count] += segment;
        }
    }
    for (int i = 0; i <= n; i++){
        if(i){
            segments[i] += segments[i - 1];
        }
    }
    for (int i = 1; i <= k; i++){
        ans[i] = i > 1 ? segments[n] - segments[i - 1] : segments[n];
    }
    for (int i = 0; i <= k; i++){
        cout << ans[i] << "\n";
    }
}

// For Q queries to find the sum between L to R we find prefix[R] - prefix[L-1] check for L == 0
void find_sum_L_R(vector<int> &a, int q){
    prefix_sum(a);
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        if(l > 0)
            cout << a[r] - a[l - 1] << endl;
    }
}



// For Q queries, If we need to add x to L to R, then we create a prefix array and add X to prefix[L] and add -X to prefix[R+1], then we find prefix_sum of this prefix array. at the end, if we need to print the array, otherwise if it ask something in between every query then it will be difficult for it to find. 

void solve_L_R(vector<int> &a, vector<int> &prefix, int query){
    for (int i = 0; i < q; i++){
        int x, l, r;
        cin >> x >> l >> r;
        prefix[l] += x;
        if(r != a.size() - 1){
            prefix[r + 1] -= x;
        }
    }
    prefix_sum(prefix);
}


// If given Q queries, we need to find the arthimetic progression from L to R i.e A[L] + 2*A[L+1] + 3*A[L+3] + 4*A[L+4] .. + (R-L+1)*A[R]
// expression ∑ (i - L + 1) * A[i] from L to R, breaking this 

void solve_L_R_AP(vector<int> &a, int q){
    vector<int> b = a;
    for (int i = 0; i < a.size(); i++){
        b[i] = i * a[i];
    }
    prefix_sum(b);
    prefix_sum(a);
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        if(l >= 0)
            cout << (1 - l) * (a[r] - a[l - 1]) + (b[r] - b[l - 1]) << endl;
    }
}

// Q quFor L to R  A[L] + (K^1)*A[L+1] + (K^2)*A[L+3] + (K^3)*A[L+4] .. + (K^(R-L))*A[R]
// Form a expression and find out the constant part out of the submission and these are the part which depend on the query.
void solve_L_R_GP(vector<int> &a, int q, int k)
{
    vector<int> b = a;
    for (int i = 0; i < a.size(); i++)
    {
        b[i] = pow(k,i) * a[i];
    }
    prefix_sum(b);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l >= 0)
            cout << pow(k, -l) * (b[r] - b[l - 1]) << endl;
    }
}

// finding k^-i using binary_exponentiation
// - step 1 : first find k inverse = k ^ -1 in O(log(k))
// then find k ^ -2 = k[2 - 1] * (K ^ -1);
// so expression is K_inv[n] i.e K^(-n) = K_inv[n-1] * x;
// binary_exponentiation 
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

void solve(vector<long long> &a, long long k, long long q, long long mod)
{
    // find k^-1, k^-2, k^-3, k^-4;
    vector<long long> k_inv(n + 1);
    k_inv[1] = binpow(k, mod - 2, mod);
    for (long long i = 2; i < a.size(); i++)
    {
        k_inv[i] = (k_inv[i - 1] *1ll* k_inv[1]) % mod;
    }
    // check for termination of the loop
    for (long long i = 1; i < a.size(); i++)
    {
        a[i] = pow(k, i) *1ll* a[i] % mod;
    }
    prefix_sum(a);
    for (int i = 0; i < q; i++){
        long long l, r;
        cin >> l >> r;
        cout << k_inv[l] * 1ll * (a[r] - a[l - 1]) % mod << endl;
    }
}


void solve_partial_L_R_AP(long long q, long long n){
    vector<long long> A(n, 0), B(n, 0);
    for (long long i = 0; i < q; i++) {
        long long a, d l, r;
        cin >> a >> d >> l >> r;
        A[l] += (a - l * d);
        B[l] += d;
        if(r < (n - 1)){
            a[r + 1] -= (a - l * d);
            b[r - 1] -= d;
        }
    }
    prefix_sum(A);
    prefix_sum(B);
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++){
        p[i] = A[i] + i * B[i];
    }
}

void solve_L_R_partial_GP(long long q, long long r, long long mod){
    vector<long long> r_pow(n+1, 1);
    for (long long i = 1; i <= n; i++){
        r_pow[i] = r * r_pow[i - 1] % mod;
    }
    vector<long long> p(n, 0);
    for (long long i = 0; i < q; i++)
    {
        long long  a, l, ri;
        cin >> a >> l >> ri;
        p[l] = (p[l] %mod +  a % mod) % mod;
        p[ri + 1] = (p[ri+1] % mod - (a * r_pow[ri + 1 - l] % mod) + mod) % mod;
    }
    for (long log i = 1; i < n; i++){
        p[i] = (p[i]% mod + p[i - 1] * r % mod) % mod; 
    }
}

// 2D prefix sum 
int solve(){
    int n, m;
    cin >> n >> m;
    ll a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    ll p[n][m];
    // creating 2D prefix sum
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            p[i][j] += a[i][j];
            if(i > 0){
                p[i][j] += p[i - 1][j];
            }
            if(j > 0){
                p[i][j] += p[i][j - 1];
            }
            if(i > 0 and j > 0){
                p[i][j] -= p[i - 1][j - 1];
            }
        }
    }
    
    // for q queries
    int q = 0;
    cin >> q;
    for (int i = 0; i < q; i++){
        int u, l, d, r;
        cin >> u >> l >> d >> r;
        int sum += p[d][r]; 
        if(l >= 1){
            sum -= p[d][l - 1];
        }
        if(u >= 1){
            sum -= p[u - 1][r];
        }
        if(u >= 1 and l >= 1){
            sum += p[u - 1][l - 1];
        }
        cout << sum << endl;
    }
}


// 2D Partial sum 
void solve_2D_parital(int m, int n ){

    ll p[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            p[i][j] = 0;
        }
    }
    //  for q queries
    for (int i = 0; i < q; i++){
        int l, r, u, d, x;
        cin >> l >> r >> u >> d >> x;
        p[u][l] += x;
        if((r+1) < m){
            p[u][r + 1] -= x;
        }
        if(d+1 < n){
            p[d + 1][l] -= x;
        }
        if((r+1) < m and (d+1) < n){
            p[d + 1][r + 1] += x;
        }
    }

    // for building final 2D 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(i >= 1){
                p[i][j] += p[i-1][j]
            }
            if(j >= 1)
                p[i][j] += p[i][j - 1];
            if(i >= 1 and j  >= 1){
                p[i][j] -= p[i - 1][j - 1];
            }
        }
    }
}

// for 2D Triangular prefix sum
// rectangular column - (p[i-1][j] - p[i-1][j-2])
// previous triangular - p[i-1][j-1]
// p[i][j] = a[i][j] + (p[i-1][j] - p[i-1][j-2]) + p[i-1][j-1]

void solve_2D_triangular_prefix(long long m, long long n, long long q)
{
    long long a[n][m], p[n][m], r[n][m];
    for (long long i = 0; i < n; i++){
        for (long long j = 0; j < m; j++){
            cin >> a[i][j];
            p[i][j] = 0;
            r[i][j] = 0;
            r[i][j] += a[i][j];
            p[i][j] += a[i][j];
            if( i > 0 and j > 0){
                p[i][j] += p[i - 1][j - 1];
                r[i][j] -= r[i - 1][j - 1];
            }
            if(j > 0){
                p[i][j] += p[i][j - 1];
                r[i][j] += r[i][j - 1];
            }
            if(i > 0){
                r[i][j] += r[i - 1][j];
            }
            if(j > 0 and i > 1){
                p[i][j] += p[i-2][j-1]
            }
        }
    }
    
    // finding the prefix sum
    for (long long i = 0; i < q; i++){
        long long l, x, y, sum = 0;
        cin >> x >> y >> l;
        sum += p[x][y];
        if((x-l) >= 0 and (y - l) >= 0){
            sum -= p[x - l][y - l];
            sum += r[x - l][y - l];
        }
        if ((x - l) >= 0){
            sum -= r[x - l][y];
        }
        cout << sum << endl;
    }
}

// 2D prefix sum another way
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    ll arr[n + 1][m + 1];
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    { // row wise prefix sum
        for (int j = 2; j <= m; j++)
            arr[i][j] += arr[i][j - 1];
    }
    for (int i = 1; i <= m; i++) // column wise prefix sum
        for (int j = 2; j <= n; j++)
            arr[j][i] += arr[j - 1][i];
    while (q--)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
        ans %= mod;
        if (ans < 0)
            ans += mod;
        cout << ans << "\n";
    }
}


