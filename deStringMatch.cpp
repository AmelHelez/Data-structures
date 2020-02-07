#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> diString(string s)
{
   vector<int> vec;
   int n = s.length();
   for(int i = 0, l = 0, h = n; i <= n; i++)
    vec.push_back(i == n || s[i] == 'I' ? l++ : h--);
   return vec;
}

int main()
{
    vector<int> v;
    string ss;
    getline(cin,ss);
    v = diString(ss);
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
}
