#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    float d;
    double e;
    char ch;
    string name;
    long int f;
    unsigned int g;
    unsigned long int h ;
    long long int i;
    long double k;
    short p;
    // the size of int is 2.14 * 10^9 positive number can be stored i.e number over 2 billion , the size of char shows 256 possible different character,  simlarrly we can do such type of inspection.  
    cout<<sizeof(int)<<"\n"<<sizeof(bool)<<"\n"<<sizeof(float)<<"\n"<<sizeof(double)<<"\n"<<sizeof(string)<<"\n"<<sizeof(long int )<<"\n"<<sizeof(unsigned int)<<"\n"<<sizeof(unsigned long int)<<"\n"<<sizeof(long long int)<<"\n"<<sizeof(char)<<"\n"<<sizeof(short);
    return 0;
}