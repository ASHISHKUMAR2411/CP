// Implementing the FCFS scheduling algorithm
#include <bits/stdc++.h>
using namespace std;

// Drivers Code
int main(){
    vector<int> arrival_time;
    vector<int> burst_time;
    int n;
    // Taking input from the user for number of Scheduling Processes
    cout<<"Enter the number of processes: ";
    cin>>n;

    // Taking input from the user for arrival time and burst time of each process
    cout<<"Enter the burst time of each process"<<endl;
    for(int i=0;i<n;i++){
        int a,b;
        cout<<"Enter the burst time of process "<<i+1<<": ";
        cin>>b;
        arrival_time.push_back(i+1);
        burst_time.push_back(b);
    }

    // Calculating the waiting time, turnaround time, completion time 
    // FCFS scheduling algorithm in O(n)
    int t=arrival_time[0];
    int wt[n],tat[n], ct[n];
    for(int i=0;i<n;i++){
        ct[i]=t+burst_time[i];
        t=ct[i];
        tat[i]=ct[i]-arrival_time[i];
        wt[i]=tat[i]-burst_time[i];
    }
    cout << endl;
    cout << endl;

    // Output of the Scheduled Execution
    cout<<"Process\t\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time"<<endl;
    for(int i=0;i<n;i++){
        cout<<"P"<<i+1<<"\t\t"<<arrival_time[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<ct[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;
    }

    // Gantt Chart
    cout<<"\nGantt Chart"<<endl;
    // cout<<"P"<<arrival_time[0]<<"\t";
    for(int i=0;i<n;i++){
        cout<<"P"<<i+1<<"\t";
    }
    cout << endl;
    cout << endl;

    // calculating the average waiting time, turnaround time
    int total_wt=0, total_tat=0;
    for(int i=0;i<n;i++){
        total_wt+=wt[i];
        total_tat+=tat[i];
    }

    // Output of the average waiting time, turnaround time
    cout<<"Average waiting time: "<<(float)total_wt/n<<endl;
    cout<<"Average turnaround time: "<<(float)total_tat/n<<endl;
    return 0;
}