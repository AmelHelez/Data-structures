#include <iostream>
#include <string>
using namespace std;

bool robot(string s)
{
    int x = 0, y = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'U') x++;
        if(s[i] == 'D') x--;
        if(s[i] == 'R') y++;
        if(s[i] == 'L') y--;
    }
    if(x == 0 && y == 0) return true;
    else return false;
}

int main()
{
    string ss;
    getline(cin,ss);
    cout << robot(ss);
}
