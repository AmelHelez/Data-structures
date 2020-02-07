#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <numeric>
using namespace std;
/*
vector<vector<int> > transpose(vector<vector<int> >&v)
{
    if(v.empty()) return vector<vector<int> >();
    vector<vector<int> > res(v[0].size(), vector<int>());
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) res[j].push_back(v[i][j]);
    }
    return res;
}


vector<vector<int> > traverse(vector<vector<int> >& v, int r, int c)
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

int degree(vector<int>& v)
{
    map<int,int> idx,cnt;
    int degree = 0, len = v.size();
    for(int i = 0; i < v.size(); i++) {
        if(!idx.count(v[i]])) idx[v[i]] = i;
        if(++cnt[v[i]] == degree) len = min(len, i - idx[v[i]] + 1);
        if(cnt[v[i]] > degree) {
            degree = cnt[v[i]];
            len = i - idx[v[i]] + 1;
        }
    }
    return len;
}
int main()
{
    vector<vector<int> > vv;
    int row,col;
    cout << "Rows: "; cin >> row;
    cout << "Cols: "; cin >> col;
    int n;
    for(int i = 0 ; i < row; i++) {
            vv.push_back(vector<int>());
        for(int j = 0; j < col; j++) {
            cin >> n;
            vv[i].push_back(n);
        }
    }
    vector<vector<int> > v2 = traverse(vv,1,4);
    for(int i = 0; i < v2.size(); i++)
        for(int j = 0; j < v2[i].size(); j++) cout << v2[i][j] << " ";
     cout << endl;
}
