#include<iostream>
using namespace std;

int main(){

    int rows;
    cin >> rows;
    
    int cols;
    cin >> cols;

    // 2D array
    int **arr = new int*[rows];
    for (int i = 0; i < rows; i++){
        arr[i] = new int [cols];
    }
    cout << endl;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> arr[i][j];
        }
        cout << endl;
    }

    cout << endl;

    //print
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //memory release
    for (int i = 0; i < rows; i++){
        delete[] arr[i];
    }
    delete[] arr;
}