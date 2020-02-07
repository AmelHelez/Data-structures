#include <iostream>
#include <cmath>
using namespace std;

int count(int n)
{
    int sum = 0;
    while(n)
    {
        sum += pow(n%10,2);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int t = 6;
    while(t--) {
        n  = count(n);
        if(n == 1) return true;
    }
    return false;
}

int main()
{
    if(isHappy(19)) cout << "True.";
    else cout << "False.";
}
