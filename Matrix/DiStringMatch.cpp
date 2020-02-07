#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> diString(string s)
{
    vector<int> res;
    for(int l = 0, h = s.length(), i = 0; i <= s.length(); i++)
    {
        res.push_back(i == s.length() || s[i] == 'I' ? l++ : h--);
    }
    return res;
}

int main()
{
    /*
    vector<int> v;
    int sajz;
    cout << "Size: ";
    cin >> sajz;
    int br;
    for(int i = 0; i < sajz; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> br; v.push_back(br);
    }*/
    string ss;
    getline(cin,ss);
    vector<int> v = diString(ss);
    for(int i = 0; i < v.size(); i++) cout << v[i] <<  " ";
}
