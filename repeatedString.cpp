#include <iostream>
#include <string>
using namespace std;

int repeated(string s1,string s2)
{
    int len1 = s1.length(), len2 = s2.length(), cnt = 1;
    string t = s1;
    while(t.length() < len2) {
        t += s1;
        cnt++;
    }
    if(t.find(s2) != string::npos) return cnt;
    t += s1;
    return (t.find(s2) != string::npos) ? cnt+1 : -1;
}

int main()
{
    string st1,st2;
    getline(cin,st1);
    getline(cin,st2);
    cout << repeated(st1,st2);
}
