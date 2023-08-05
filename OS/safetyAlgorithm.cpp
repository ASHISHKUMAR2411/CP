// Banker's Algorithm
#include<iostream>
using namespace std;

int main()
{
    // Lets Assume that the process names are Process0, Process1, Process2, Process3, Process4 are the Process names here

    int n, m, i, j, k;
    // we can also give processes at the run time

    n = 5;                         // Assuming Number of processes given
    m = 3;                         // Assuming Number of resources given


    // Allocated Resource Matrix
    int AllocatedResource[5][3] = {{1, 0, 1},  // Process0 
                       {1, 1, 2},  // Process1
                       {1, 0, 3},  // Process2
                       {2, 0, 0},  // Process3
                       {0, 0, 2}}; // Process4


    int MaximumResourceNeeded[5][3] = {{4,3,1},  // Process0 // MAX Matrix
                     {2, 1, 4},  // Process1
                     {1, 3, 3},  // Process2
                     {5, 4, 1},  // Process3
                     {4, 3, 3}}; // Process4


    // Available Resources Matrix
    int avail[3] = {3, 3, 0}; 
    int f[n], ans[n], ind = 0;

    // taking f is used to store either 1 or 0 so that we can check for not safe sequence and intialising the value to zero
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }

    // Finding the required resources needed for every process.
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = MaximumResourceNeeded[i][j] - AllocatedResource[i][j];
    }

    // for finding whether safe or unsafe

    int y = 0;
    // as there are total 5 process
    for (k = 0; k < 5; k++)
    {
        // for 5 process
        for (i = 0; i < n; i++)
        {
            // As initial value is 0 for all
            if (f[i] == 0)
            {
                // setting flag value to 0 and then changing incase if available resources are available for corresponding
                int flag = 0;

                // checking corresponding required resources are available. 
                for (j = 0; j < m; j++)
                {
                    // if need is available or not if not then break
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                
                // if flag is 0 that means required resources are available. 
                if (flag == 0)
                {
                    // then we insert the process in the sequence.
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += AllocatedResource[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    
    // then again flag is set to 1 assuming that it is safe 
    int flag = 1;

    // To check if sequence is safe or not
    for (int i = 0; i < n; i++)
    {
        // if it is zero that means that process didn't find the required resources. then we set flag = 0 for unsafe and break.
        if (f[i] == 0)
        {
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }

    // we check if the flag = 1 which is for safe. then we print the corresponding process.
    if (flag == 1)
    {
        cout << "Following is the SAFE Sequence" << endl;
        for (i = 0; i < n - 1; i++)
            cout << " Process" << ans[i] << " ->";
        cout << " Process" << ans[n - 1] << endl;
    }

    return (0);
}
