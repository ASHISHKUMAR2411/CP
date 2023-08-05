// *Set that represents a set of elements and supports operations like union, intersection, etc. When the type of elements is char, we may want to use a simple boolean array of size 256 to make a set. For other data types, we have to use some other complex technique.

//? let's see the implementation 
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
#define mo 1000000007
using namespace std;
template<class T>
void fun(T a)
{
    cout<<"The main template class "<<a<<endl;
}
template<>
void fun(int a)
{
    cout<<"The temporary template for the int type "<<a<<endl;
}
int main()
{
    fun<int>(1);
    fun<char>('a');
    fun<float>(2.34F);
    fun<double>(2.33D);
    fun<string>("Ashish Kumar");
    return 0;
}