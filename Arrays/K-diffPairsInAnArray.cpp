#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int findPairs(vector<int>& nums, int k)
{
    sort(nums.begin(),nums.end());
    if(nums.size() < 2) return 0;
    int res = 0, j = 1;
    for(int i = 0; i < nums.size()-1; i++) {
        j = i+1;
        while(j < nums.size()) {
            if(nums[j] >= nums[i]+k) {
                if(nums[i] == nums[j] - k) res++;
                break;
            }
            j++;
        }
        while(nums[i] == nums[i+1]) i++;
    }
    return res;
}

int main()
{
    vector<int> v;
    int k, broj;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    for(int i = 0; i < size; i++) {
        cout << "Enter the " << i+1 << ". number: ";
        cin >> broj;
        v.push_back(broj);
     }

     cout << "\nEnter the k-diff integer: ";
     cin >> k;
     cout << findPairs(v,k);
}
