#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

bool isNonDecreasing(vector<int>& v)
{
    int n = v.size();
    bool flag = false;
    for(int i = 1; i < n; i++)
    {
        if(v[i] < v[i-1]) {
            if(!flag) {
                flag = true;
                if(v[i] != i+1 && v[i] != n-1 && v[i] < v[i-2] && v[i-1] > v[i+1]) return false;
            } else return false;
        }
    }
    return true;
}

vector<int> intersection(vector<int>& v1,vector<int>& v2)
{
    int len1 = v1.size();
    int len2 = v2.size();
    set<int> sett;
    vector<int> res;
    for(int i = 0; i < len1; i++) sett.insert(v1[i]);
    for(int i = 0; i < len2; i++) {
        if(sett.count(v2[i])) {
            res.push_back(v2[i]);
            sett.erase(v2[i]);
        }
    }
    return res;
}

void rotate(vector<int>& v, int k)
{
    int n = v.size();
    vector<int> vec(v);
    for(int i = 0; i < n; i++) v[(i+k)%n] = vec[i];
}

bool isMonotonic(vector<int>& v)
{
    int n = v.size();
    bool f1 = true,f2 = true;
    for(int i = 1; i < n; i++) {
        if(v[i] < v[i-1]) f2 = false;
        else if(v[i] > v[i-1]) f1 = false;
        if(!f1 && !f2) return false;
    }
    return true;
}

int repeatedElement(vector<int>& v)
{
    int n = v.size();
    vector<int>::iterator it = v.begin();
    while(it != v.end()) {
        if(count(v.begin(),v.end(),*it) > 1) break;
        else it++;
    }
    return *it;
}

void squares(vector<int>& v)
{
    for(int i = 0; i < v.size(); i++) v[i] = v[i]*v[i];
    sort(v.begin(),v.end());
}

int removeDuplicates(vector<int>& v)
{
    int n = v.size();
    sort(v.begin(),v.end());
    int j = 0;
    for(int i = 0; i < n-1; i++) {
        if(v[i] != v[i+1]) v[j++] = v[i];
    }
    v[j++] = v[n-1];
    return j;
}

int peakIndex(vector<int>& v)
{
    int n = v.size();
    if(n < 3) return -1;
    int begin = 0, end = n, middle = 0;
    while(begin < end) {
        middle = (begin+end)/2;
        if(v[middle] > v[middle+1]) end = middle;
        else begin = middle+1;
    }
    return end;
}

bool isMountain(vector<int>& v)
{
    int n = v.size();
    if(n < 3) return false;
    int up = 0, down = 0;
    for(int i = 0; i < n-1; i++) {
        if((!up && v[i] >= v[i+1]) || (down && v[i] <= v[i+1])) return false;
        if(v[i] < v[i+1]) up = 1;
        if(v[i] > v[i+1]) down = 1;
    }
    return up & down;
}

void parity(vector<int>& v)
{
    int n = v.size();
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] % 2 == 0) {
            swap(v[j],v[i]); j++;
        }
    }
}

vector<int> disappear(vector<int>& v)
{
    int n = v.size();
    vector<int> res;
    for(int i = 0; i < n; i++) {
        while(v[i] != i+1 && v[v[i]-1] != v[i]) swap(v[i],v[v[i]-1]);
    }
    for(int i = 0; i < n; i++) {
        if(v[i] != i+1) res.push_back(i+1);
    }
    return res;
}

int partition(vector<int>& v)
{
    sort(v.begin(),v.end());
    int sum = 0;
    for(int i = 0; i < v.size(); i += 2) sum += v[i];
        return sum;
}

int degree(vector<int>& v)
{
    int n = v.size();
    sort(v.begin(),v.end());
    map<int,int> idx,cnt;
    int degree = 0;
    for(int i = 0; i < v.size(); i++) {
        if(!idx.count(v[i])) idx[v[i]] = i;
        if(++cnt[v[i]] == degree) n = min(n,i - idx[v[i]] + 1);
        if(cnt[v[i]] > degree) {
            degree = cnt[v[i]];
            n = i - idx[v[i]] + 1;
        }
    }
    return n;
}

vector<int> twoSum(vector<int>& v, int k)
{
    int n = v.size(), left = 0, right = v.size()-1;
    int tmp;
    vector<int> res(2,0);
    while(left < right) {
        tmp = v[left] + v[right];
        if(tmp == k) {
            res[0] = left+1;
            res[1] = right+1;
            break;
        }
        else if(tmp > k) right--;
        else left++;
    }
    return res;
}

vector<int> intersection2(vector<int>& v1,vector<int>& v2)
{
    int len1 = v1.size(),len2 = v2.size();
    vector<int> res;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int i = 0, j = 0;
    while(i < len1 && j < len2)
    {
        if(v1[i] == v2[j]) {
            res.push_back(v1[i]);
            i++; j++;
        }
        else if(v1[i] > v2[j]) j++;
        else i++;
    }
    return res;
}

vector<vector<int> > transpose(vector<vector<int> >& v)
{
    if(v.empty()) return vector<vector<int> >();
    vector<vector<int> >res(v[0].size(),vector<int>());
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) res[j].push_back(v[i][j]);
    }
    return res;
}

vector<vector<int> > reshape(vector<vector<int> >& v,int r,int c)
{
    int x = v.size();
    int y = v[0].size();
    if(x*y != r*c) return v;
    vector<vector<int> >res(r,vector<int>(c));
    int i = 0, j = 0;
    for(int row = 0; row < x; row++) {
        for(int col = 0; col < y; col++) {
            res[i][j++] = v[row][col];
            if(j >= c) {
                i++; j = 0;
            }
        }
    }
    return res;
}

bool isToeplitz(vector<vector<int> >& v)
{
    bool flag = true;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size();j++) {
            if(((i+1 < v.size()) && (j+1 < v[0].size())) && (v[i][j] != v[i+1][j+1])) return false;
        }
    }
    return flag;
}

int repeatedString(string s1,string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    string t = s1;
    int cnt = 1;
    while(t.length() != len2) {
        t += s1;
        cnt++;
    }
    if(t.find(s2) != string::npos) return cnt;
    t += s1;
    return (t.find(s2) != string::npos) ? cnt+1 : -1;
}

vector<int> diString(string s)
{
    vector<int> res;
    int len = s.length();
    for(int i = 0, l = 0, h = s.length(); i <= len; i++) {
        res.push_back(i == len || s[i] == 'I' ? l++ : h--);
    }
    return res;
}

int rangeAddition(int m,int n,vector<vector<int> >& v)
{
    for(int i = 0; i < v.size(); i++) {
        m = min(m,v[i][0]);
        n = min(n,v[i][1]);
    }
    return m*n;
}

bool palindrome(int x)
{
    int n = x;
    long int pali = 0;
    while(n != 0) {
        int last = n%10;
        pali = (pali*10) + last;
        n /= 10;
    }
    if(x == pali) return true;
    else return false;
}
int main()
{/*
    vector<int> v,v1,vTest;
    int n,len1,len2;
    cin >> len1; cin >> len2;
    for(int i = 0; i < 4; i++) {
        cin >> n; v.push_back(n);
    }
    if(isNonDecreasing(v)) cout << "True.";
    else cout << "False.";

for(int i = 0; i < len1; i++) {
    cin >> n;
    v.push_back(n);
}
cout << "\n=========================\n";
for(int i = 0; i < len2; i++) {
    cin >> n;
    v1.push_back(n);
}/*
vTest = intersection(v,v1);
for(int i = 0; i < vTest.size(); i++) cout << vTest[i] << " ";

  rotate(v,2);
  for(int i = 0; i < v.size(); i++) cout << v[i] << " ";

   if(isMonotonic(v)) cout << "True"; else cout << "False";

  cout << repeatedElement(v) << endl;

  squares(v);
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";

   cout << removeDuplicates(v) << endl;

   cout << peakIndex(v) << endl;

   if(isMountain(v)) cout << "True"; else cout << "False";
   parity(v);
        for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
            vTest = disappear(v);
        for(int i = 0; i < vTest.size(); i++) cout << vTest[i] << " ";
            cout << partition(v);
            cout << degree(v);
       vTest = twoSum(v,9);
        for(int i = 0; i < vTest.size(); i++) cout << vTest[i] << " ";
            vTest = intersection2(v,v1);
        for(int i = 0; i < vTest.size(); i++) cout << vTest[i] << " ";

    vector<vector<int> > vv,vv1;
    int row,col;
    cout << "Row: "; cin>> row; cout << "Column: "; cin >> col;
    int n;
    for(int i = 0; i < row; i++) {
            vv.push_back(vector<int>());
        for(int j = 0; j < col; j++) {
            cin >> n;
            vv[i].push_back(n);
        }
    }/*
    vv1 = transpose(vv);
    for(int i = 0; i < vv1.size(); i++) {
        for(int j = 0; j < vv1[0].size(); j++) cout << vv1[i][j] << " ";
    cout << endl;
    }
      vv1 = reshape(vv,2,4);
    for(int i = 0; i < vv1.size(); i++) {
        for(int j = 0; j < vv1[0].size(); j++) cout << vv1[i][j] << " ";
    cout << endl;
    }
    if(isToeplitz(vv)) cout << "True"; else cout << "False";*/
        string s1,s2;
    getline(cin,s1); getline(cin,s2);
    cout << repeatedString(s1,s2);
}
