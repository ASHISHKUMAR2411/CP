#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    fstream file;
    file.open("text.txt",ios::out);
    // auto cout_buf = cout.rdbuf(file.rdbuf()); one line for all
    streambuf *stream_buffer_cout = cout.rdbuf();
    streambuf *stream_buffer_cin = cout.rdbuf();
    streambuf *stream_buffer_file = file.rdbuf();
    cout.rdbuf(stream_buffer_file);
    cout<<"This lines were written inside the file "<<endl;
    cout.rdbuf(stream_buffer_cout);
    cout<<"This is writtten to the screen \n";
    file.close();
    return 0;
}