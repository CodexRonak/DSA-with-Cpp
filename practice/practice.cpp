#include <iostream>
using namespace std;
int main(){
    int n = 4;
    // top
    for (int i = 0; i < n; i++){
        // space
        for (int j = 0; j < n-i-1; j++){
            cout<<" ";
        }

        // stars
        cout << "*";

        // sapce
        if (i!= 0){
            for (int j = 0; j < 2 * i - 1; j++){
                cout << " ";
            }
            cout << "*";
        }
            cout << endl;
    }

    // bottom
    for (int i = 0; i < n - 1; i++){
        // space
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }
        // stars
        cout << "*";

        if(i!=n-2){

            for (int j = 0; j < 2*(n - i) - 5; j++)
            {
                cout << " ";
            }
            cout << "*";
        }

        cout << endl;
    }
        return 0;
}
