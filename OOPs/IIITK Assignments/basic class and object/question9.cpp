#include <bits/stdc++.h>
using namespace std;

// Program to display the current date
class date
{
private:
    int dd, mm, yy;

public:
    date()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        dd = ltm->tm_mday;
        mm = 1 + ltm->tm_mon;
        yy = 1900 + ltm->tm_year;
    }

    void display()
    {
        cout << "\nThe Current Date is :: ";
        cout << dd << "-" << mm << "-" << yy << "\n";
    }
};
int main()
{
    date date1;
    date1.display();

    return 0;
}