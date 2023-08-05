// GetTemporaryBuffer
/* This function take a size n and return the largest available buffer up to size n which can be fit into physical memory.
This function is used to get a memory of temporary nature mostly used for the operation of an algorithm as some algorithms required extra space to perform correctly .
Once the the memory block which is assigned is not needed anymore it shall be released by calling return_temporary_buffer . */
// pair(int*, ptrdiff_t) p = get_temporary_buffer(int)(required size)

// n: Number of elements of type T for which temporary memory is allocated.
// ptrdiff_t: it is an integral type.
// Return: The function returns the first and second pair of objects. When memory is allocated the first contains the pointer to the first element in the block and the second contains the size. If the memory block is not allocated than the first pair contains null pointer and second contains zero.

// Here we are taking an example of sorting using the get_temporary_buffer
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
void sorting(int b[],int n)
{
    int c =0;
    for(int i =0;i<n;i++)
    {
        if(b[i]%2 == 0)
        {
            c++;
        }
    }
    cout<<"No of even term in the array is "<<" : "<<c;
    cout<<"\n";
    cout<<"original array : ";
    for(int i = 0;i<n;i++)
    {
        cout<<" "<<b[i];
    }
    cout<<"\n";
    // Now we will actually use get_temporary_buffer 

    pair<int *,ptrdiff_t> p = get_temporary_buffer<int>(n);
    uninitialized_copy(b,b+p.second,p.first);
    sort(p.first,p.first+p.second);
    cout<<"\n";
    cout<<"The sorted array : ";
    for(int i =0; i < p.second;i++)
    {
        cout<<" "<<p.first[i];
    }

}

// Here mains starts 
int main()
{
    cout<<"\nEnter the number of element : ";
    int n;
    cin>>n;
    int b[n];
    cout<<"\nenter the element of the array : ";
    for(int i =0;i<n;i++)
    {
        cin>>b[i];
    }
    sorting(b,n);
    return 0;
}