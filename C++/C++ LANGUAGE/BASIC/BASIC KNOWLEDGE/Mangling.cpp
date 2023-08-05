// we have the function overloading in c++ and we don't have function overloading inn c so when we use c codes in c++ and write the same decalaration for the function it may shoot trouble and that is not good

//*  for example
#include <iostream>
using namespace std;
// Save file as .cpp and use C++ compiler to compile it
// int printf(const char *format,...);

// int main()
// {
// 	printf("GeeksforGeeks");
// 	return 0;
// }

// Save file as .cpp and use C++ compiler to compile it
// extern "C"
// {
// 	int printf(const char *format,...);
// }

// int main()
// {
// 	printf("GeeksforGeeks");
// 	return 0;
// }

extern "C"
{
    int printf(const char *format, ...);
}
int main()
{
    printf("GeeksForGeeks");
    void *ptr;
    int *i = (int *)ptr; /* Implicit conversion from void* to int* is not allows but it can be used explicitly in c++ but is allowed in c */
    cout<<ptr<<endl<<endl<<i<<endl<<*i<<endl;
    return 0;
}