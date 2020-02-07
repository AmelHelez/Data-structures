#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool validMountain(vector<int>& v)
{
    int n = v.size(), up = 0, down = 0;
    for(int i = 0; i < n-1; i++) {
        if((!up && (v[i] >= v[i+1])) || (down && (v[i] <= v[i+1]))) return false;
        if(v[i] < v[i+1]) up = 1;
        if(v[i] > v[i+1]) down = 1;
    }
    return up && down;
}

int main()
{
    vector<int> v;
    int size; cin >> size;
    for(int i = 0; i < size; i++) {
        int br; cin >> br;
        v.push_back(br);
    }
    cout << validMountain(v);
    return 0;
}
