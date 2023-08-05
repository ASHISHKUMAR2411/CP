// CPP program to give a brief about String
// String syntax
// string str1 = "name";
// string str2("Name");
// string str3(str2);
// string str4(noOfTimes,character);
// string str5 = str4;
// string str6(strName,fromIndex,NumberOfCharacter);
// string str7(str6.brgin(),str6.begin()+5);

// LENGTH () length in string is used to calculate the length of the string

// APPEND () This member function appends characters in the end of string.
//? Syntax 1 : Appends the characters of string str. It Throws length_error if the resulting size exceeds the maximum number of characters.
//? string& string::append (const string& str)

// str :  is the string to be appended.
// Returns :  *this

//? Syntax 2 : Appends at most, str_num characters of string str, starting with index str_idx. It throws out_of_range if str_idx > str. size(). It throws length_error if the resulting size exceeds the maximum number of characters.
//? string& string::append (const string& str, size_type str_idx, size_type str_num)

// str : is the string to be appended
// str_num : being number of characters
// str_idx : is index number.
// Returns : *this.

// ? Syntax 3: Appends the characters of the C-string cstr. Throw length_error if the resulting size exceeds the maximum number of characters.
// string& string::append (const char* cstr)
// here *cstr can be simple string which we want to append
// *cstr : is the pointer to C-string.
// Note : that cstr may not be a null pointer (NULL).
// Return : *this

// ?Syntax 4: Appends chars_len characters of the character array chars. Throws length_error if the resulting size exceeds the maximum number of characters.
// string& string::append (const char* chars, size_type chars_len)

// *chars is the pointer to character array to be appended.
// chrs_len : is the number of characters from *chars to be appended.
// Note that chars must have at least chars_len characters.
// Returns : *this.

// syntax - 5
//  we have the stringName.append(size,charater to append that muvh size );
// return *this

// syntax - 6
// here we have the strinName.append(starting iterator,ending iterator )
// return *this

//
#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;
// Function to demonstrate find_first_not_of
void find_first_not_ofDemo(string str1, string str2)
{
    // Finds first character in str1 which
    // is not present in str2
    string::size_type ch = str1.find_first_not_of(str2);
    cout << "First unmatched character : ";
    cout << str1[ch];
}
int main()
{
    /* string initialisation */

    string str1 = "Ashish Kumar";
    string str2("Prince Kumar");
    // cout<<tolower(str1[0]);
    string str3(str2);
    string str4(5, '*');
    string str5 = str4;
    string str6(str1, 3, 6);
    string str7(str2.begin(), str2.begin() + 5);
    const char *ptr = " str1";

    /* here calling them to see the result  */
    // cout << str1 << endl;
    // cout << str2 << endl;
    // cout << str3 << endl;
    // cout << str4 << endl;
    // cout << str5 << endl;
    // cout << str6 << endl;
    // cout << str7 << endl;
    // str4.clear();
    // int strlen = str1.length();
    // cout << strlen << "\n";

    /* APPEND secetion */
    // str1.append(str2);
    // //? append here adds the string to the end
    // cout << str1 << endl;
    // str2.append(str1, 2, 4);
    // cout << str2 << endl;
    // str4.append("Geeks For Geeks ");
    // cout << str4 << endl;
    // str4.append(ptr);
    // cout << str4 << endl;
    // str3.append("Ashish", 5);
    // cout << str3 << endl;
    // str5.append(5, ')');
    // cout<<str5<<endl;
    // str5.append(str1.begin()+2,str1.begin()+11);
    // cout<<str5<<endl;

    // ASSIGN section
    // here we assign the string with the other element its changes the whole
    // syntax-1 strName.assign(noOfcharacter,character);
    // cout << str1 << endl;
    // str1.assign(2, '%');
    // cout << str1 << endl;

    // syntax-2 strName.assign("string");
    // str1.assign("Ashish Kumar");
    // cout << str1 << endl;
    // str1.assign(str2);
    // cout << str1 << endl;
    // str1.assign(str4);
    // cout << str1 << endl;
    // string str9;
    // cout << "enter the string : ";
    // cin >> str9;
    // str1.assign(str9);
    // cout << str9 << " " << str1 << endl;
    // str1.assign("Ashish ",9);
    // cout << str1 << endl;
    // str1.assign(str2.begin(),str2.begin()+5);
    // cout << str1 << endl;
    // str1.assign(str2,2,6);
    // cout << str1 << endl;

    // AT uses to find the element

    // cout<<str2.at(2)<<endl;
    // char ch ;
    // ch = str1.at(2);
    // cout<<ch<<endl;

    // BACK
    // cout << str1.back() << endl;

    // BEGIN - it return a pointer so we have to
    // cout << *str1.begin() << endl;

    // CSTR used to return a pointer which is pointed to a null terminated string .
    // cout << *(str1.c_str() + 5) << endl;

    // CAPACITY return a number of element it can hold without alloting ectra space .
    // cout << str1.capacity() << endl;

    // I KNOW ABOUT THE CBEGIN , CEND , CLEAR , COMPARE , COPY ,  CRBEGIN , CREND ,
    // DATA
    // cout << str1.data() << endl;

    // EMPTY  return boolean value whether the string is empty or not
    // cout << str1.empty() << endl;

    // FIND has four syntax
    // in this it will the position of first encounter of 'character' given by you otherwise return invalid numbers
    // cout << str1.find('g') << endl;
    // in this it will ask for string to search , then it will ask for the number of position from where search should start , then it will ask for the number of character from the given string to search from the starting .
    // cout << str1.find("sh", 2, 2) << endl;
    // in this syntax we have  string and the position to search for
    // cout<<str1.find("sh", 1)<<endl;

    // FINDFIRSTNOTOF is used to find the character other than the given it wil ignore the character .
    // in this syntax it will avoid the occurenece of the 's' and it will start doing that from the positon of 1 from the string and it will return the position of the character other than 'c' as first encuntered .
    // cout << str1.find_first_not_of('s', 1) << endl;

    // in this it will ignore the string and return the position of first encountered .
    // cout << str1.find_first_not_of("sh", 1) << endl;

    //
    // cout << str1.find_first_not_of("ash", 0, 1) << endl;

    // find_first_not_ofDemo(str1, str2);
    // Syntax 2: Search for the first character from index idx that is not an element of the string str.

    // size_type string::find_first_not_of (const string& str, size_type idx) const
    // str : Another string with the set of characters
    // to be used in the search.
    // idx : is the index number from where we have to
    // start finding first unmatched character.

    // Finds first character in str1 from index 3 which
    // is not present in str2
    // string::size_type ch = str1.find_first_not_of(str2, 3);
    // cout << "\nFirst unmatched character : ";
    // cout << str1[ch];

    //     Syntax 3: Searches for the first character that is or is not also an element of the C-string cstr.

    // size_type string::find_first_not_of (const char* cstr) const
    // cstr : Another C-string with the set of characters
    // to be used in the search.

    // Finds first character in str which
    // is not present in "geeksforgeeks"
    // string::size_type ch1 = str1.find_first_not_of("geeksforgeeks");
    // cout << "\nFirst unmatched character : ";
    // cout << str1[ch1];

    // Finds first character in str from 5th index which
    // is not present in "geeksforgeeks"
    // string::size_type ch2 = str1.find_first_not_of("geeksForgeeks", 5);
    // cout << "\nFirst unmatched character : ";
    // cout << str1[ch2];

    // Finds first character in str which
    // is not equal to character 'G'
    // string::size_type ch3 = str1.find_first_not_of('G');
    // cout << "\nFirst unmatched character : ";
    // cout << str1[ch3];

    // Finds first character in str from 6th index which
    // is not equal to character 'G'
    // string::size_type ch4 = str1.find_first_not_of('G', 7);
    // cout << "\nFirst unmatched character : ";
    // cout << str1[ch4];

    // Finds first character in str from 4th index which
    // is not equal to any of the first 3 characters from "svmnist"
    // string::size_type ch5 = str1.find_first_not_of("svmnist", 4, 3);
    // cout << "\nFirst unmatched character : ";
    // cout << str1[ch5];

    // FINDFIRSTOF
    //     std::find_first_of is used to compare elements between two containers. It compares all the elements in a range [first1,last1) with the elements in the range [first2,last2), and if any of the elements present in the second range is found in the first one , then it returns an iterator to that element.

    // If there are more than one element common in both the ranges, then an iterator to the first common element present in the first container is returned. In case there is no match, then iterator pointing to last1 is returned.

    // It can be used in two ways as shown below:

    // Comparing elements using ==:
    // Syntax:

    // Template
    // ForwardIterator1 find_first_of(ForwardIterator1 first1,
    //    ForwardIterator1 last1,
    //    ForwardIterator2 first2,
    //    ForwardIterator2 last2);

    // first1: Forward iterator to the first element
    //    in the first range.
    // last1: Forward iterator to the last element
    //    in the first range.
    // first2: Forward iterator to the first element
    //    in the second range.
    // last2: Forward iterator to the last element
    //    in the second range.

    // Return Value: It returns an iterator to the
    //               first element in [first1,last1) that is part of
    //               [first2,last2). If no matches are found or [first2,
    //               last2) is empty, the function returns last1.

    // Defining first container
    vector<int> v = {1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8}, i;

    // Defining second container
    vector<int> v1 = {1, 3, 10};

    vector<int>::iterator ip;

    // Using std::find_first_of
    ip = std::find_first_of(v.begin(), v.end(), v1.begin(),
                            v1.end());

    // Displaying the first common element found
    cout << *ip << "\n";

    // Finding the second common element
    ip = std::find_first_of(ip + 1, v.end(), v1.begin(),
                            v1.end());

    // Displaying the second common element found
    cout << *ip << "\n";
    // Here, in both the vectors, the first common element is 1 and to find the second common element, we have passed the beginning of the first range as the element next to the first common element already found.

    return 0;
}
