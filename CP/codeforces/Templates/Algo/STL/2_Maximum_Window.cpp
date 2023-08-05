#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(K)

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

void add(deque<int> &d, int x)
{
    while (!d.empty() && d.back() < x)
        d.pop_back();
    d.push_back(x);
    return;
}

void rem(deque<int> &d, int x)
{
    assert(!d.empty());
    if (d.front() == x)
        d.pop_front();
    return;
}

signed main()
{
    // freopen("IN", "r", stdin);
    // freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        int A[n];

        for (int i = 0; i < n; i++)
            cin >> A[i];

        deque<int> d;

        for (int i = 0; i < k; i++)
            add(d, A[i]);

        for (int i = 0; i <= n - k; i++)
        {
            cout << d.front() << " ";
            rem(d, A[i]);
            if (i + k < n)
                add(d, A[i + k]);
        }

        cout << "\n";
    }
    return 0;
}

// 
// SC : O(N)IInd Method
// What we can do is that, we can use the mutlimap method where we can, and erase the a[i-k] and add the a[i] and then store the first element i.e top of the map to the b[i] 
// TC : O(N*logK)

// signed main()
// {

//     int T;
//     cin >> T;
//     while (T--)
//     {
//         int n, k;
//         cin >> n >> k;
//         int A[n];

//         for (int i = 0; i < n; i++)
//             cin >> A[i];

//         multiset<int> M;

//         for (int i = 0; i < k; i++)
//             M.insert(A[i]);

//         for (int i = 0; i <= n - k; i++)
//         {
//             cout << *(M.rbegin()) << " ";
//             M.erase(M.find(A[i]));
//             if (i + k < n)
//                 M.insert(A[i + k]);
//         }
//         cout << "\n";
//     }
//     return 0;
// }
