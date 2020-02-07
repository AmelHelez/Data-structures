#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrayPairSum(vector<int>& nums)
{
    int sum = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i += 2) sum += nums[i];
    return sum;
}

int main()
{
    vector<int> n;
    int size;
    cout << "Enter length: ";
    cin >> size;
    for(int i = 0; i < size; i++) {
        cout << "Enter number " << i+1 << ": ";
        int broj; cin >> broj;
        n.push_back(broj);
    }
    cout << arrayPairSum(n);
    return 0;
}


