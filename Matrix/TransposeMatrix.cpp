#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
const int b = 10;
void transpose(int arr[][b],int row,int column)
{
    for(int i = 0; i < row-1; i++) {
         for(int j = i+1; j < column; j++) swap(arr[i][j],arr[j][i]);
    }
    for(int i = 0; i < row; i++) {
            cout << "[";
        for(int j = 0; j < column; j++)
                cout << arr[i][j] << ",";
        cout << "]" << endl;
}
}
*/

vector<vector<int> > transpose(vector<vector<int> >& v)
{
    vector<vector<int> > res(v[0].size(),vector<int>());
    if(v.empty()) return vector<vector<int> >();
    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v[i].size(); j++) res[j].push_back(v[i][j]);
    return res;
}
int main()
{
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
