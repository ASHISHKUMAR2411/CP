#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct keyword
{
    char name[10];
    int freq;
};

int main()
{
    char arr[][10] = {"+", "-", "/", "*", "\%", "++", "--", "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", ">>=", "<<=", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!"};
    struct keyword kw[27];
    for (int i = 0; i < 27; i++)
    {
        strcpy(kw[i].name, arr[i]);
        kw[i].freq = 0;
    }
    // read from a text file
    FILE *fp = fopen("operators.txt", "r");
    // find words from the file
    char word[19];
    while (fscanf(fp, "%s", word) != EOF)
    {
        for (int i = 0; i < 27; i++)
        {
            if (strcmp(kw[i].name, word) == 0)
            {
                kw[i].freq++;
            }
        }
    }
    int total = 0;
    // print the frequency of each keyword
    for (int i = 0; i < 27; i++)
    {
        if (kw[i].freq && strcmp(kw[i].name, ",") != 0)
        {
            printf("%s : %d times \n", kw[i].name, kw[i].freq);
            total += kw[i].freq;
        }
    }
    printf("Total : %d ", total);
    return 0;
}