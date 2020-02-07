#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> findNums(vector<int>& nums)
{
    vector<int> ans;
        for(int i=0;i<nums.size();++i){
            while(nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=i+1)
                ans.push_back(i+1);
        }
        return ans;
}

int main()
{
    vector<int> v, vFinal;
    int sajz;
    cout << "Enter length: ";
    cin >> sajz;
    for(int i = 0; i < sajz; i++) {
        cout << "Enter number " << i+1 << ": ";
        int br; cin >> br;
        v.push_back(br);
    }
    vFinal = findNums(v);
    for(int i = 0; i < vFinal.size(); i++) cout << vFinal[i] << " ";
    return 0;
}

