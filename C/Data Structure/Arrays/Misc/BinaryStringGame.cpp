// We define a function f on a binary string S of length N as follows :
// f(S) =∑| Si + 1−Si |
//JJ and Uttu have a binary string S of length N and they decide to play a game using it.The rules of the game are as follows :
// JJ starts the game with players making moves in alternate turns thereafter.In one move,
// a player can pick L, R such that 1≤L≤R≤N and flip all the characters in SL…R(Flipping a character means changing 0 to 1 or 1 to 0).
// A player can only make a move if that move increases the value of f(S).
// The player who can not make any further moves loses.
// Which player(out of JJ and Uttu) will win the game, assuming that both the players play optimally ?

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        bool arr[n];
        for(int i = 0; i < n; i++){
            arr[i] = s[i] - '0';
        }
        
    }
}
