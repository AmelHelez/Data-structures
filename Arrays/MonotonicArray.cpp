#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isMonotonic(vector<int>& nums)
{
    bool f1 = true, f2 = true;
    int n = nums.size();
    for(int i = 1; i < n; i++) {
        if(nums[i-1] < nums[i]) f2 = false;
        else if(nums[i-1] > nums[i]) f1 = false;
        if(!f1 && !f2) return false;
    }
    return true;
}
int main()
{

    cout << "Enter array length: ";
    int sajz;
    cin >> sajz;
    vector<int> v;
    for(int i = 0; i < sajz; i++)
    {
        cout << "Enter the " << i+1 << ". number : ";
        int br; cin >> br;
        v.push_back(br);
    }
    if(isMonotonic(v)) cout << "The array is monotonic";
    else cout << "The array is not monotonic.";
    return 0;
}
