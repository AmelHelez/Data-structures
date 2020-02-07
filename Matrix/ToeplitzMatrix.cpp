#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isToeplitz(vector<vector<int> >& v)
{
    bool flag = true;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) {
            if(((i+1 < v.size()) && (j+1 < v[0].size())) && v[i][j] != v[i+1][j+1]) return false;
        }
    }
    return flag;
}

int main()
{
    vector<vector<int> > vv;
    int row,col;
    cout << "Rows: "; cin >> row;
    cout << "Cols: "; cin >> col;
    int br;
    for(int i = 0; i < row; i++) {
            vv.push_back(vector<int>());
        for(int j = 0; j < col; j++) {
         cout << "Enter number: ";
          cin >> br;
          vv[i].push_back(br);
        }
    }
    cout << isToeplitz(vv);
}
