#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int x)
{
    if(x < 0) return false;
    long int pali = 0;
    int n = x;
    while(n != 0) {
        int last = n%10;
        pali = (10*pali) + last;
        n /= 10;
    }
    if(pali == x) return true;
    else return false;
}

int main()
{
   int n;
   cin >> n;
   cout << isPalindrome(n);
}
