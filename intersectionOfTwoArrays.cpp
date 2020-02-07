#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int>& v1, vector<int>& v2)
{
    vector<int> vec;
    int i = 0, j = 0;
    int len1 = v1.size(), len2 = v2.size();
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    while(i < len1 && j < len2)
    {
        if(v1[i] == v2[j]) {
            vec.push_back(v1[i]);
            i++; j++;
        }
        else if(v1[i] > v2[j]) j++;
        else i++;
    }
    return vec;
}

int main()
{
    vector<int> v1,v2,v3;
    int len1,len2;
    cout << "Enter length for first array: ";
    cin >> len1;
    cout << "Now for the second: ";
    cin >> len2;
    int n;
    for(int i = 0; i < len1; i++) {
        cin >> n; v1.push_back(n);
    }
    cout << "\n=====================================\n";
    for(int i = 0; i < len2; i++) {
        cin >> n; v2.push_back(n);
    }
    cout << "\n=================================\n";
    v3 = intersection(v1,v2);
    for(int i = 0; i < v3.size(); i++) cout << v3[i] << " ";
}
