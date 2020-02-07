#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
vector<vector<int> > transpose(vector<vector<int> >& v)
{
    if(v.empty()) return vector<vector<int> >();
    vector<vector<int> > res(v[0].size(),vector<int>());
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) {
            res[j].push_back(v[i][j]);
        }
    }
    return res;
}

vector<vector<int> > reshape(vector<vector<int> >&v, int r, int c)
{
    int x = v.size();
    int y = v[0].size();
    if(x*y != r*c) return v;
    vector<vector<int> > res(r,vector<int>(c));
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


bool isToeplitz(vector<vector<int> >&v)
{
    bool flag = true;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) {
            if(((i+1 < v.size()) && (j+1 < v[0].size())) && v[i][j] != v[i+1][j+1]) return false;
        }
    }
    return flag;
}
*/

int repeat(string s1,string s2)
{
    int n1 = s1.length(), n2 = s2.length(), cnt = 1;
    string t = s1;
    while(t.length() < n2)
    {
        t += s1;
        cnt++;
    }
    if(t.find(s2) != string::npos) return cnt;
    t += s1;
    return(t.find(s2) != string::npos) ? cnt+1 : -1;
}

int main()
{
    vector<vector<int> > v1;
    int row,col,n;
    cout << "Rows: "; cin >> row;
    cout << "Cols: "; cin >> col;
    for(int i = 0; i < row; i++) {
        v1.push_back(vector<int>());
        for(int j = 0; j < col; j++) {
            cout << "Enter number: ";
            cin >> n;
            v1[i].push_back(n);
        }
    }
    vector<vector<int> > v2 = transpose(v1);
    for(int i = 0; i < v2.size(); i++) {
        for(int j = 0; j < v2[i].size(); j++) cout << v2[i][j] << " ";
        cout << endl;
    }
}
