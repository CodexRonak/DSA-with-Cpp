#include <iostream>
using namespace std;
int main(){
    int n = 4;
    for (int i = 0; i < n; i++){
        // top-left
        for (int j = 0; j < i + 1; j++){
            cout << "*";
        }
        // top-mid
        for (int j = 0; j < 2 * (n - i) - 2; j++){
            cout << " ";
        }
        // top-right
        for (int j = 0; j < i + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++){
        // bottom-left
        for (int j = 0; j < n - i; j++){
            cout << "*";
        }
        // bottom-mid
        for (int j = 0; j < 2 * i; j++){
            cout << " ";
        }
        // bottom-right
        for (int j = 0; j < n - i; j++){
            cout << "*";
        }
        cout << endl;
    }
        return 0;
}