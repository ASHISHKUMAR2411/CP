#include<stdlib.h>
#include<stdio.h>
#include<string.h>  


int main(){
    char arr[][10] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while" };

    char str[10];
    printf("Enter a string to check keyword :  ");
    scanf("%s", &str);
    for (int i = 0; i < 33; i++){
        if (strcmp(arr[i], str) == 0){
            printf("Keyword");
            return 0;
        }
    }
    printf("Not a keyword");
    return 0;
}