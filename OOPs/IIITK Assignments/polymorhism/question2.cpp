#include <iostream>
using namespace std;
void Max(int a, int b)
{
    cout << " The Max of " << a << " and " << b << " is " << max(a, b) << endl;
}
void Max(float a, float b)
{
    cout << " The Max of " << a << " and " << b << " is " << max(a, b) << endl;
}
void Max(double a, double b)
{
    cout << " The Max of " << a << " and " << b << " is " << max(a, b) << endl;
}

void Max(const char *a, const char *b){
    cout << " The Max of " << a << " and " << b << " is " << max(a, b) << endl;
}

    int main()
{
    Max(2,-3);
    Max(2.5,9.3);
    Max(2.9393274,-3.3982409);
    const char *ch1 = "Ashish";
    const char *ch2 = "Kumar";
    Max(ch1, ch2);
    return 0;
}