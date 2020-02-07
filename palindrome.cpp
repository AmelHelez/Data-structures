#include <iostream>
#include <string>
using namespace std;

inline bool chk(char a)
{
    return((a >= 'A') && (a <= 'Z')) || ((a >= 'a') && (a <= 'z')) || ((a >= '0') && (a <= '9'));
}

bool isPalindrome(string s)
{
    int len = s.length();
    if(len == 1) return true;
    int i = 0, j = len-1;
    while(i <= j)
    {
        while((i <= j) && (!chk(s[i]))) i++;
        while((i <= j) && (!chk(s[j]))) j--;
        if((i < j) && (s[i] != s[j]) && (s[i] != s[j] + 32) && (s[j] != s[i] +32)) return false;
        i++; j--;
    }
    return true;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin,str);
    if(!isPalindrome(str)) cout << "NOT a palindrome.";
    else cout << "PALINDROME!";
}
