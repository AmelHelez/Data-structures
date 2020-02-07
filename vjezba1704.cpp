#include <iostream>
#include <vector>
using namespace std;


bool nonDecreasing(vector<int>& v)
{
    bool flag = false;
    int n = v.size();
    for(int i = 1; i < n; i++) {
        if(v[i] < v[i-1]) {
            if(!flag) {
                flag = true;
                if(i != 1 && i != n-1 && v[i] < v[i-2] && v[i-1] > v[i+1]) return false;
            }
            else return false;
        }
    }
    return true;
}

int main()
{
    vector<int> vv;
    int n,sajz = 3;
    for(int i = 0; i < sajz; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        vv.push_back(n);
    }
    if(nonDecreasing(vv)) cout << "The array is non-decreasing!";
    else cout << "The array is not non-decreasing..";
}
