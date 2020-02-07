#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

void mergee(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = 0;
    for(int j = 0; j < n; j++) {
        while(i < m+j && nums1[i] <= nums2[j]) i++;
        if(i == m+j) {
            copy(nums2.begin() + j,nums2.end(),nums1.begin()+m+j);
            return;
        }
        else {
            for(int k = m+j; k>i; k--) nums1[k] = nums1[k-1];
            nums1[i++] = nums2[j];
        }
    }
}
int main()
{
    int sajz1, sajz2;
    cout << "Enter the length of the first array: ";
    cin >> sajz1;
    cout << "Now, enter the length of the second array: ";
    cin >> sajz2;
    vector<int> a,b;
    cout << "First array: \n";
    for(int i = 0; i < sajz1; i++) {
        cout << "Enter the " << i+1 << ". number: ";
        int br1; cin >> br1;
        a.push_back(br1);
    }
    cout << "================================\nSecond array: \n";

    for(int i = 0; i < sajz2; i++) {
        cout << "Enter the " << i+1 << ". number: ";
        int b2; cin >> b2;
        b.push_back(b2);
    }

    int range1, range2;
    cout << "Enter how many numbers you want to choose from the array1: ";
    cin >> range1;
    cout << "Now, for the second: ";
    cin >> range2;
    mergee(a,range1,b,range2);
    for(int i = 0; i < sajz1; i++) cout << a[i] << ", ";

}
