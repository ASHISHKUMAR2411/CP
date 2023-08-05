#include<iostream>
using namespace std;
// doing divide and conqquere methods 
template<class T>
T DAC_Max(T arr[], int index,int size)
{
    T max ;
    if(index>=size-2)
    {
        if(arr[index]>arr[index+1])
        {
            return arr[index]; 
        }
        else
        {
            /* code */
            return arr[index+1];
        }
    }
    max = DAC_Max(arr,index+1,size);
    if(arr[index]>max)
    {
        return arr[index];
    }
    else
    {
        return max;
    }
}
template<class T>
T DAC_Min(T arr[],int index,int size)
{
    T min;
    if(index==size-2)
    {
        if(arr[index]<arr[index+1])
        {
            return arr[index];
        }
        else{
            return arr[index+1];
        }
    }
    min = DAC_Min(arr,index+1,size);
    if(arr[index]<min)
    {
        return arr[index];
    }
    else{
        return min;
    }
}

int main()
{
    // int arr[100];
    string arr[100];
    int size;
    cin>>size;
    for (int  i = 0; i < size; i++)
    {
        /* code */
        cout<<"\nenter the element :";
        cin>>arr[i];
    }
    // int max = DAC_Max<int>(arr,0,size);
    // int min = DAC_Min<int>(arr,0,size);
    string max = DAC_Max<string>(arr,0,size);
    string min = DAC_Min<string>(arr,0,size);
    cout<<"\nMaximum is : "<<max<<"\nMinimum is : "<<min<<endl;
    return 0;
}