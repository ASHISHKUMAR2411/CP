#include<iostream>
#include<fstream>
int main()
{
    std::streambuf *psbuf, *backup;
    std::ofstream filestr;
    filestr.open("text.txt");
    backup = std::cout.rdbuf();
    std::cout.rdbuf(psbuf);
    std::cout<<"this was written to the file : ";
    std::cout.rdbuf(backup);
    filestr.close();
    return 0;
}