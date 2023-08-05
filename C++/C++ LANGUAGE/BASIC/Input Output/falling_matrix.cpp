// produciing hacking background in c++
// TODO(issue)
// FIXME
// NOTE
// HACK

#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

const int width = 70;

const int flipsPerLines = 5;
const int sleepTime = 100;

int main()
{
    int i = 0, x = 0;
    srand(time(NULL));
    bool switches[width] = {0};
    const string ch = "1234567890qwertyuiopasdfghjklzxcvbnm,./';[]!~@#$%^&*()-=_+:;";
    const int l = ch.size();
    system("Color 0A");
    while (true)
    {
        for (i = 0; i < width; i += 2)
        {
            if (switches[i])
            {
                cout << ch[rand() % l] << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        for (i = 0; i != flipsPerLines; ++i)
        {
            x = rand() % width;
            switches[x] = !switches[x];
        }
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(sleepTime));
    }
    return 0;
}