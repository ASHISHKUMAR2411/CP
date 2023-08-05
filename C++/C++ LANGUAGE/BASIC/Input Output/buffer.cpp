#include <iostream>
#include <string>
#include<limits>
#include<ios>
using namespace std;
// namespace std;
int main()
{
    cout << "Enter the number and charcater \n";
    int n;
    char ch[40];
    cin >> n;
    // fflush(stdin);
    //it clears the buffer i.e \n in this case 

    //we can also use the   cin.ignore(numeric_limits::max(),'\n'); it also requires limits in header section  , it disregards everything that is a newline also .
    // cin.ignore(numeric_limits<streamsize>::max(),'\n');

    // we can also use cin.sync() as it discards all left in buffer 
    // cin.sync();

    // we can also use cin>>ws where it remove all white spaces before actual content of string and character , and it also removes buffer ,
    cin>>ws;
    cin.getline(ch, 80);
    cout << n << " " << ch;
    return 0;
}
