#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

/*
bool isNonDecr(vector<int>& v)
{
    bool flag = false;
    int n = v.size();
    for(int i = 1; i < n; i++) {
        if(v[i] < v[i-1]) {
            if(!flag) {
                flag = true;
                if(i != 1 && i != n-1 && v[i] < v[i-2] && v[i-1] > v[i+1]) return false;
            }
            else return false;
        }
    }
    return true;
}


int repeat(vector<int>& v)
{
    int n = v.size();
    vector<int>::iterator it = v.begin();
    while(it != v.end()) {
        if(count(v.begin(),v.end(), *it) > 1) break;
        else it++;
    }
    return *it;
}


vector<int> rotate(vector<int>& v,int k)
{
    int n = v.size();
    vector<int> vCopy(v);
    for(int i = 0; i < n; i++) v[(i+k)%n] = vCopy[i];
    return v;
}


bool isMonotonic(vector<int>& v)
{
    bool f1 = true, f2 = true;
    int n = v.size();
    for(int i = 1; i < n; i++) {
        if(v[i-1] > v[i]) f2 = false;
        else if(v[i] > v[i-1]) f1 = false;
        if(!f1 && !f2) return false;
    }
    return true;
}


int removeDuplicates(vector<int>& v)
{
    int n = v.size();
    int j = 0;
    if( n == 0 || n == 1) return n;
    for(int i = 0; i < n-1; i++) {
        if(v[i] != v[i+1]) v[j++] = v[i];
    }
    v[j++] = v[n-1];
    return j;
}


vector<int> squares(vector<int>& v)
{
    int n = v.size();
    for(int i = 0; i < n; i++) v[i] = v[i]*v[i];
    sort(v.begin(),v.end());
    return v;
}


int peakIndex(vector<int>& v)
{
    int n = v.size();
    if(n < 3) return -1;
    int begin = 0, end = n, middle = 0;
    while(begin < end) {
        middle = (begin+end) / 2;
        if(v[middle] > v[middle+1]) end = middle;
        else begin = middle+1;
    }
    return end;
}


bool isMountain(vector<int>& v)
{
    int n = v.size(),up = 0, down = 0;
    for(int i = 0; i < n-1; i++) {
        if((!up && (v[i] >= v[i+1])) || (down && v[i] <= v[i+1])) return false;
        if(v[i] < v[i+1]) up = 1;
        if(v[i] > v[i+1]) down = 1;
    }
    return up & down;
}


vector<int> parity(vector<int>& v)
{
    int n = v.size();
    int i = 0;
    for(int j = 0; j < n; j++) {
        if(v[j] % 2 == 0) {
            swap(v[i],v[j]); i++;
        }
    }
    return v;
}


vector<int> disappear(vector<int>& v)
{
    int n = v.size();
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        while(v[i] != i+1 && v[v[i]-1] != v[i]) swap(v[i],v[v[i]-1]);
    }
    for(int i = 0; i < n; i++) {
        if(v[i] != i+1) ans.push_back(i+1);
    }
    return ans;

}


int partition(vector<int>& v)
{
    int n = v.size();
    int sum = 0;
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i += 2) sum += v[i];
    return sum;
}


int degee(vector<int>& v)
{
    int n = v.size(), degree = 0;
    map<int,int> idx,cnt;
    for(int i = 0; i < v.size(); i++) {
        if(!idx.count(v[i])) idx[v[i]] = i;
        if(++cnt[v[i]] == degree) n = min(n, i-idx[v[i]]+1);
        if(cnt[v[i]] > degree) {
            degree = cnt[v[i]];
            n = i-idx[v[i]]+1;
        }
    }
    return n;
}

vector<int> twoSum(vector<int>& v,int target)
{
    int n = v.size();
    int tmp;
    int left = 0, right = n-1;
    vector<int> res(2,0);
    sort(v.begin(),v.end());
    while(left < right) {
        tmp = v[left] + v[right];
        if(tmp == target) {
            res[0] = left+1;
            res[1] = right+1;
            break;
        }
        else if(tmp > target) right--;
        else left++;
    }
    return res;
}
*/

 int kDiffPairs(vector<int>& v,int k)
 {
     int n = v.size();
     sort(v.begin(),v.end());
     int res = 0, j = 1;
     for(int i = 0; i < n-1; i++) {
        j = i+1;
        while(j < n) {
            if(v[j] >= v[i]+k) {
                if(v[i] == v[j]-k) res++; break;
            }
            j++;
        }
        while(v[i] == v[i+1]) i++;
     }
     return res;
 }

 vector<int> intersection(vector<int>& v1, vector<int>& v2)
 {
     int len1 = v1.size(), len2 = v2.size();
     vector<int> ans;
     sort(v1.begin(),v1.end());
     sort(v2.begin(),v2.end());
     int temp;
     int i = 0, j = 0;
     while(i < len1 && j < len2) {
        if(v1[i] == v2[j]) {
            ans.push_back(v1[i]);
            i++; j++;
        }
        else if(v1[i] > v2[j]) j++;
        else if(v1[i] < v2[j]) i++;
     }
     return ans;
 }

inline bool chk(char a)
{
    return ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= '0' && a <= '9'));
}

bool isPalindrome(string s)
{
    int len = s.length();
    int i = 0, j = len-1;
    while(i <= j) {
        while((i <= j) && (!chk(s[i]))) i++;
        while((j >= i) && (!chk(s[j]))) j--;
        if((i < j) && (s[i] != s[j]) && (s[i] != s[j] + 32) && (s[j] != s[i] + 32)) return false;
    i++; j--;
    }
    return true;
}

int main()
{
    /*
    vector<int> v1,v2,v3;
    int n;
    int size; cout << "Size: "; cin >> size;
    for(int i = 0;i < size; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> n; v1.push_back(n);
    }

    cout << isNonDecr(v1);
    cout << repeat(v1);
    v2 = rotate(v1,2);
    for(int i = 0; i < v2.size();i++) cout << v2[i] << " ";

    cout << isMonotonic(v1);

   cout << removeDuplicates(v1);

   v2 = squares(v1);
   for(int i = 0; i < v2.size(); i++) cout << v1[i] << " ";

   cout << peakIndex(v1);

   cout << isMountain(v1);

   v2 = parity(v1);
   for(int i = 0; i < v2.size(); i++) cout << v2[i] << " ";

   v2 = disappear(v1);
   for(int i = 0; i < v2.size(); i++) cout << v2[i] << " ";

   cout << partition(v1);

   cout << degree(v1);
 v2 = twoSum(v1,9);
   for(int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
   cout << kDiffPairs(v1,2);
   */
   string s;
   getline(cin,s);
   cout << isPalindrome(s);
}
