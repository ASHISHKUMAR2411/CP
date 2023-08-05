#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct cricket
{
    char Pname[50];
    char Pteam[5];
    float batting_average;
} player[10],team1[10],team2[10];
 int main()
 {
    // so this is for player with batting average  
    int i, j=0,k=0;
    char ch[1];
    
    
    for (i = 0; i < 10; i++)
    {
        printf("\n enter the name of the %d player : \t", i + 1);
        gets(ch);
        gets(player[i].Pname);
        printf("\n enter the team name i.e CSK or MI in same way i have written :\t ");
        
        gets(player[i].Pteam);
        printf("\n enter batting average of the %d player : \t ", i + 1);
        scanf("%f",&player[i].batting_average);
    }
    for( i=0;i<10;i++)
    {
        if((strcmp(player[i].Pteam,"CSK"))==0)
        {
            team1[k++]=player[i];
        }
        else
        {
            team2[j++]=player[i];
        }
    }

    printf("\n now printing the player name teamwise ");
    printf("\n for the team CSK");
    for(i=0;i<k;i++)
    {
        printf("\n the name of %d player is :",i+1);
        puts(team1[i].Pname);
        printf("\n batting average is : %f ",team1[i].batting_average);
    }
    printf("\n for the team MI");
    for(i=0;i<j;i++)
    {
        printf("\n the name of %d player is : %s ",i+1);
        puts(team2[i].Pname);
        printf("\n batting average is : %f",team2[i].batting_average);
    }
    return 0;
 }
 