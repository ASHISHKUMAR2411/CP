// lets suppose A = 5, B = 6,
// SO Output for n = 5 => [5,6,55,56,65]

#include<bits/stdc++.h>
#include <boost/lexical_cast.hpp>  
using namespace std;

void printNthDigit(int n, int A, int B){
    queue<int> queue;
    queue.push(boost::lexical_cast<string>(A));
    queue.push(boost::lexical_cast<string>(B));
    for (int i = 0; i < n; i++) {
        string s = queue.top();
        cout << s << " ";
        queue.pop();
        queue.push(s + to_string(A));
        queue.push(s + to_string(B));
    }
}

int main() {
    srand(time(0));
    printNthDigit(rand()%100, 5, 6);
    return 0;
}