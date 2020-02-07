#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
vector<vector<int> > transpose(vector<vector<int> >& v)
{
    if(v.empty()) return vector<vector<int> >();
    vector<vector<int> > res(v[0].size(), vector<int>());
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) {
            res[j].push_back(v[i][j]);
        }
    }
    return res;
}


vector<vector<int> > reshape(vector<vector<int> >& v, int r, int c)
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


int repeat(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length(), cnt = 1;
    string t = s1;
    while(t.length() < n2) {
        t += s1; cnt++;
    }
    if(t.find(s2) != string::npos) return cnt;
    t += s1;
    return(t.find(s2) != string::npos) ? cnt+1 : -1;
}
*/

vector<int> diString(string s)
{
    vector<int> res;
    for(int i = 0, l = 0, h = s.length(); i <= s.length(); i++) {
        res.push_back(i == s.length() || s[i] == 'I' ? l++ : h--);
    }
    return res;
}
int main()
{
    /*
    vector<vector<int> > vv,v1;
    int row,col,n;
    cout << "Rows: "; cin >> row;
    cout << "Columns: "; cin >> col;
    for(int i = 0; i < row; i++) {
        vv.push_back(vector<int>());
        for(int j = 0; j < col; j++) {
            cin >> n;
            vv[i].push_back(n);
        }
    }
    cout << isToeplitz(vv);
    //v1 = transpose(vv);
   // v1 = reshape(vv,2,4);
    /*for(int i = 0; i < v1.size(); i++) {
        for(int j = 0; j < v1[i].size(); j++) cout << v1[i][j] << " ";
        cout << endl;
    }
    string a,b;
    getline(cin,a); getline(cin,b);
    cout << repeat(a,b);
   */
    string c;
    getline(cin,c);
    vector<int> w = diString(c);
    for(int i = 0; i < w.size(); i++) cout << w[i] << " ";
    return 0;
}
