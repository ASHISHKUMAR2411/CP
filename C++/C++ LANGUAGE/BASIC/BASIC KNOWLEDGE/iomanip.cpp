#include<iostream>
#include<iomanip>
#include<ctime>
#include<chrono>
using std::cout;
using std::cin;
int main()
{
    int a,b,c;
    double d=3.14151718;
    long double price;
    cout<<std::hex;
    cout<<std::setiosflags(std::ios::showbase | std::ios::uppercase);
    cout<<100<<std::endl;
    cout<<std::hex<<std::setiosflags(std::ios::showbase);
    cout<<100<<std::endl;
    cout<<std::resetiosflags(std::ios::showbase)<<100<<std::endl;
    cout<<std::setbase(8);
    cout<<110<<std::endl;
    cout<<std::setbase(10);
    cout<<110<<std::endl;
    cout<<std::setbase(16);
    cout<<110<<std::endl;
    cout<<std::setbase(6);
    cout<<110<<std::endl;
    cout<<std::setfill('x')<<std::setw(10);
    cout<<77<<std::endl;
    cout<<std::setprecision(5)<<d<<"\n";
    cout<<std::setprecision(9)<<d<<"\n";
    cout<<std::fixed;
    cout<<std::setprecision(5)<<d<<"\n";
    cout<<std::setprecision(6)<<d<<"\n";
    cout<<"Pleaase , enter the price ";
    cin>>std::get_money(price);
    if(std::cin.fail()) 
    {
        cout<<"\n error reaging the money \n";
    }
    else
    {
        cout<< "the price is "<<std::put_money(price)<<"\n";
    }

    struct std::tm when;
    cout<<"\nenter the time :";
    cin>>std::get_time(&when,"%R");
    if(std::cin.fail())
    {
        cout<< "Error reading time \n";
    }
    else
    {
        cout<<"\n the time entered is :"<<when.tm_hour<<" hour and "<<when.tm_min<<" minutes "<<" \n";
    }

    using std::chrono::system_clock;
    std::time_t tt = system_clock::to_time_t(system_clock::now());
    struct std::tm * ptm =std::localtime(&tt);
    cout<< "Now (local time) :"<<std::put_time(ptm,"%c")<<"\n";
    time_t curtime;
    time(&curtime);
    cout<<"\n current time :"<<ctime(&curtime);
    return 0;
}