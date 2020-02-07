#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isNonDecr(vector<int>& v)
{
    bool flag = false;
    int n = v.size();
    if(n <= 1) return false;
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
    int n;
    int s; cout << "Enter length: "; cin >> s;
    for(int i = 0; i < s; i++) {
        cin >> n; vv.push_back(n);
    }
    cout << isNonDecr(vv);
}
