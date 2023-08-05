// there are some standard macros which can be used to print program file (_FILE_),for date of compliation(_DATE_), time of compliation(_TIME_),the line number in C code (_LINE_)
#include<stdio.h>
int main()
{
    printf("\n the file name is : %s",__FILE__);
    printf("\n the date of compilation is : %s",__DATE__);
    printf("\n the time of compilation :%s",__TIME__);
    printf("\n the line number of the c code is : %d",__LINE__);
    // the below one ae first declared
    printf("\n %s"__TIMESTAMP__);
    printf("\n %ul",__STDC_VERSION__);
    printf("\n %d",__STDC_UTF_32__);
    printf("\n %d",__STDC_UTF_16__);
    printf("\n %s",__VERSION__);
    // printf("\n %u",__CHAR16_TYPE__);
    // printf("\n %u",__CHAR32_TYPE__);
    printf("\n %s",__COUNTER__);
    // printf("\n %d",__EDG__);
    // printf("\n %ld",__EDG_PTRDIFF_TYPE__);
    printf("\n %d",__STDC__);
    // printf("\n %d",__SIGNED_CHARS__);
    // printf("\n %d",__INTELLISENSE__);
    printf("\n %d",__GNUC_STDC_INLINE__);
    printf("\n %d",__GNUC_PATCHLEVEL__);
    printf("\n %d",__GNUC_MINOR__);
    printf("\n %d",__GNUC__);
    // printf("\n %ul",__EDG_SIZE_TYPE__);
    // printf("\n %d",__EDG_VERSION__);
    printf("\n %s",__BASE_FILE__);
    return 0;



}