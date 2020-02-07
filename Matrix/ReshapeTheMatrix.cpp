#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > reshape(vector<vector<int> >& v, int r, int c)
{
    int x = v.size();
    int y = v[0].size();
    if(x*y != r*c) return v;
    vector<vector<int> > result(r,vector<int>(c));
    int i = 0, j = 0;
    for(int row = 0; row < x; row++) {
        for(int col = 0; col < y; col++) {
            result[i][j++] = v[row][col];
            if(j >= c) {
                i++;
                j = 0;
            }
        }
    }
    return result;
}

int main()
{
    cout << "Row number: ";
    int row,col;
    cin >> row;
    cout << "Column number: ";
    cin >> col;
    vector<vector<int> > vect;
    int br;
    for(int i = 0; i < row; i++) {
            vect.push_back(vector<int>());
        for(int j = 0; j < col; j++) {
         cout << "Enter number: ";
          cin >> br;
          vect[i].push_back(br);
        }
    }
    int row2,col2;
    cout << "Now enter the num of rows you want: ";
    cin >> row2;
    cout << "And columns: ";
    cin >> col2;
    vector<vector<int> > v2 = reshape(vect,row2,col2);
    for(int i = 0; i < row2; i++) {
        for(int j = 0; j < col2; j++) cout << v2[i][j] << " ";
        cout << endl;
    }

}

