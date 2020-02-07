#include <iostream>
using namespace std;

int removeDuplicates(int arr[],int size)
{
    if(size == 0 || size == 1) return size;

    int j = 0;

    for(int i = 0; i < size - 1; i++)
    {
         if(arr[i] != arr[i+1]) arr[j++] = arr[i];
    }
    arr[j++] = arr[size - 1];

    return j;
}

int main()
{
    int sajz;
    cout << "Enter the length: ";
    cin >> sajz;
    int a[sajz];
    for(int i = 0; i < sajz; i++) cin >> a[i];
    cout << removeDuplicates(a,sajz) << " is the size\n";
}
