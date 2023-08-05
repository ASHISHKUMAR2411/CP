#include<iostream>
using namespace std;
//* for typename template
template <typename T>
T myMax(T x,T y)
{
    return (x>y) ? x : y;
}

//* template for  class 
//* 1. Array Class 
template <typename T>
class Array
{
private:
    /* data */
    T *ptr;
    int size;

public:
    Array(T arr[] , int s );
    void print();
};

template <typename T>
Array<T>::Array(T arr[],int s)
{
    ptr = new T(s);
    size = s;
    for(int i=0;i<size;i++)
    {
        ptr[i] = arr[i];
    }
}

template <typename T>
void Array<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << " " << *(ptr + i);
	cout << endl;
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	Array<int> a(arr, 5);
	a.print();
	return 0;
}
