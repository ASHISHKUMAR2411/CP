// You are given a positive integer K and an array A consisting of N non - negative integers.Find the lexicographically smallest sequence B that satisfies the following conditions
// 1) We can obtain B by rearranging the elements in A.
// 2) The length of longest non-decreasing subsequence of B is equal to K.
// If no such sequence exists,print −1.
// Input Format
// First line of the input contains T, the number of testcases.
// Then the testcases follow.First line of each test case contains two space separated integers N and K.
// Second line of each test case contains N space separated integers describing the array A.
// Output Format
// For each test case, output the array B in a single line with a space between two consecutive elements.And output −1 if no such array B exists.
// Constraints
// 1≤T≤200
// 1≤N≤200
// 1≤K≤N
// 1≤Ai≤N
// Sum of N over all test cases doesn't exceed  200
// Sample Input
// 4
// 3 1
// 2 1 3
// 3 2
// 2 1 3
// 3 3
// 2 1 3
// 3 1
// 2 2 3
// Sample Output
// 3 2 1
// 1 3 2
// 1 2 3
// -1
// Explanation
// For the first test case, the array B is {3,2,1}.
// For the second test case, the array B is {1,3,2}.
// For the third test case, the array B is {1,2,3}.
// For the fourth test case, the array B is −1.
//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int dp[n][k+1];
        for(int i=0;i<n;i++)
        {
            dp[i][1]=a[i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                dp[i][j]=INT_MAX;
                for(int l=0;l<i;l++)
                {
                    if(a[i]>=dp[l][j-1])
                    {
                        dp[i][j]=min(dp[i][j],dp[l][j-1]);
                    }
                }
                dp[i][j]=max(dp[i][j],a[i]);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[i][k]);
        }
        if(ans==INT_MAX)
        {
            cout<<-1<<endl;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(dp[i][k]==ans)
                {
                    cout<<dp[i][k]<<" ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

