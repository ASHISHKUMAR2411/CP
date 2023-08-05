#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, vector<string> command)
{
    
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> command(N);
    for (int i_command = 0; i_command < N; i_command++)
    {
        getline(cin, command[i_command]);
    }

    vector<int> out_;
    out_ = solve(N, command);
    cout << out_[0];
    for (int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
        cout << "\n"<< out_[i_out_];
    }
}