#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {
    s= ltrim(rtrim(s));
    if((int)(s.length())==1)
    {
        cout<<"NO";
        return;
    }
    int size = (int)s.length();
    int number = stoi(s);
    int arr[size];
    int n = 1 ;
    for(int i = 1;i<size;i++)
    {
        n*=10;
    }
    for(int i =0;i<size;i++)
    {
        arr[i] = number/n;
        number = number%n;
        n = n/10;
    }
    for(int i =0;i<size;i++)
    {
        if((a[i+1]-a[i])==1);
        else if(a[i]==9)
        {
            if(a[i+1]==9);
            if((a[i+1]+a[i+2]-a[i]) == 1 );
        }
    }
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
