#include <bits/stdc++.h>
using namespace std;

// for bianry search, we need to find the monotonos space in order to solve the particular problem, what we need to do is to define a functin which convert it into monotones space,
// for example
// Find the position where the sorted array was rotated,
void _find_rotational(vector<int> &nums)
{
    // function would be f(x) = arr[i] >= arr[0], this will give the space where we could define yes and no, and the boundary will be the answer.

    // finding the boundary point of the rotation
    int l = 0, r = nums.size() - 1, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] >= arr[0])
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << "The position for the rth value i.e rotation value is : " << ans << endl;
}

// Find the position where the array was tone changes i.e where the array increasing order changes to decreasing order,
void _find_rotational(vector<int> &nums)
{
    // function would be f(x) = arr[i] >= arr[x - 1], this will give the space where we could define yes and no, and the boundary will be the answer.

    // finding the boundary point of the rotation
    int l = 1, r = nums.size() - 1, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] > arr[mid - 1])
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << "The position for the rth value i.e rotation value is : " << ans << endl;
}

// given n points in the number line, and k points, insert those k points such that it will minimize the maximum distance between two points, we are given the array in n points in a sorted fashion,

// Basic Intuition O(nlogn) is that, we have given n - 1 differences between n consecutive point. suppose if we assume a number x to be the minimum distance, then how many points I have to place in that number line, so that we can minimum distance is x, if those number is greater then k, then x can't be the minimum distance. Instead of going linearly we use binary search to search for x,

// for two point to have x maximum difference, we need to divide the point in ceil(diff/x) - 1

bool check_for_k(int x, int arr[], int n, int k)
{
    int need = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int diff = arr[i + 1] - arr[i];
        need += (diff + x - 1) / x - 1;
    }
    return need <= k;
}

void _solve_for_k_points()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // for safety we sort the array
    sort(arr, arr + n);

    // then we need to find the value x x can be from [1, 1e9], we have to search, it is not possible in O(n), so we try to search in binary search
    int lo = 1;
    int hi = 1e9;
    int ans = 1e9;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check_for_k(mid, arr, n, k))
        {
            ans = mid;
            ho = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << "The maximum distance possible is : " << ans << endl;
}

// Given n elements in one array , and m elements in second array, we need to find all possible A[i] + B[j], for all pair(i,j), then sort the sum, and then find kth term in that sum.

// Intuition - the intuition behind the approach is that, first we sort both the array and then we find the lets say a[i] + b[j] = v be the sum at the kth position, this value v can be before kth position also and after that, also, so our approach is to count all sum whose sum  <= v and count of all those pair is < k, in order to do that, we need to take one element of A array and suppose v be the value which is the ans, we need to count all elements of B whose sum is <= v and count of such pair is < k, so for that our answer will be the, we need to do all this with both the array

bool check_for_v(int v, int k, int a[], int b[], int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += upper_bound(b, b + n, v - a[i]) - b;
    }
    return count < k;
}

void _solve_for_k()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    int k;
    cin >> k;
    int lo = a[0] + b[0];
    int high = a[n - 1] + b[m - 1];
    int ans = lo - 1;
    while (lo < high)
    {
        int mid = (lo + high) / 2;
        if (check_for_v(mid, k, a, b, n, m))
        {
            lo = lo + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    // just next element
    cout << ans + 1 << endl;
}

// We are given array with n size with 1 and 0s as the elements, and we are given k, here k  means that we can flip any k 0s to 1s and find the maximum length of the continuos subarray with maximum all 1s.

// Basic Intuition is that what if we suppose X is the length of the maximum subarray with continuos 1s, then we check all the X segments of the array whether it is possible to create some of them or not, so for that we can do is we can suppose length from 0 to n, check with sliding approach with prefix sum, and if it is possible we move our range

bool check_for_x(int x, vector<int> &z, int k)
{
    // checking if the possible 0s are equal to k in any of x segments
    for (int i = x; i < z.size(); i++)
    {
        if ((i - x) > 0)
        {
            if (z[i] - z[i - x - 1] <= k)
            {
                return true;
            }
        }
        else
        {
            if (z[i] <= k)
            {
                return true;
            }
        }
    }
    return false;
}

void solve_for()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<int> zeroes(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (arr[0] == 0)
        zeroes[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeroes[i] += zeroes[i - 1] + 1;
        }
    }
    int low = 0, high = n, ans = 0;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (check_for_x(mid, zeroes, k))
        {
            ans = low;
            low = low + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
}


// we are given n balls and with different colours two balls can be of same colour, we need to find maximum basket we can fill with k distinct color balls, we are given with k

void check_for_basket(int mid, map<int, int> b, int k){
    int count = 0;
    for(auto i : b){
        count += min(mid, b.second)
    }
    return count >= mid * k; 
}

void solve_fo_ball(){
    int n, k;
    cin >> n >> k;
    // int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        mp[x]++;
    }
    int l = 0, r = n / k;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check_for_basket(mid, mp, k)){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
}

// For finding X such that X < N and X - sum of digit of X >= some S, find all those x

bool check_for_digit(int mid, int s){
    long long sum = 0, l = mid;
    while(l){
        sum += l % 10;
        l /= 10;
    }
    return (mid - l) >= s;
}

void solve_for_X(){
    long long n, s;
    cin >> n >> s;
    long long l = 0, r = n, ans = 0;
    while(l <= r){
        long long mid = (l + r) / 2;
        if(check_for_digit(mid, s)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
}

// for finding the value of the maximum fractional value of the some k indexes of an array A and B, i.e (A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]) is maximum.

// Intuition is that, let's suppose that maximum value of the fraction is x, so the (A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]) = x
// we can write it as (A[i1]+A[i2]+A[i3]+……+A[iK]) - x * (B[i1]+B[i2]+B[i3]+……+B[iK]) = 0, i.e if we pair them Summation of (A[i1] - x * B[i1]) >= 0, that means we can higher values of x, 

void solve_for_fractions(){
    int n;
    cin >> n;
    long long a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    long double s = 0.0;
    long double l = 0.0;
    long double r = 1e8;
    long double ans = 0.0;
    while((r - l) >= 1e-9){
        long double mid = (l + r) / 2.0;
        priority_queue<long double, vector<long double>, greater<long double>()> pq;
        for (int i = 0; i < n; i++){
            pq.push(a[i] - mid * b[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        s = 0.0;
        while(pq.size()){
            s += pq.top();
            pq.pop();
        }
        if(s >= 0.0){
            l = mid;
            ans = mid;
        }
        else{
            r = mid;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}


// Find the value of the x for all the possible sum of the integers
ll func(ll x)
{ // count number of subarray with sum<=x
    ll cnt = 0;
    ll currSum = 0;
    ll start = 0;
    ll current = 0;
    while (current < n)
    {
        currSum += arr[current];
        while (start <= current and currSum > x)
        {
            currSum -= arr[start];
            start++;
        }
        cnt += (current - start + 1);
        current++;
    }
    return cnt;
}


// Using Partial Sum and lower bound, 
void solve_for_kth(){
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> arr(n), partial(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // for m ranges
    for (ll i = 0; i < m; i++)
    {
        ll li = 0, ri = 0;
        cin >> li >> ri;
        partial[li - 1] += 1;
        if (ri < n)
        {
            partial[ri] -= 1;
        }
    }

    // finding partial sum
    for (ll i = 1; i < n; i++)
    {
        partial[i] += partial[i - 1];
    }

    // for sorting the array
    vector<pair<ll, ll> > vp(n);
    for (ll i = 0; i < n; i++)
    {
        vp[i].first = arr[i];
        vp[i].second = partial[i];
    }
    sort(vp.begin(), vp.end());

    // Now finding the all the elements
    for (ll i = 1; i < n; i++)
    {
        vp[i].second += vp[i - 1].second;
    }

    // now for finding the
    for (ll i = 0; i < n; i++)
    {
        partial[i] = vp[i].second;
    }

    // now taking q queries
    for (ll i = 0; i < q; i++)
    {
        ll k;
        cin >> k;
        if (k > partial[n - 1])
            cout << -1 << endl;
        else
        {
            ll pos = lower_bound(partial.begin(), partial.end(), k) - partial.begin();
            cout << vp[pos].first << endl;
        }
    }
}
