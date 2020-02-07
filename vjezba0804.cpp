#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;

int removeDuplicates(vector<int>& v)
{
    int n = v.size();
    int j = 0;
    for(int i = 0; i < n-1; i++) {
        if(v[i] != v[i+1]) v[j++] = v[i];
    }
    v[j++] = v[n-1];
    return j;
}

int missing(vector<int>& v)
{
    int n = v.size();
    return n*(n+1) / 2 - accumulate(v.begin(),v.end(),0);
}

vector<int> rotate(vector<int>& v, int k)
{
    int n = v.size();
    vector<int> vCopy(v);
    for(int i = 0; i < n; i++)
        v[(i+k)%n] = vCopy[i];
    return v;
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

int repeatedElement(vector<int>& v)
{
    int n = v.size();
    vector<int>::iterator it = v.begin();
    while(it != v.end())
    {
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

int partitionSum(vector<int>& v)
{
    int sum = 0, n = v.size();
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i += 2) sum += v[i];
    return sum;
}

vector<vector<int> > reshape(vector<vector<int> >& v, int r, int c)
{
    vector<vector<int> > res(r,vector<int>(c));
    int x = v.size();
    int y = v[0].size();
    if(x*y != r*c) return v;
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

vector<int> intersection2(vector<int>& v1, vector<int>& v2)
{
    vector<int> vec;
    int len1 = v1.size(), len2 = v2.size();
    int i = 0, j = 0;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    while(i < len1 && j < len2)
    {
        if(v1[i] == v2[j]) {
            vec.push_back(v1[i]);
            i++; j++;
        }
        else if(v1[i] > v2[j]) j++;
        else i++;
    }
    return vec;
}
int repeatedString(string a,string b)
{
    int len1 = a.length(), len2 = b.length(), cnt = 1;
    string t = a;
    while(t.length() < len2) {
        t += a;
        cnt++;
    }
    if(t.find(b) != string::npos) return cnt;
    t += a;
    return (t.find(b) != string::npos) ? cnt+1 : -1;
}

vector<int> intersection1(vector<int>& v1, vector<int>& v2)
{
    set<int> sett;
    int len1 = v1.size(), len2 = v2.size();
    vector<int> vec;
    for(int i = 0; i < len1; i++) sett.insert(v1[i]);
    for(int i = 0; i < len2; i++) {
        if(sett.count(v2[i])) {
            vec.push_back(v2[i]);
            sett.erase(v2[i]);
        }
    }
    return vec;
}

bool isMountain(vector<int>& v)
{
    int n = v.size();
    if(n < 3) return false;
    int up = 0, down = 0;
    for(int i = 0; i < n-1; i++) {
        if((!up && (v[i] >= v[i+1])) || (down && (v[i] <= v[i+1]))) return false;
        if(v[i] < v[i+1]) up = 1;
        if(v[i] > v[i+1]) down = 1;
    }
    return up & down;
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


int kDiff(vector<int>& v, int k)
{
    int n = v.size();
    int res = 0, j = 1;
    for(int i = 0; i < n-1; i++) {
            j = i+1;
        while(j < n) {
            if(v[j] >= v[i] + k) {
                if(v[i] == v[j] - k) {
                    res++; break;
                }
            }
            j++;
        }
        while(v[i] == v[i+1]) i++;
    }
    return res;
}
int degree(vector<int>& v)
{
    int n = v.size(), degree = 0;
    map<int,int> idx,cnt;
    for(int i = 0; i < v.size(); i++) {
        if(!idx.count(v[i])) idx[v[i]] = i;
        if(++cnt[v[i]] == degree) n = min(n, i - idx[v[i]] + 1);
        if(cnt[v[i]] > degree) {
            degree = cnt[v[i]];
            n = i - cnt[v[i]] + 1;
        }
    }
    return n;
}

inline bool chk(char a)
{
    return((a >= 'A') && (a <= 'Z')) || ((a >= 'a') && (a <= 'z')) || ((a >= '0') && (a <= '9'));
}
bool palindromeString(string s)
{
    int i = 0, j = s.length() - 1;
    while(i <= j) {
        while((i <= j) && (!chk(s[i]))) i++;
        while((j >= i) && (!chk(s[i]))) j--;
        if((i < j) && (s[i] != s[j]) && (s[i] != s[j] + 32) && (s[j] != s[i] + 32)) return false;
        i++; j--;
    }
    return true;
}

bool palindromeNumber(int n)
{
    int x = n;
    long int pali = 0;
    while(n != 0) {
        int last = n%10;
        pali = (pali*10) + last;
        n /= 10;
    }
    if(pali == x) return true;
    else return false;
}

vector<vector<int> > transpose(vector<vector<int> >& v)
{
    vector<vector<int> > res(v[0].size(),vector<int>());
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) res[j].push_back(v[i][j]);
    }
     return res;
}
int main()
{
/*
    vector<int> vv, v2;
    int s,n; cin >> s;
    for(int i = 0; i < s; i++) {
        cin >> n;
        vv.push_back(n);
    }
    int s2,n2; cin >> s2;
    for(int i = 0; i < s2; i++) {
        cin >> n2;
        v2.push_back(n2);
    }
    /*cout << removeDuplicates(vv);
    cout << missing(vv);

    vector<int> v2 = rotate(vv,3);
    for(int i = 0; i < v2.size(); i++) cout << v2[i] << " ";

    cout << peakIndex(vv);

   cout << repeatedElement(vv);

   squares(vv);
   for(int i = 0; i < vv.size(); i++) cout << vv[i] << " ";

   cout << partitionSum(vv);

  string ss,s2;
  getline(cin,ss); getline(cin,s2);
  cout << repeatedString(ss,s2);

    vector<int> v3 = intersection1(vv,v2);
    for(int i = 0; i < v3.size(); i++) cout << v3[i] << " ";
*/
vector<vector<int> > vv;
    int br;
    int row,col;
    cout << "Row(s): ";
    cin >> row;
    cout << "Col(s): ";
    cin >> col;
    for(int i = 0; i < row; i++) {
        vv.push_back(vector<int>());
        for(int j = 0; j < col; j++) {
            cout << "Enter number: ";
            cin >> br;
            vv[i].push_back(br);
        }
    }
    vector<vector<int> > v2 = transpose(vv);
    for(int i = 0; i < v2.size(); i++) {
        for(int j = 0; j < v2[i].size(); j++) cout << v2[i][j] << " ";
        cout << endl;
    }
}
