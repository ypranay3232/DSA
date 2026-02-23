// optimised sol using Hoare partition where we select mid as pivot. 
#include<iostream>
using namespace std;

int partition(int arr[],int low, int high){
    // choose middle element as pivot.
    int pivot = arr[low + (high - low)/2]; 

    int i = low -1;
    int j = high +1;

    // now place the elements in order
    while(true){
        // move i until its >= pivot
        do{
            i++;
        }while(arr[i]<pivot);

        // now move j until its <= pivot
        do{
            j--;
        }while(arr[j]>pivot);

        // stopping case : if i cross j stop
        if(i >=j){
            return j;
        }

        // swap misplaced elements : 
        swap(arr[i],arr[j]);
    }
}

void quicksort(int arr[], int low, int high)
{
    while (low < high)
    {
        int p = partition(arr, low, high);

        if (p - low < high - p)
        {
            quicksort(arr, low, p);
            low = p + 1;
        }
        else
        {
            quicksort(arr, p + 1, high);
            high = p;
        }
    }
}
int main(){
    int arr[] = {8, 1, 3, 4, 20, 80, 95};
    int n = 7;

    quicksort(arr,0, n-1);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}