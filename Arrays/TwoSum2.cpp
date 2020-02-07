#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
    sort(numbers.begin(),numbers.end());
  /*
    int l = 0, r = numbers.size() - 1;
    while(l < r) {
        if(numbers[l] + numbers[r] == target) break;
        if(numbers[l] + numbers[r] < target) l++;
        else r--;
    }
    return vector<int>({l+1,r+1});
*/
    int n = numbers.size();
    int left = 0, right = n - 1;
    int tmp;
    vector<int> ret(2,0);

    while(left < right) {
        tmp = numbers[left] + numbers[right];
        if(tmp == target) {
            ret[0] = left+1;
            ret[1] = right+1;
            break;
        }
        else if(tmp > target) right--;
        else left++;
    }
    return ret;
}

int main()
{
    vector<int> v;
    int t;
    cout << "Enter the size of the array: ";
    int s; cin >> s;
    for(int i = 0; i < s; i++)
    {
        int broj;
        cout << "Enter the " << i+1 << ". number: ";
        cin >> broj;
        v.push_back(broj);
    }
    cout << "\nNow enter the target number: ";
    cin >> t;
    vector<int> twoSuma = twoSum(v,t);
    for(int i = 0; i < twoSuma.size(); i++) cout << twoSuma[i] << " ";
    return 0;
}
