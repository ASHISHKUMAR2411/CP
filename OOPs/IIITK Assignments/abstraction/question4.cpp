// Computes time difference of two time period
// Time periods are entered by the user

#include <iostream>
using namespace std;

class TIME
{
private:
    int seconds;
    int minutes;
    int hours;
public :
    TIME(){
        seconds = 0;
        minutes = 0;
        hours = 0;
    }
    void set(){
        cout << "Enter hours, minutes and seconds respectively: ";
        cin >> hours >> minutes >> seconds;
    }
    void computeTimeDifference( TIME t1,  TIME t2, TIME *difference)
    {

        if (t2.seconds > t1.seconds)
        {
            --t1.minutes;
            t1.seconds += 60;
        }

        difference->seconds = t1.seconds - t2.seconds;
        if (t2.minutes > t1.minutes)
        {
            --t1.hours;
            t1.minutes += 60;
        }
        difference->minutes = t1.minutes - t2.minutes;
        difference->hours = t1.hours - t2.hours;
    }
    void show(){
        cout<<" Hour : "<<hours<<" minutes : "<<minutes<<" seconds : "<<seconds<<endl;
    }
};


int main()
{
    class TIME t1, t2, difference;
    t1.set();
    t2.set();
    difference.computeTimeDifference(t1, t2, &difference);
    t1.show();
    t2.show();
    cout<<"The difference between both time is : "<<endl;
    difference.show();
    return 0;
}