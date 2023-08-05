// We have many algorithm for pattern search in the text/string 

// n = length of text
// m = length of pattern

// PART 1 - For Changing Text(text size may differ between search then also they works)

// 1st Naive Solution 
// where we take a window of size m from text and for every possible window we check for the pattern  
// Time Complexity: O((n-m+1)*m)

// Naive Solution when all character are distinct 
// Time Complexity: O(n)

// 2nd Rabin Karp
// We preprocess the pattern and look for it within the text using hash_function here we don't search when hash_function does not match  
// it is better than naive solution but when every time hash_function matches then it become as like naive solution 
// Time Complexity: O((n-m+1)*m)

// 3rd KMP - Most Popular solution
// time complexity - O(n) , 
// it preprocess the pattern

// Many Other Solution are there like boyer moore , Z algorithm 


// PART 2 - When Text is fixed(when text does not change while searching)

// 1st Suffix Tree (It is a data structure)
// We preprocess the text and look for pattern within
// Time Complexity: O(m) but we take extra time to pre process the text first 


