// * in class we hve differnet ways to show the static vaiable as  of the function and it is shown as it is .
#include<iostream>
using namespace std;
template<class T>
class Test
{
private:
    T val;
    /* data */
public:
static int count;
    Test()
    {
        count++;
    };
};
template<class T>
int Test<T>::count=0; 
int main()
{
    Test<int> a;
    Test<int> b;
    Test<double> c;
    cout<<Test<int>::count<<endl;
    cout<<Test<double>::count<<endl;
    return 0;
}