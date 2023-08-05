// CPP program to find the string to number number to string
#include <iostream>
#include <string>
// #include<boost/lexical_cast.hpp>
#include <sstream>
using namespace std;
int main()
{
    // converting string to number using stringstream
    string s = "12345";
    stringstream change(s);
    int x = 0;
    change >> x;
    cout << "\nthe value of x is : " << x;

    // using sscanf function for string to number
    const char *str = "12345";
    // int x;
    sscanf(str, "%d", &x);
    printf("\nThe value of x : %d", x);

    x = stoi(s);
    cout << "\n"
         << s << endl;

    // BOOST lexical cast string to nnumber
    // string str = "23",str1 = "2.3";
    // float f_value = boost::lexical_cast<float>(str1);
    // int i = boost::lexical_cast<int>(str);
    // cout<<"\nthe float value is : "<<f_value<<endl;
    // cout<<"\nthe int value is : "<<i<<endl;

    // converting integer to string
    int num = 2016;

    // declaring output string stream
    ostringstream str1;

    // Sending a number as a stream into output
    // string
    str1 << num;

    // the str() coverts number into string
    string geek = str1.str();

    // Displaying the string
    cout << "The newly formed string from number is : ";
    cout << geek << endl;

    // converting number and float into string 
    int i_vl = 10;
    float f_vl = 1.23;
    string str2 = to_string(i_vl);
    string str3 = to_string(f_vl);
    cout<<"The string is : "<<str2<<endl;
    cout<<"the string is : "<<str3<<endl;

    // 

    return 0;
}