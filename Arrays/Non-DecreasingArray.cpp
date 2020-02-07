#include <iostream>
#include <vector>
using namespace std;
/*
void isNonDecreasing(int arr[], int size)
{
    int temp = 0;
    int cnt = 0;
    for(int i = 0; i < size; i++) {
    if(arr[i] > arr[i+1]) {
            cout << "The number " << arr[i] << " is greater than " << arr[i+1] << endl;
    cout << "Please modify the number " << arr[i] << " to be smaller than " << arr[i+1] << endl;
        cnt++;
        if(cnt > 1) break;
        cin >> temp;
        arr[i] = temp;
    }
    }
    if(cnt > 1) cout << "False.";
    else cout << "True.";

}
*/
bool checkPossibility(vector<int>& nums)
{
    if(nums.size() <= 1) return true;
    bool flag = false;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] < nums[i-1]) {
            if(!flag) {
                flag = true;
                if(i != 1 && i != nums.size() - 1 && nums[i] < nums[i-2] && nums[i-1] > nums[i+1]) return false;
            }
            else return false;
        }
    }
    return true;
}

int main()
{
    cout << "Enter the size of the array: ";
    int s; cin >> s;
    vector<int> v;
    for(int i = 0; i < s; i++) {
        cout << "Enter " << i+1 << " number: ";
        int broj; cin >> broj;
        v.push_back(broj);
    }
    if(!checkPossibility(v)) cout << "False";
    else cout << "True.";
}
