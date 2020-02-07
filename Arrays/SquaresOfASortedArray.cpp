#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

void sortedSquares(int arr[], int size)
{
    int a[size];
    for(int i = 0; i < size; i++) arr[i] = arr[i] * arr[i];
    for(int i = 1; i < size; i++)
    {
        for(int j = 0; j < size - i; j++) {
            if(arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
    for(int i = 0; i < size; i++) a[i] = arr[i];

}

int main()
{
    int sajz;
    cin >> sajz;
    int ar[sajz];
    for(int i = 0; i < sajz; i++) cin >> ar[i];
    sortedSquares(ar,sajz);
    for(int i = 0; i < sajz; i++) cout << ar[i] << ", ";
    return 0;
}
