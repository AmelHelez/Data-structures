#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int missing(vector<int>& v)
{
    int len = v.size();
    return len*(len+1)/2 - accumulate(v.begin(),v.end(),0);
}

int main()
{
    vector<int> vv;
    int s, broj;
    cout << "Size: ";
    cin >> s;
    for(int i = 0; i < s; i++) {
        cin >> broj;
        vv.push_back(broj);
    }
    cout << missing(vv);
}
