#include <iostream>
#include <utility>
using namespace std;

int climbStairs(int n)
{
    int arr[2];
    arr[0] = 1; arr[1] = 2;
    if(n <= 2) return n;
    int front = 0, back = 1;
    for(int i = 0; i < n-2; i++)
    {
        int r = arr[0]+arr[1];
        arr[front] = r;
        swap(front,back);
    }
    if(n % 2 == 0) return arr[1];
    else return arr[0];
}

int main()
{
    cout << climbStairs(3);
}
