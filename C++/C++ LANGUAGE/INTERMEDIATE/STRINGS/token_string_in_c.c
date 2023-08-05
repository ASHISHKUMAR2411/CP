// C file to print the token string
#include <stdio.h>
#include <string.h>
int main()
{
    char name[] = "Ashish - Kumar - Kushwaha";
    const char s[] = "-";
    char *tok = strtok(name, s);
    while (tok != 0)
    {
        printf("%s\n", tok);
        tok = strtok(0, s);
    }
    return 0;
}