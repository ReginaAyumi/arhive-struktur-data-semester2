#include <iostream>
using namespace std;

void insertion(int arr[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {81, 56, 2, 12, 9, 32, 45, 26, 23, 66, 51, 87, 39, 29, 47, 7, 16, 92, 44, 21};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i, j;

    cout << "Program Insertion Sort" << endl;

    insertion(arr, n);
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}