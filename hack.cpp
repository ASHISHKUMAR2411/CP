#include <bits/stdc++.h>
using namespace std;

vector<long long> min_sum_queries(int N, vector<int> A, int Q, vector<vector<int>> queries)
{
    // Write your code here
    
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
        vector<int> A(N);
        for (int i_A = 0; i_A < N; i_A++)
        {
            cin >> A[i_A];
        }
        int Q;
        cin >> Q;
        vector<vector<int>> queries(Q, vector<int>(4));
        for (int i_queries = 0; i_queries < Q; i_queries++)
        {
            for (int j_queries = 0; j_queries < 4; j_queries++)
            {
                cin >> queries[i_queries][j_queries];
            }
        }

        vector<long long> out_;
        out_ = min_sum_queries(N, A, Q, queries);
        cout << out_[0];
        for (int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
            cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}