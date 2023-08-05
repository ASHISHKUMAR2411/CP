// Write a C++ Program to overload the subscript operator[] by writing the member operator function operator definition.Also the above overloaded operator work on the vector class.
#include<bits/stdc++.h>
using namespace std;
class vector
{
    int *a;
    int n;
public:
    vector()
    {
        n=0;
        a=NULL;
    }
    vector(int n)
    {
        this->n=n;
        a=new int[n];
    }
    vector(const vector &v)
    {
        n=v.n;
        a=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=v.a[i];
        }
    }
    ~vector()
    {
        delete []a;
    }
    int operator[](int i)
    {
        return a[i];
    }
    vector operator=(const vector &v)
    {
        n=v.n;
        a=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=v.a[i];
        }
        return *this;
    }
    friend ostream& operator<<(ostream &out,vector &v)
    {
        for(int i=0;i<v.n;i++)
        {
            out<<v.a[i]<<" ";
        }
        return out;
    }
};
int main()
{
    vector v1(5);
    vector v2(v1);
    cout<<"Enter the elements of vector 1: ";
    for(int i=0;i<v1.n;i++)
    {
        cin>>v1.a[i];
    }
    cout<<"Enter the elements of vector 2: ";
    for(int i=0;i<v2.n;i++)
    {
        cin>>v2.a[i];
    }
    cout<<"Vector 1: "<<v1<<endl;
    cout<<"Vector 2: "<<v2<<endl;
    return 0;
}
// Output:
// Enter the elements of vector 1: 1 2 3 4 5
// Enter the elements of vector 2: 6 7 8 9 10
// Vector 1: 1 2 3 4 5
// Vector 2: 6 7 8 9 10
