#include <iostream>
#include <string>
#include <cctype>
using namespace std;


inline bool chk(char a) {
return ((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z'))
 || ((a >= '0') && (a <= '9'));
}
bool isPalindrome(string s)
{
    int length = s.length();
    if(length == 1) return true;
    int i = 0, j = length - 1;
    while(i <= j) {
        while((i <= j) && (!chk(s[i]))) i++;
        while((j >= i) && (!chk(s[j]))) j--;
        if((i < j) && (s[i] != s[j]) && (s[i] != s[j] + 32) && (s[j] != s[i] + 32)) return false;
        i++;
        j--;
    }
    return true;

}

int main()
{
    string ss;
    getline(cin,ss);
    cout << isPalindrome(ss);
}
