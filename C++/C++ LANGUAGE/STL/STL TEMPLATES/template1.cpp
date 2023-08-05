#include<iostream>
using namespace std;
//* instead of using the typename we can also use the class 
template <typename T>
T myMax(T x,T y)
{
    return (x>y) ? x : y;
}
int main()
{
    cout<<myMax<int>(3,7)<<endl;
    cout<<myMax<char>('g','e')<<endl;
    cout<<myMax<double>(3.45D,7.34D)<<endl;
    cout<<myMax<float>(3.45F,7.34F)<<endl;
    return 0;
} 