#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    set<int> uset;
    for(int i = 0; i<nums1.size(); i++)
        uset.insert(nums1[i]);

    vector<int> res;
    for(int i = 0; i<nums2.size(); i++) {
        if(uset.count(nums2[i])) {
            res.push_back(nums2[i]);
            uset.erase(nums2[i]);
        }
    }

    return res;
}

int main()
{
    vector<int> n1,n2;
    int size1,size2;
    cout << "Enter array 1 length: ";
    cin >> size1;
    cout << "Enter array 2 length: ";
    cin >> size2;
    for(int i = 0; i < size1; i++) {
        cout << "Enter number " << i+1 << ": ";
        int broj; cin >> broj;
        n1.push_back(broj);
    }
    cout << "\n=======================================\n";
    for(int i = 0; i < size2; i++) {
        cout << "Enter number " << i+1 << ": ";
        int br; cin >> br;
        n2.push_back(br);
    }
    vector<int> v = intersection(n1,n2);
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
}
