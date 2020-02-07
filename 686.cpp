#include <iostream>
#include <string>
using namespace std;

int repeatedString(string A, string B)
{
   int n1 = A.length();
   int n2 = B.length();
   int cnt = 1;
   string temp = A;
   if(temp.length() >= n2) return -1;
   while(temp.length() <= n2) {
    temp += A;
    cnt++;
   }
   return cnt;

}
int main()
{
    string s1;
    string s2;
    cout << "Enter the first string: ";
    getline(cin,s1);
    cout << "Now enter the second string: ";
    getline(cin,s2);
    cout << "The first string has to be repeated " << repeatedString(s1,s2) << " times.";
    return 0;

}
