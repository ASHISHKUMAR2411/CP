/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int min = INT_MAX;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] < min){
                min = a[i];
            }
        }
        if(min == a[0]) cout << "YES\n";
        else cout << "NO\n";
    }
    
}