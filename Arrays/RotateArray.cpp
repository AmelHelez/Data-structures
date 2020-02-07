#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotatee(vector<int>& nums, int k)
{
   int n = nums.size();
    vector<int> numsCopy(nums);

    for(int i = 0; i < n; i++)
        nums[(i+k)%n] = numsCopy[i];
}

int main()
{
    int sajz;
    cout << "Enter the size: ";
    cin >> sajz;
    vector<int> v;
    for(int i = 0; i < sajz; i++) {
        cout << "Enter the " << i+1 << ". number: ";
        int br; cin >> br;
        v.push_back(br);
    }
    int n;
    cout << "Now enter the number from where you want to rotate: ";
    cin >> n;
    //rotateFull(a,n,7);
    rotatee(v,n);
    for(int i = 0; i < sajz; i++) cout << v[i] << " ";
    return 0;
}
