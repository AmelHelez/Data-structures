#include <iostream>
using namespace std;


bool judgeCircle(string s)
{
    int x = 0;
    int y = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'U') y++;
        else if(s[i] == 'D') y--;
        else if(s[i] == 'R') x++;
        else if(s[i] == 'L') x--;
    }

    if(x == 0 && y == 0) return true;
    else return false;
}

int main()
{
    string ss;
    getline(cin,ss);
    if(judgeCircle(ss)) cout << "True.";
    else cout << "False";
    return 0;
}
