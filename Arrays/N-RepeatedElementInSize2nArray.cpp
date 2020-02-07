#include <iostream>
using namespace std;

int findNumber(int arr[],int size)
{
    int cnt = 0;
    int temp = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++) {
            if(arr[i] == arr[j]) cnt++;
            temp = arr[j];
        }
    }


}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the " << i+1 << ". number: ";
        cin >> a[i];
    }
    cout << findNumber(a,n);
}
