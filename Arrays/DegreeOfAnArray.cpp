#include <iostream>
#include <map>
#include <vector>
using namespace std;

int findShortestSubArray(vector<int>& nums)
{
    /*
    unordered_map<int,int> cnt,begin;
    int freq = 0, res = INT_MAX;
    for(int i = 0; i < nums.size(); i++)
    {
        int n = nums[i];
        if(!begin.count(n)) begin[n] = i;
        if(++cnt[n] >= freq) {
            res = cnt[n] == freq ? min(i - begin[n] + 1, res) : i - begin[n] + 1;
            freq = cnt[n];
        }
    }
    return nums.empty() ? 0 : res;
*/
   map<int, int> idx,cnt;
   int degree = 0, minlen = nums.size();
   for(int i = 0; i < nums.size(); i++) {
    if(!idx.count(nums[i])) idx[nums[i]] = i;
    if(++cnt[nums[i]] == degree) minlen = min(minlen, i - idx[nums[i]] + 1);
    if(cnt[nums[i]] > degree) {
        degree = cnt[nums[i]];
        minlen = i - idx[nums[i]] + 1;
    }
   }
   return minlen;
}


int main()
{
    vector<int> v;
    int sajz;
    cout << "Enter length: ";
    cin >> sajz;
    for(int i = 0; i < sajz; i++) {
        int broj;
        cout << "Enter number " << i+1 << ": ";
        cin >> broj;
        v.push_back(broj);
    }
    cout << findShortestSubArray(v);
    return 0;
}
