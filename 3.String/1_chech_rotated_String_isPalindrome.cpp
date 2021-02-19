
// Check if a string is a rotated palindrome or not
// Given a string, check if it is a rotated palindrome or not.

// Example -
/*
'CBAABCD' is a rotated palindrome as it is a rotation of palindrome 'ABCDCBA'.
'BAABCC' is a rotated palindrome as it is a rotation of palindrome 'ABCCBA'.
*/
#include<iostream>
using namespace std;
// 1. Approach Time - 0(NlogN).
// Rotated the string begin upto length of the string.
// and each Rotated string is Palindrome or not
// if no one string is palindrome then 
// this is not a rotated palindroming string.
// Sample code
/*

bool isPalindrome(string)
{
	int s = 0;
	int e = string length-1;
	while(s<e)
	{
		if(string[s]!=string[e])
		{
			return false;
		}
		s++;
		e--;
	}
	return true;
}	

	for(int i = 0; i<string length; i++)
	{
		rotated(string.begin(); string.begin()+i; string.end());
		if(isPalindrome(string)
		{
			flag = true;
			break;
		}
	}

	if(flag){
		cout<<"string is palindrome";
	}
	else{
		cout<<"String is not palindrome";
	}
*/ 


// 2. Approach  Time - 0(NlogN), Space - 0(N)
// Here is N - length of the string.

// The basic approach to solve this problem is
// concetinate the string with itself
// Example - str = 'CBAABCD' , 'CBAABCDCBAABCD'
// In the middle of concatinated string 'ABCDCBA' this palidromic string is present.
// To solve this problem use sliding window technique begin upto original length of the string.
// and check is the string the string is palindrome or not.
bool isPalindrome(string str, int i , int e)
{
    while(i<e)
    {
        if(str[i]!=str[e])
        {
            return false;
        }
        i++;
        e--;
    }
    return true;
}
bool checkPalindrome(string str, int len)
{
    int e = (str.length()/2)-1;
    for(int i =0; i<str.length()-len; i++)
    {
        if(isPalindrome(str, i, e))
        {
            for(int j = i; j<=e; j++)
            {
                cout<<str[j];
            }
            cout<<endl;
            return true;
        }
        else if(e<(str.length()-1))
        {
            e++;
        }
    }
    return false;
}
int main()
{
    string str;
    getline(cin, str);
    int len = str.length();
    str = str+str;

    if(checkPalindrome(str, len))
    {
        cout<<"Yes, String is Palindrome "<<endl;
    }
    else
    {
        cout<<"No, String is Palindrome"<<endl;
    }
    return 0;
}