#include<iostream>
using namespace std;
class Marks
{
    private: 
      int a;
      char b;
      float c;
    public : 
      static int stu;
      int emarks;
      int mmarks;
      int pmarks;
    public :
        Marks()
        {
            ++stu;
        };
};
int Marks::stu=0;
int main()
{
    Marks ob1;
    ob1.emarks=50;
    ob1.mmarks=80;
    ob1.pmarks=90;
    Marks ob2;
    ob2.pmarks=85;
    ob2.emarks=80;
    ob2.mmarks=60;
    cout<<"\n marks for the student 1";
    cout<<"\n english marks "<<ob1.emarks;
    cout<<"\n maths marks "<<ob1.mmarks;
    cout<<"\n physics marks "<<ob1.pmarks;
    cout<<"\n marks for the student 2";
    cout<<"\n english marks "<<ob2.emarks;
    cout<<"\n maths marks "<<ob2.mmarks;
    cout<<"\n physics marks "<<ob2.pmarks;
}