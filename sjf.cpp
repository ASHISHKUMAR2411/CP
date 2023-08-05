#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int pname;
    int btime;
    int atime;
} a[50];

void insert(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "Enter details of Process " << i + 1 << "\n";
        a[i].pname = (i + 1);
        cout << "Enter the arrival Time of p[" << i + 1 << "] : ";
        cin >> a[i].atime;
        cout << "Enter the burst Time of p[" << i + 1 << "] : ";
        cin >> a[i].btime;
        cout << "\n";
    }
}

bool btimeSort(node a, node b)
{
    return a.btime < b.btime;
}

bool atimeSort(node a, node b)
{
    return a.atime < b.atime;
}

void disp(int n)
{
    // sorting first according to the burst time and then by the arrival time 
    sort(a, a + n, btimeSort);
    sort(a, a + n, atimeSort);

    int ttime = 0, i;
    int j, tArray[n];
    for (i = 0; i < n; i++)
    {
        j = i;
        while (a[j].atime <= ttime && j != n)
        {
            j++;
        }
        sort(a + i, a + j, btimeSort);
        tArray[i] = ttime;
        ttime += a[i].btime;
    }
    tArray[i] = ttime;

    float averageWaitingTime = 0;
    float averageTAT = 0;
    cout << "\n";
    cout << "P.Name  AT\tBT\tCT\tTAT\tWT\t\n";
    for (i = 0; i < n; i++)
    {
        cout << a[i].pname << "\t";
        cout << a[i].atime << "\t";
        cout << a[i].btime << "\t";
        cout << tArray[i + 1] << "\t";
        cout << tArray[i] - a[i].atime + a[i].btime << "\t";
        averageTAT += (((tArray[i] - a[i].atime) < 0) ? 0 : (tArray[i] - a[i].atime)) + a[i].btime;
        cout << (((tArray[i] - a[i].atime) < 0) ? 0 : (tArray[i] - a[i].atime)) << "\t";
        averageWaitingTime += (((tArray[i] - a[i].atime) < 0) ? 0 : (tArray[i] - a[i].atime));
        cout << "\n";
    }
    cout << "\n";
    cout << "\nGantt Chart\n";
    for (i = 0; i < n; i++)
    {
        cout << "|   P" << a[i].pname << "   ";
    }
    cout << "\n";
    for (i = 0; i < n + 1; i++)
    {
        cout << tArray[i] << "\t";
    }
    cout << "\n";
    cout << "Average Waiting time: " << (float)averageWaitingTime / (float)n << endl;
    cout << "Average TA time: " << (float)averageTAT / (float)n << endl;
}

int main()
{
    int nop, choice, i;

    // taking Input of Each process i.e their arrival time and burst time
    cout << "Enter number of processes\n";
    cin >> nop;
    insert(nop);

    // calling function to display results
    disp(nop);
    return 0;
}