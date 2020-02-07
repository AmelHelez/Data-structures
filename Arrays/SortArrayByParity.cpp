#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sortArray(vector<int>& v)
{
    int i = 0;
    for(int j = 0; j < v.size(); j++) {
        if(v[j] % 2 == 0) {
            swap(v[i],v[j]);
            i++;
        }
    }
    return v;
}

int main()
{
    int sajz;
    cout << "Enter length: ";
    cin >> sajz;
    vector<int> v;
    for(int i = 0; i < sajz; i++) {
        cout << "Enter number " << i+1 << ": ";
        int br; cin >> br;
        v.push_back(br);
    }
    vector<int> vv = sortArray(v);
    for(int i = 0; i < sajz; i++) cout << vv[i] << " ";

}
