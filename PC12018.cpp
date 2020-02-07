#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
int removeDuplicates(vector<int>& v)
{
    sort(v.begin(),v.end());
    int n = v.size();
    int j = 0;
    for(int i = 0; i < n-1; i++) {
        if(v[i] != v[i+1]) v[j++] = v[i];
    }
    v[j++] = v[n-1];
    return j;
}


int missingNumber(vector<int>& v)
{
    int n = v.size();
    return n*(n+1) / 2 - accumulate(v.begin(),v.end(),0);
}


int minimum(int arr[], int n)
{
    int smallest = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < smallest) smallest = arr[i];
    }
    return smallest;
}
*/

vector<int> rotate(vector<int>& v, int k)
{
    int n = v.size();
    vector<int> vCopy(v);
    for(int i = 0; i < n; i++) v[(i+k)%n] = vCopy[i];
    return v;
}
int main()
{

    vector<int> vec, vec2;
    int br;
    int size; cout << "Enter size: "; cin >> size;
    for(int i = 0; i <size; i++) {
        cout << "Enter number: " << i+1 << ":";
        cin >> br;
        vec.push_back(br);
    }
    vec2 = rotate(vec,3);
    for(int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
/*
    int s; cout << "Enter length: "; cin >> s;
    int a[s];
    for(int i = 0; i < s; i++) cin >> a[i];
    cout << minimum(a,s);
*/
}
