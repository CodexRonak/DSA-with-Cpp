#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int k){
    if(arr[0] == k){
        return true;
    }
    if (n == 0){
        return false;
    }
    else{
        return linearSearch(arr + 1, n - 1, k);
    }
}

int main(){
    int arr[] = {12, 3, 2, 40, 15, 6, 77, 65};
    int k = 22;
    int n = 8;

    if(linearSearch(arr, n, k)){
        cout << "present" << endl;
    }
    else{
        cout << "not present" << endl;
    }

    return 0;
}