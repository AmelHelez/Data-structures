#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
using namespace std;
/*
bool isNonDecr(vector<int>& v)
{
    bool flag = false;
    int n = v.size();
    if(n <= 1) return false;
    for(int i = 1; i < n; i++) {
        if(v[i] < v[i-1]) {
            if(!flag) {
                flag = true;
                if(i != 1 && i != v.size()-1 && v[i] < v[i-2] && v[i-1] > v[i+1]) return false;
            } else return false;
        }
    }
    return true;
}


int nRepeat(vector<int>& v)
{
    vector<int>::iterator it = v.begin();
    while(it != v.end()) {
        if(count(v.begin(),v.end(),*it) > 1) break;
        else it++;
    }
    return *it;
}


void rotatee(vector<int>& v, int k)
{
    int n = v.size();
    vector<int> vCopy(v);
    for(int i = 0; i < n; i++) {
        v[(i+k)%n] = vCopy[i];
    }
}


bool isMonotonic(vector<int>& v)
{
    int n = v.size();
    bool f1 = true, f2 = true;
    for(int i = 1; i < n; i++) {
        if(v[i-1] < v[i]) f2 = false;
        else if(v[i-1] > v[i]) f1 = false;
        if(!f1 && !f2) return false;
    }
    return true;
}


int removee(vector<int>& v)
{
    int n = v.size();
    if(n == 0 || n == 1) return n;
    sort(v.begin(),v.end());
    int j = 0;
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
    int n = v.size(), up = 0, down = 0;
    if(n < 3) return false;
    for(int i = 0; i < n-1; i++) {
        if((!up && v[i] >= v[i+1]) || (down && v[i] <= v[i+1])) return false;
        if(v[i] < v[i+1]) up = 1;
        if(v[i] > v[i+1]) down = 1;
    }
    return up & down;

}


vector<int> parity(vector<int>& v)
{
    int i = 0;
    for(int j = 0; j < v.size(); j++) {
        if(v[j] % 2 == 0) {
            swap(v[i],v[j]);
            i++;
        }
    }
    return v;
}



vector<int> disappearedNums(vector<int>& v)
{
    vector<int> ans;
    int n = v.size();
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
    int sum = 0, n = v.size();
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i += 2) sum += v[i];
    return sum;
}



int degree(vector<int>& v)
{
    map<int,int> idx,cnt;
    int len = v.size(), degree = 0;
    for(int i = 0; i < v.size(); i++) {
        if(!idx.count(v[i])) idx[v[i]] = i;
        if(++cnt[v[i]] == degree) len = min(len,i - idx[v[i]] + 1);
        if(cnt[v[i]] > degree) {
            degree = cnt[v[i]];
            len = i - idx[v[i]] + 1;
        }
    }
    return len;
}


vector<int> twoSum(vector<int>& v, int target)
{
    int n = v.size();
    sort(v.begin(),v.end());
    int left = 0, right = n-1, tmp;
    vector<int> res(2,0);

    while(left < right)
    {
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


int kDiff(vector<int>& v, int k)
{
    int n = v.size();
    sort(v.begin(), v.end());
    if(v.size() <= 1) return 0;
    int res = 0, j = 1;
    for(int i = 0; i < n-1; i++) {
        j = i+1;
        while(j < n) {
            if(v[j] >= v[i]+k) {
                if(v[i] == v[j]-k) res++;
                break;
            }
            j++;
        }
        while(v[i] == v[i+1]) i++;
    }
    return res;
}
*/

vector<int> intersection2(vector<int>& v1, vector<int>& v2)
{
    int n1 = v1.size(), n2 = v2.size();
    int temp;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int i = 0, j = 0;
    vector<int> ans;
    while(i < n1 && j < n2)
    {
        if(v1[i] == v2[j]) {
            ans.push_back(v1[i]);
            i++; j++;
        }
        else if(v1[i] > v2[j]) j++;
        else i++;
    }
    return ans;
}

int main()
{
    vector<int> v;
    int s; cout << "Size: "; cin >> s;
    int br;
    for(int i = 0; i < s; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> br;
        v.push_back(br);
    }
    /*cout << isNonDecr(v);
      cout << nRepeat(v);
      rotatee(v,3);
      for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
      cout << isMonotonic(v);

     cout << removee(v);

    vector<int> v1 = squares(v);
    for(int i = 0; i < v1.size(); i++) cout << v1[i] << " ";

    cout << peakIndex(v);

    cout << isMountain(v);

    vector<int> v2 = parity(v);
    for(int i = 0; i <v2.size(); i++) cout << v2[i] << " ";

    vector<int> v3 = disappearedNums(v);
    for(int i = 0; i < v3.size(); i++) cout << v3[i] << " ";
     cout << partition(v);
     cout << degree(v);

    vector<int> v3 = twoSum(v,9);
    for(int i = 0; i < v3.size(); i++) cout << v3[i] << " ";
*/
    vector<int>w;
    int wSize; cout << "Enter length of w: ";
    cin >> wSize;
    int wBr;
    for(int i = 0;i < wSize; i++) {
        cin >> wBr;
        w.push_back(wBr);
    }
    vector<int> inter = intersection2(v,w);
    for(int i = 0; i < inter.size(); i++) cout << inter[i] << " ";
}
