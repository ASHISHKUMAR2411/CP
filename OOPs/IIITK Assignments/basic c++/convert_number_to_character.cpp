#include <iostream>
using namespace std;

string oneAndTenth[] = {"", "one ", "two ", "three ", "four ",
                "five ", "six ", "seven ", "eight ",
                "nine ", "ten ", "eleven ", "twelve ",
                "thirteen ", "fourteen ", "fifteen ",
                "sixteen ", "seventeen ", "eighteen ",
                "nineteen "};


string tenMultiple[] = {"", "", "twenty ", "thirty ", "forty ",
                "fifty ", "sixty ", "seventy ", "eighty ",
                "ninety "};

// n is 1- or 2-digit number
string numToWords(int n, string s)
{
    string str = "";
    // if n is more than 19, divide it
    if (n > 19)
        str += tenMultiple[n / 10] + oneAndTenth[n % 10];
    else
        str += oneAndTenth[n];

    // if n is non-zero
    if (n)
        str += s;

    return str;
}

// Function to print a given number in words
string convertToWords(long n)
{
    // stores word representation of given number n
    string out;
    out += numToWords((n / 10000000), "crore ");
    out += numToWords(((n / 100000) % 100), "lakh ");
    out += numToWords(((n / 1000) % 100), "thousand ");
    out += numToWords(((n / 100) % 10), "hundred ");

    if (n > 100 && n % 100)
        out += "and ";
    out += numToWords((n % 100), "");

    return out;
}

// Driver code
int main()
{
    long int Number ;
    cout<<"Enter the number : ";
    cin>>Number;

    // convert given number in words
    cout<<"the number in words is : ";
    cout << convertToWords(Number) << endl;

    return 0;
}