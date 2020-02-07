#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int peakIndexInMountain(vector<int>& v)
{
    int len = v.size();
    int a = 0, b = len, c = 0;
    while(a < b) {
        c = (a+b) / 2;
        if(v[c] > v[c+1]) b = c;
        else a = c+1;
    }
    return b;
}

int main()
{
    vector<int> v;
    cout << "Enter length: ";
    int len; cin >> len;
    for(int i = 0; i < len; i++)
    {
        cout << "Enter number " << i+1 << ": ";
        int b; cin >> b;
        v.push_back(b);
    }
    cout << peakIndexInMountain(v);
}
