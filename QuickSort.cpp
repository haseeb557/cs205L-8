#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r )
{
    int pivot = arr[r];
    int i = l-1;
    for(int j = l; j<r; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
     swap(arr,i+1,r);
     return i+1;
}

void quicksort (int arr[], int l, int r)
{
    if(l<r)
    {
        int pi = partition(arr,l,r);          //pi pivot ka index hai. Pivot is the number where the partition happens
        quicksort(arr,l,pi-1);                //calling the function bec. its a recursive function 
        quicksort(arr,pi+1,r);
    }
}

int main()
{
    int n;
    cout<<"enter how many values in array\n";
    cin>>n;
    int arr[n];
     for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int N = sizeof(arr) / sizeof(int);
    
    quicksort (arr,0,N-1);
    for(int i=0; i<N; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}