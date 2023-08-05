#include<stdlib.h>
#include<stdio.h>
#include<string.h>  

struct keyword{
    char name[10];
    int freq;
};

int main(){
    char arr[][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    struct keyword kw[32];
    for (int i = 0; i < 32; i++){
        strcpy(kw[i].name, arr[i]);
        kw[i].freq = 0;
    }
    // read from a text file
    FILE *fp = fopen("compiler.txt", "r");
    // find words from the file
    char word[10];
    while (fscanf(fp, "%s", word) != EOF){
        for (int i = 0; i < 32; i++){
            if (strcmp(kw[i].name, word) == 0){
                kw[i].freq++;
            }
        }
    }
    int total = 0;
    // print the frequency of each keyword
    for (int i = 0; i < 32; i++){
        if (kw[i].freq)
        {
            printf("%s : %d times \n", kw[i].name, kw[i].freq);
            total += kw[i].freq;
        }
    }
    printf("Total : %d ", total);
    return 0;
}