#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    if(s >= e){
        return pivot;
    }

    int count = 0;
    for (int i = s + 1 ; i <= e; i++){
        if(pivot > arr[i]){
            count++;
        }
    }

    int pivotIdx = s + count;
    swap(arr[s], arr[pivotIdx]);

    int i = s;
    int j = e;

    while(i < pivotIdx && pivotIdx < j){
        while(arr[i] < pivot){
            i++;
        }
        
        while(pivot < arr[j]){
            j--;
        }

        if(i < pivotIdx && pivotIdx < j){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIdx;
}

void quickSort(int arr[], int n, int s, int e){
    if(s >= e)
        return;

    int pivot = partition(arr, s, e);

    quickSort(arr, n, s, pivot - 1);
    quickSort(arr, n, pivot + 1, e);

}

int main(){
    int arr[] = {4, 6, 3, 9, 1};
    int n = 5;

    quickSort(arr, n, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}