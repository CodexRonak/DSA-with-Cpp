#include<iostream>
using namespace std;


void mergeSort(int arr[], int arrIdx[], int temp[], int tempIdx[], int surpasser[], int s, int e){
    if(s>=e){
        return;
    }

    int m = s + (e - s) / 2;

    mergeSort(arr, arrIdx, temp, tempIdx, surpasser, s, m);
    mergeSort(arr, arrIdx, temp, tempIdx, surpasser, m + 1, e);


    int idx1 = 0;
    int idx2 = 0;
    int len1 = m - s + 1;
    int len2 = e - m;

    int mainIdx = s;

    while (idx1 < len1 && idx2 < len2){
        int i = s + idx1; // left subarray ka pointer
        int j = m + 1 + idx2; // right subarray ka pointer

        if(arr[i] < arr[j]){
            int origin = arrIdx[i];
            surpasser[origin] += (len2 - idx2);
            temp[mainIdx] = arr[i];
            tempIdx[mainIdx] = arrIdx[i];
            mainIdx++;
            idx1++;
        }
        else{
            temp[mainIdx] = arr[j];
            tempIdx[mainIdx] = arrIdx[j];
            mainIdx++;
            idx2++;
        }
    }

    while(idx1 < len1){
        int i = s + idx1;
        int origin = arrIdx[i];
        surpasser[origin] += (len2 - idx2);
        temp[mainIdx] = arr[i];
        tempIdx[mainIdx] = arrIdx[i];
        mainIdx++;
        idx1++;
    }

    while(idx2 < len2){
        int j = m + 1 + idx2;
        temp[mainIdx] = arr[j];
        tempIdx[mainIdx] = arrIdx[j];
        mainIdx++;
        idx2++;
    }

    for (int i = s; i <= e; i++){
        arr[i] = temp[i];
        arrIdx[i] = tempIdx[i];
    }
}

int main(){
    int n = 5;
    int arr[n] = {4, 3, 6, 2, 1};
    int arrIdx[n];
    int temp[n];
    int tempIdx[n];
    int surpasser[n] = {0};

    for (int i = 0; i < n; i++) {
        arrIdx[i] = i;
    }

    mergeSort(arr, arrIdx, temp, tempIdx, surpasser, 0, n - 1);
    // Print calculated surpasser values
    cout << "Surpasser counts: ";
    for (int i = 0; i < n; i++) {
        cout << surpasser[i] << " ";
    }
    cout << endl;
    return 0;
}