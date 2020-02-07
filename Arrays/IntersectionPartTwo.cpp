#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
void intersection(int a[],int n, int b[], int m)
{
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] > b[j]) { j++; }
        else
        if(b[j] > a[i]) { i++; }
        else {
            cout << a[i] << " ";
            i++; j++;
        }
    }
    */

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
vector<int> ans;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int temp = 0;
    int len1 = nums1.size();
    int len2 = nums2.size();
    int i = 0, j = 0;
    while(i < len1 && j < len2) {
        if(nums1[i] == nums2[j]) {
            ans.push_back(nums1[i]);
            i++; j++;
        }
        else if(nums1[i] < nums2[j]) i++;
        else if(nums2[j] < nums1[i]) j++;
    }
    return ans;

}



int main()
{
    /*
    int n1,n2;
    cin >> n1;
    cin >> n2;
    int a[n1],b[n2];
    for(int i = 0; i < n1; i++) cin >> a[i];
    for(int i = 0; i < n2; i++) cin >> b[i];
    intersection(a,n1,b,n2);
    */
    vector<int> prvi, drugi;

    int broj,br;
    cout << "Enter the length of the first one: ";
    int s1,s2;
    cin >> s1;
    cout << "Now, of the second: ";
    cin >> s2;
    cout << "First vector \n";
    for(int i = 0; i < s1; i++) {
        cout << "Enter the " << i+1 << ". number: ";
        cin >> broj;
        prvi.push_back(broj);
    }
    cout << "============================\n";
    cout << "Second Array \n";
    for(int i = 0; i < s2; i++) {
        cout << "Enter the " << i+1 << ". number: ";
        cin >> br;
        drugi.push_back(br);
    }

    vector<int> kv;
    kv = intersect(prvi,drugi);
    for(int i = 0; i < kv.size(); i++) cout << kv[i] << " ";
    return 0;
}
