#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxCount(int m, int n, vector<vector<int> >& v)
{
    for(int i = 0; i < v.size(); i++) {
        m = min(m, v[i][0]);
        n = min(n,v[i][1]);
    }
    return m*n;
}

int main()
{
    vector<vector<int> > vv;
    int row,col,n;
    cout << "Rows: "; cin >> row;
    cout << "Cols: "; cin >> col;
    for(int i = 0; i < row; i++) {
        vv.push_back(vector<int>());
        for(int j = 0; j < col; j++) {
            cin >> n;
            vv[i].push_back(n);
        }
    }
    cout << maxCount(3,3,vv);
}
