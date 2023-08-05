#include <bits/stdc++.h>
using namespace std;

int Possibility(int N, int M, vector<long long> A)
{
    int j = N - 1, sum = 0;
    int maxi = *max_element(A.begin(), A.end());
    vector<long long> v;

    while (M > 0 && j >= 0)
    {
        if (A[j] > maxi)
        {
            v.push_back(A[j]);
            j--;
        }
        else
        {
            if (j > 1)
            {
                sum += A[j] + A[j - 1] + A[j - 2];
                v.push_back(sum);
                j = j - 3;
            }
            else
            {
                v.push_back(A[j]);
                j--;
            }
        }

        M--;
    }
    while (j >= 0)
    {
        v.push_back(A[j]);
        j--;
    }
    if(M==0){
        reverse(v.begin(), v.end());
    }
    int flag = 1;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] >= v[i + 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        vector<long long> A(N);
        for (int i_A = 0; i_A < N; i_A++)
        {
            cin >> A[i_A];
        }

        int out_;
        out_ = Possibility(N, M, A);
        cout << out_;
        cout << "\n";
    }
}