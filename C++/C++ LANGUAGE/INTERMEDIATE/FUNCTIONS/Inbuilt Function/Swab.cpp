
// Swab
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     char s1[] = "Ashish";
//     char s2[10];
//     swab(s1,s2,2);
//     cout<<s2;
//     return 0;
// }
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

/* global arrays: destination[] initialized with zeros */
char source [7] = "ABCDEF";
char destination [7];

main ()
{
  swab (source, destination, 6);
  printf ("swab: %s -> %s\n", source, destination);
  return 0;
}