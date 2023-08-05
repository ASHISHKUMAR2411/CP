#include<bits/stdc++.h>
using namespace std;

// Basic Intuition : For any question to be valid for using two pointer or three pointer is when we have to find something in range from [l, r], like if we have a range of continuous values as our answer, then we check if we move l to l` then what would be the effect on the r as r`, so the relation ship is l` > l then r` >= r, if this condition is satisfied, then only  we should apply two pointer,
// One more usage of two pointer is when we have to find two distinct element located at l and r position and find some computation for that, then also we can use two pointer.


// Question 1 : Given an array, we need to find the longest sub-array with k distinct elements,

// Intuition : Using Two pointer, first let suppose i am at l position and and my r is also at l, it has one distinct element, now I move r toward n, and check if the distinct element is less than k and I add the number, If the number had already shown up and then also I add it to the subarray, and increase the r, and stop when it is equal to k and we find a distinct element, find the length of it and store it in the maximum, now as we have k distinct elements we increase the l to the right, and decrease the count of distinct by one, now we again increase r to do the same, we do this untill l is less than the n,

int arr[1000100];
int count_distinct = 0;

void insert(int x){
    if(arr[x] == 0){
        count_distinct++;
    }
    arr[x]++;
}
void remove(int x){
    arr[x]--;
    if(arr[x] == 0){
        count_distinct--;
    }
}

void solve(vector<int> &arr, int k){
    int head = -1;
    int tail = 0;
    int ans = -1e9;
    int n = arr.size();
    while(tail < n){
        while((head + 1) < n and ((arr[head + 1] == 0 and count_distinct < k) || (arr[head + 1] != 0 and count_distinct <= k))){
            head++;
            insert(arr[head]);
        }
        ans = max(ans, (head - tail + 1));
        if(head < tail){
            tail++;
            head = tail - 1;
        }
        else{
            remove(arr[tail]);
            tail++;
        }
    }
    cout << ans << endl;
}

// Question 2 : Given an array, we need to count the sub-array with k distinct elements, the question is slightly changed from the above one, so what we need to do is count them, 
// Intuition If we have subarray with size n, then there will be n subarray

void solve(vector<int> &arr, int k)
{
    int head = -1;
    int tail = 0;
    int ans = -1e9;
    int n = arr.size();
    while (tail < n)
    {
        while ((head + 1) < n and ((arr[head + 1] == 0 and count_distinct < k) || (arr[head + 1] != 0 and count_distinct <= k)))
        {
            head++;
            insert(arr[head]);
        }
        ans += (head - tail + 1);
        if (head < tail)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            remove(arr[tail]);
            tail++;
        }
    }
    cout << ans << endl;
}


// Questions : You have given array, find three sum of any three distinct indexes i, j, k, where thier sum is closest to x, find that closeness

// Intuition : Sort the array, and use pointer like move j from 1 to n - 2, and i from 0 to j - 1 and k from j+1 to n-1, find the sum of those elements and check for minimum,

void solve(vector<int> ans, int x){
    int ans = INT_MAX;
    for (int i = 1; i < n - 1; i++){
        int j = 0, k = n - 1;
        while(i < j and k > j){
            int sum = (arr[i] + arr[j] + arr[k]); 
            ans = min(ans, abs(sum - x));
            if(sum > x){
                k--;
            }
            else{
                j++;
            }
        }
    }
    cout << ans << endl;
}

// Question : Given An array of integers we have to find the maximum sum of subarray possible such that, the subarray contains <= k odd numbers and the sum of the subarray should be <= d, 

// Basic Intuition is : We need to find the prefix[r] - prefix[l-1] <= d and keep the count of the odd number, we can do this using two pointer approach. Keep in mind that, when the order of the array matters, then we have to think about two pointers

void solve(){
    long long n, d, k;
    cin >> n >> d >> k;
    long long a[n], prefix[n];
    for (long long i = 0; i < n; i++){
        cin >> a[i];
        prefix[i] = a[i];
        if(i){
            prefix[i] += prefix[i - 1];
        }
    }

    // now keep the count of the odd numbers, ans, left an right pointer
    long long head = -1, tail = 0, ans = -1e18, count_odd = 0;
    multiset<long long> mt;
    while(tail < n){
        if((head + 1) < n and ((count_odd < k and arr[head + 1]%2) || count_odd <= k and arr[head + 1]%2 == 0)){
            head++;
            if(arr[head]%2){
                count_odd++;
            }
            mt.insert(prefix[head]);
        }
        int temp = d + (tail > 0) ? prefix[tail-1]: 0;
        auto it = mt.upper_bound(temp);
        if(it != mt.begin()){
            it--;
            ans = max(ans, *it - (tail > 0 ? prefix[tail - 1] : 0));
        }
        if(tail > head){
            tail++;
            head = tail - 1;
        }
        else{
            if(arr[tail]%2){
                count_odd--;
            }
            mt.erase(mt.find(prefix[tail]));
            tail++;
        }
    }
    cout << ans << endl;
}



// Questions is find the number of subarray whose sum is <= k

// Intuition : I will use two pointer with prefix sum, we will store the prefix sum in a multiset and find the the subarray from l to particular j such that whose prefix sum is less than equal to k and we will add those variables

void solve(){
    long long n, k;
    cin >> n >> k;
    long long arr[n], prefix[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        prefix[i] = arr[i];
        if(i)
            prefix[i] += prefix[i - 1];
    }
    multiset<long long> mt;
    long long head = 0, count = 0, tail = 0, ans = 0; 
    while(head < n){
        ans += arr[head];
        while(tail <= head && ans > k){
            ans -= arr[tail];
            tail++;
        }
        count += (head - tail + 1);
        head++;
    }
    cout << count;
}

// find the subarray with length d with minimum distinct elements possible
int arr[1000100];
int Distinct = 0;
void insert(int x){
    if(arr[x] == 0){
        Distinct++;
    }
    arr[x]++ ;
}
void remove(int x){
    arr[x]--;
    if(arr[x] == 0){
        Distinct--;
    }
}
void solve(){
    int n, d;
    cin >> n >> d;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < d; i++){
        insert(a[i]);
    }
    while(head < n){
            insert(arr[head]);
            remove(arr[tail]);
            head++;
            tail++;
            ans = min(ans, Distinct);
    }
    cout << Distinct << endl;
}


// Smallest Subarray with K distinct Elements, K is equal to the total distinct elements present in the array.

void solve(){
    int n;
    cin >> n;
    int arr[n];
    set<int> s;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        s.insert(arr[i]);
    }
    int k = s.size();
    int head = 0, tail = 0, ans = INT_MAX, Distinct = 0;
    while(head < n){
        a[arr[head]]++;
        if(a[arr[head]] == 1){
            Distinct++;
        }
        while(tail <= head and (Distinct == k )){
            ans = min(ans, (head - tail + 1));
            a[arr[tail]]--;
            if(a[arr[tail]] == 0){
                Distinct--;
            }
            tail++;
        }
        head++;
    }
    cout << ans << endl;
}

// Their Solution
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testcases;
    cin >> testcases;
    while (testcases--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        ll freq[100001] = {0};
        for (ll i = 0; i < n; i++)
            cin >> arr[i], freq[arr[i]]++;
        ll distinctElement = 0;
        for (ll i = 0; i <= 100000; i++)
        {
            distinctElement += (freq[i] > 0);
            freq[i] = 0;
        }
        ll ans = n;
        ll start = 0;
        ll current = 0;
        ll currSum = 0;
        while (current < n)
        {
            freq[arr[current]]++;
            if (freq[arr[current]] == 1)
                currSum++;
            while (start <= current and currSum == distinctElement)
            {
                ans = min(ans, current - start + 1);
                if (freq[arr[start]] == 1)
                    currSum--;
                freq[arr[start]]--;
                start++;
            }
            current++;
        }
        cout << ans << "\n";
    }
}


// Question : TO find the sum of the number of distinct character in the substring of the string 

// Code 
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(char c = 'a'; c <= 'z'; c++){
        int count = 0, res = 0;
        for (int i = 0; i < n; i++){
            if(s[i] == c){
                res += ((count) * (count + 1)) / 2;
                count = 0;
            }
            else{
                count++;
            }
        }
        res += ((count + 1) * (count)) / 2;
        ans += (n * (n + 1)) / 2 - res;
    }
    cout << ans << endl;
}