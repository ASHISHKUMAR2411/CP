#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
// Output the minimum number of operations (we can divide the numbers by 2 but we can't change their position) that must be done for a sequence of n integers to become strictly increasing

int findNumberOfOperations(vector<int> &arr){
    int count = 0;
    for(int i = arr.size() - 1; i >= 1; i--){
        if(arr[i] > arr[i-1]){
            continue;
        }
        else if(arr[i] == arr[i-1] && arr[i-1] == 0){
            return -1;
        }
        else{
            while(arr[i-1] >= arr[i]){
                arr[i-1] = arr[i-1]/2;
                count++;
            }
            if (arr[i] < i || (arr[i] == arr[i - 1] && arr[i - 1] == 0))
            {
                return -1;
            }
        }
    }
    return count;
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << findNumberOfOperations(arr) << endl;
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// #define lli int
// #define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define try   \
//     lli t;    \
//     cin >> t; \
//     while (t--)
// #define f(i, a, b) for (lli i = a; i < b; i++)
// #define mod 1e9 + 7
// #define sz(a) (int)(a.size())
// #define rz resize
// #define pb push_back
// #define ff first
// #define ss second

// int main()
// {
//     fast;
//     try
//     {

//         lli n, x;
//         cin >> n;
//         lli arr[n];
//         lli flag = 0;
//         f(i, 0, n)
//         {
//             cin >> arr[i];
//             if (arr[i] < i)
//             {
//                 flag = 1;
//             }
//         }

//         if (n == 1)
//         {
//             cout << 0 << endl;
//             continue;
//         }

//         if (flag == 1)
//         {
//             cout << -1 << endl;
//         }
//         else
//         {
//             lli g = arr[n - 1];
//             lli count = 0;
//             for (lli i = n - 2; i >= 0; i--)
//             {
//                 if (g > arr[i])
//                 {
//                     g = arr[i];
//                     continue;
//                 }
//                 else
//                 {
//                     lli f = arr[i] / g;
//                     f = log2(f) + 1;
//                     count += f;
//                     g = arr[i] / pow(2, f);
//                 }
//             }
//             cout << count << endl;
//         }
//     }
// }