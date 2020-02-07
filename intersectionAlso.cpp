#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> intersect(vector<int>& v1, vector<int>& v2)
{
    set<int> sett;
    vector<int> vec;
    int len1 = v1.size(), len2 = v2.size();
    for(int i = 0; i < len1; i++) sett.insert(v1[i]);
    for(int i = 0; i < len2; i++) {
        if(sett.count(v2[i])) {
            vec.push_back(v2[i]);
            sett.erase(v2[i]);
        }
    }
    return vec;
}

int main()
{
    vector<int> v1,v2,v3;
    int s1; cin >> s1;
    int s2; cin >> s2;
    int n;
    for(int i = 0; i < s1; i++) {
        cin >> n;
        v1.push_back(n);
    }
    for(int i = 0; i < s2; i++) {
        cin >> n;
        v2.push_back(n);
    }
    v3 = intersect(v1,v2);
    for(int i = 0; i < v3.size(); i++) cout << v3[i] << " ";
}
