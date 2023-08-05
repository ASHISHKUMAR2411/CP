#include<iostream>
using namespace std;
class Test
{
    public:
    Test()
    {
        cout<<"Inside Test's Constructor ";
    }
    ~Test()
    {
        cout<<"\nInside Test's Destructor";
    }
};
int main()
{
    static Test t1;
    // return 0;
    exit(0);
}