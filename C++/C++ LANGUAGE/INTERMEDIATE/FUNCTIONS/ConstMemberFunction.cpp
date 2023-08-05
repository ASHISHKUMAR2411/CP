// ConstMemberFunction
#include<bits/stdc++.h>
using namespace std;
class test
{
    private:
    int v;
    public:
    test(int value =0 ){ v = value ;}
    int getValue() const{ return v;}
    int putValue(){return v;} 
};
int main()
{
    const test t(20);
    test t1(25);
    cout<<"\n"<<t.getValue();
    cout<<"\n"<<t1.getValue();
    cout<<"\n"<<t1.putValue();
    return 0;
}